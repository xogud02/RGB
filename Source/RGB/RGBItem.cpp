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


	GetStaticMeshComponent()->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);

	OnActorBeginOverlap.AddDynamic(this, &ARGBItem::OnOverlap);
}

void ARGBItem::BeginPlay() {
	Super::BeginPlay();
	
	auto Material = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), this, TEXT("Material'/Game/material/Glass.Glass'")));
	GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamicFromMaterial(0, Material)->SetVectorParameterValue(TEXT("BasicColor"), ConvertToColor(Color));
}

void ARGBItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, 90 * DeltaTime, 0));
}

void ARGBItem::OnOverlap(AActor* OverlappedActor, AActor* OtherActor){
	auto Character = Cast<ARGBCharacter>(OtherActor);
	if (Character->GetBodyColor() == Color) {
		return;
	}
	Character->SetBodyColor(Color);
}

