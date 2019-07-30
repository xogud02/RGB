// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RGBCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API URGBCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	URGBCharacterAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
	bool bInAir = false;
};
