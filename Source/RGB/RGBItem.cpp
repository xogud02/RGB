// Fill out your copyright notice in the Description page of Project Settings.


#include "RGBItem.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "RGBCharacter.h"

ARGBItem::ARGBItem() {
	PrimaryActorTick.bCanEverTick = true;
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/mesh/SM_Octahedron.SM_Octahedron'")).Object;
	GetStaticMeshComponent()->SetStaticMesh(Mesh);

	auto Material = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("Material'/Game/material/Glass/Glass.Glass'")).Object;
	GetStaticMeshComponent()->SetMaterial(0, Material);
	GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);

	OnActorBeginOverlap.AddDynamic(this, &ARGBItem::OnOverlap);
}

void ARGBItem::BeginPlay() {
	Super::BeginPlay();

	Color = ConvertToEnum(GetStaticMeshComponent()->GetMaterial(0)->GetName());
	auto Character = Cast<ARGBCharacter>(GetWorld()->GetPawnIterator()->Get());
	Character->AddCharacterColorObserver(this);
	UpdateColor(Character->GetBodyColor());;
}

void ARGBItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, 90 * DeltaTime, 0));
}

void ARGBItem::OnOverlap(AActor* OverlappedActor, AActor* OtherActor){
	auto Character = Cast<ARGBCharacter>(OtherActor);
	Character->SetBodyColor(Color);
}

void ARGBItem::UpdateColor(EColor NewColor){
	if (NewColor != Color) {
		GetStaticMeshComponent()->SetCollisionProfileName("OverlapOnlyPawn");
		return;
	}

	if (NewColor == Color) {
		GetStaticMeshComponent()->SetCollisionProfileName("NoCollision");
		return;
	}
}

