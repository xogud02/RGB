// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RGB.h"
#include "Engine/StaticMeshActor.h"
#include "CharacterColorObserver.h"
#include "RGBBarrier.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API ARGBBarrier : public AStaticMeshActor, public ICharacterColorObserver{
	GENERATED_BODY()

   private:
	EColor Color = EColor::WHITE;

   public:
	ARGBBarrier();
	virtual void UpdateColor(EColor NewColor) override;

   protected:
	virtual void BeginPlay() override;
};
