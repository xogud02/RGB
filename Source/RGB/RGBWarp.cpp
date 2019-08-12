// Fill out your copyright notice in the Description page of Project Settings.


#include "RGBWarp.h"
#include "Components/StaticMeshComponent.h"
#include "RGBCharacter.h"
#include "ConstructorHelpers.h"
#include "Components/ArrowComponent.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GameFramework/PlayerController.h"

ARGBWarp::ARGBWarp(){
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

void ARGBWarp::BeginPlay(){
	Super::BeginPlay();
	Color = ConvertToEnum(GetStaticMeshComponent()->GetMaterial(0)->GetName());
	InitialDirection = GetActorRotation();
}

void ARGBWarp::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0, DeltaTime * 30, 0));
}

void ARGBWarp::OnOverlap(AActor* OverlappedActor, AActor* OtherActor){
	auto Character = Cast<ARGBCharacter>(OtherActor);
	if (Character->GetBodyColor() != Color) {
		return;
	}

	if (!Destination) {
		return;
	}

	if (Warped) {
		Warped = false;
		return;
	}

	Destination->Warped = true;
	auto YawScale = Cast<APlayerController>(Character->GetController())->InputYawScale;
	Character->SetActorLocationAndRotation(Destination->GetActorLocation(), Destination->InitialDirection);
	auto Scale = (- Character->GetControlRotation().Yaw + Destination->InitialDirection.Yaw) / YawScale;
	Character->AddControllerYawInput(Scale);
}