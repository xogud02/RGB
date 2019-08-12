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

	auto Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ARROW"));
	Arrow->SetupAttachment(GetRootComponent());

	OnActorBeginOverlap.AddDynamic(this, &ARGBWarp::OnOverlap);
	GetStaticMeshComponent()->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
}

void ARGBWarp::BeginPlay(){
	Super::BeginPlay();
	auto Material = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(),this,TEXT("Material'/Game/material/Glow.Glow'")));
	InitialDirection = GetActorRotation();
	GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamicFromMaterial(0, Material)->SetVectorParameterValue("BasicColor", ConvertToColor(Color));
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

	auto YawScale = Cast<APlayerController>(Character->GetController())->InputYawScale;
	Character->SetActorLocationAndRotation(Destination->GetActorLocation(), Destination->InitialDirection);
	auto Scale = (- Character->GetControlRotation().Yaw + Destination->InitialDirection.Yaw) / YawScale;
	Character->AddControllerYawInput(Scale);
}
