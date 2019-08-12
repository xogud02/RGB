// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RGB.h"
#include "Engine/StaticMeshActor.h"
#include "RGBBarrier.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API ARGBBarrier : public AStaticMeshActor
{
	GENERATED_BODY()
	
private:
	EColor Color = EColor::WHITE;
	
public:
	ARGBBarrier();

protected:
	virtual void BeginPlay() override;

private:
	void OnCharacterColorChange(EColor NewColor);
};
