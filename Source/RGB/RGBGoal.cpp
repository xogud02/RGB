// Fill out your copyright notice in the Description page of Project Settings.


#include "RGBGoal.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "RGBCharacter.h"
#include "Kismet/GameplayStatics.h"

ARGBGoal::ARGBGoal() {
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/mesh/SM_Goal.SM_Goal'")).Object;
	GetStaticMeshComponent()->SetStaticMesh(Mesh);

	auto Material = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("MaterialInstanceConstant'/Game/material/Plane/Plane_R.Plane_R'")).Object;
	GetStaticMeshComponent()->SetMaterial(0, Material);

	OnActorBeginOverlap.AddDynamic(this, &ARGBGoal::OnOverlap);
	GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
	GetStaticMeshComponent()->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
}

void ARGBGoal::Tick(float DeltaTime){
	AddActorWorldRotation(FRotator(0, DeltaTime * 90, 0));

}

void ARGBGoal::OnOverlap(AActor* OverlappedActor, AActor* OtherActor){
	auto Character = Cast<ARGBCharacter>(OtherActor);

	if (!Character) {
		return;
	}

	UGameplayStatics::OpenLevel(GetWorld(), *NextLevel);
}
