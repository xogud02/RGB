// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RGB.h"
#include "UObject/NoExportTypes.h"
#include "PositionArrayTraveler.generated.h"

/**
 * 
 */

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class RGB_API UPositionArrayTraveler : public UObject {
	GENERATED_BODY()

   private:
	TArray<FVector> Positions;

   protected:
	virtual int GetNextIndex() PURE_VIRTUAL(UPositionArrayTraveler::GetNextIndex, return 0;);
	virtual void UpdateArraySize(int Size) PURE_VIRTUAL(UPositionArrayTraveler::UpdateArraySize, return;);

   public:
	FVector GetNextPosition();
	void SetPositions(TArray<FVector> RelativePositions, FVector InitialPosition);
};
