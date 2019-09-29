// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PositionArrayTraveler.h"
#include "RotationPAT.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API URotationPAT : public UPositionArrayTraveler {
	GENERATED_BODY()

   protected:
	virtual TArray<int32> CreateIndexes(int32 Size) override;
};
