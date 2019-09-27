// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PositionArrayTraveler.h"
#include "PingPongPAT.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API UPingPongPAT : public UPositionArrayTraveler {
	GENERATED_BODY()

   private:
	bool IsForWard = true;
	int32 CurrentIndex = 0;
	int32 Size = 0;

   protected:
	virtual int32 GetNextIndex() override;
	virtual void UpdateArraySize(int32 Size) override;
};
