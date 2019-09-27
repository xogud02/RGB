// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PositionArrayTraveler.h"
#include "Queue.h"
#include "RandomPAT.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API URandomPAT : public UPositionArrayTraveler {
	GENERATED_BODY()

   private:
	TQueue<int32> IndexQueue;

   protected:
	virtual int32 GetNextIndex() override;
	virtual void UpdateArraySize(int32 Size) override;
};
