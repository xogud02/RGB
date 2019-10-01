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
		GetStaticMeshComponent()->SetCollisionProfileName("NoCollision");
		return;
	}

	auto Character = Cast<ARGBCharacter>(GetWorld()->GetPawnIterator()->Get());
	Character->AddCharacterColorObserver(this);
	UpdateColor(Character->GetBodyColor());
}

void ARGBWarp::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0, DeltaTime * CurrentRoatateSpeed, 0));
}

void ARGBWarp::OnOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	auto Character = Cast<ARGBCharacter>(OtherActor);

	if (Warped) {
		return;
	}

	Destination->Warped = true;
	Character->WarpTo(Destination->GetActorLocation(), Destination->InitialDirection);
	Destination->Warped = false;
}

void ARGBWarp::UpdateColor(EColor NewColor){
	ActivateWarp(NewColor == Color);
}

void ARGBWarp::ActivateWarp(bool Activate){
	if(Activate){
		GetStaticMeshComponent()->SetCollisionProfileName("OverlapOnlyPawn");
		CurrentRoatateSpeed = RotateSpeed;
	}else{
		GetStaticMeshComponent()->SetCollisionProfileName("NoCollision");
		CurrentRoatateSpeed = 0;
	}
}
