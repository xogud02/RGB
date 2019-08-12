// Fill out your copyright notice in the Description page of Project Settings.


#include "RGBBarrier.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstance.h"
#include "RGBCharacter.h"
#include "GameFramework/GameMode.h"

ARGBBarrier::ARGBBarrier() {
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/mesh/SM_Cube.SM_Cube'")).Object;
	GetStaticMeshComponent()->SetStaticMesh(Mesh);

	auto Material = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("Material'/Game/material/Glow/Glow.Glow'")).Object;
	GetStaticMeshComponent()->SetMaterial(0, Material);
}

void ARGBBarrier::BeginPlay(){
	Super::BeginPlay();

	Color = ConvertToEnum(GetStaticMeshComponent()->GetMaterial(0)->GetName());
	
	auto Character = Cast<ARGBCharacter>(GetWorld()->GetPawnIterator()->Get());
	Character->OnColorChange.AddUObject(this, &ARGBBarrier::OnCharacterColorChange);
	OnCharacterColorChange(Character->GetBodyColor());
}

void ARGBBarrier::OnCharacterColorChange(EColor NewColor){
	if (NewColor != Color) {
		GetStaticMeshComponent()->SetCollisionProfileName("BlockAll");
		return;
	}

	if (NewColor == Color) {
		GetStaticMeshComponent()->SetCollisionProfileName("NoCollision");
		return;
	}

}
