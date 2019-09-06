// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "RGB.h"
#include "RGBObjectMover.generated.h"

UCLASS(ClassGroup = (Common, Movement), meta = (BlueprintSpawnableComponent))
class RGB_API URGBObjectMover : public UActorComponent {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FVector> RelativePositions;

	TArray<FVector> Positions;

	UPROPERTY(EditAnywhere)
	float PauseLength = 1.5;

	float PauseCount;

	int TargetIndex;

	UPROPERTY(EditAnywhere)
	float Speed = 300;

	UPROPERTY(VisibleAnywhere)
	bool IsForward = true;

	UPROPERTY(VisibleAnywhere)
	bool IsPaused = true;

   public:
	virtual void BeginPlay() override;
	URGBObjectMover();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
