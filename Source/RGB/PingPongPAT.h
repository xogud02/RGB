// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PositionArrayTraveler.h"
#include "PingPongPAT.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API UPingPongPAT : public UPositionArrayTraveler {
	GENERATED_BODY()

   protected:
	virtual TArray<int32> CreateIndexes(int32 Size) override;
};
