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

   private:
	int32 CurrentIndex = 0;
	int32 Size = 0;

   protected:
	virtual int32 GetNextIndex();
	virtual void UpdateArraySize(int32 Size) override;
};
