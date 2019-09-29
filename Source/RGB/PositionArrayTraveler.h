// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RGB.h"
#include "UObject/NoExportTypes.h"
#include "Queue.h"
#include "Array.h"
#include "PositionArrayTraveler.generated.h"

/**
 * 
 */

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class RGB_API UPositionArrayTraveler : public UObject {
	GENERATED_BODY()

   private:
	TArray<FVector> Positions;
	TQueue<int32> IndexQueue;

   protected:
	virtual TArray<int32> CreateIndexes(int32 Size) PURE_VIRTUAL(UPositionArrayTraveler::CreateIndexes, return TArray<int32>(); );

   public:
	FVector GetNextPosition();
	void SetPositions(TArray<FVector> RelativePositions, FVector InitialPosition);
};
