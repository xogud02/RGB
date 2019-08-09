// Fill out your copyright notice in the Description page of Project Settings.


#include "RGBBarrier.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "RGBCharacter.h"
#include "GameFramework/GameMode.h"

ARGBBarrier::ARGBBarrier() {
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/mesh/SM_Cube.SM_Cube'")).Object;
	GetStaticMeshComponent()->SetStaticMesh(Mesh);

}

void ARGBBarrier::BeginPlay(){
	Super::BeginPlay();

	auto Material = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), this, TEXT("Material'/Game/material/Glow.Glow'")));
	GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamicFromMaterial(0, Material)->SetVectorParameterValue(TEXT("BasicColor"), ConvertToColor(Color));

	AGameMode* foo;
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
