// Fill out your copyright notice in the Description page of Project Settings.

#include "RGBWarp.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "RGBCharacter.h"

ARGBWarp::ARGBWarp() {
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/mesh/SM_Warp.SM_Warp'")).Object;
	GetStaticMeshComponent()->SetStaticMesh(Mesh);

	auto Material = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("MaterialInstanceConstant'/Game/material/Glow/GlowSlow.GlowSlow'")).Object;
	GetStaticMeshComponent()->SetMaterial(0, Material);

	auto Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ARROW"));
	Arrow->SetupAttachment(GetRootComponent());

	OnActorBeginOverlap.AddDynamic(this, &ARGBWarp::OnOverlap);
	GetStaticMeshComponent()->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
}

void ARGBWarp::BeginPlay() {
	Super::BeginPlay();
	Color = ConvertToEnum(GetStaticMeshComponent()->GetMaterial(0)->GetName());
	InitialDirection = GetActorRotation();
	if(!Destination){
		GetRootComponent()->SetVisibility(false);
	}
}

void ARGBWarp::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0, DeltaTime * 30, 0));
}

void ARGBWarp::OnOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	auto Character = Cast<ARGBCharacter>(OtherActor);

	if (Warped) {
		Warped = false;
		return;
	}

	if (Character->GetBodyColor() != Color) {
		return;
	}

	if (!Destination) {
		return;
	}

	Destination->Warped = true;
	Character->WarpTo(Destination->GetActorLocation(), Destination->InitialDirection);
}
