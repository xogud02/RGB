// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "RGB.h"
#include "PositionArrayTraveler.h"
#include "RGBObjectMover.generated.h"

UCLASS(ClassGroup = (Common, Movement), meta = (BlueprintSpawnableComponent))
class RGB_API URGBObjectMover : public UActorComponent {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FVector> RelativePositions;
	UPROPERTY(EditAnywhere)
	float PauseLength = 1.5;

	float PauseCount;

	FVector TargetPosition;

	UPROPERTY(EditAnywhere)
	float Speed = 300;

	UPROPERTY(VisibleAnywhere)
	bool IsPaused = true;

	UPROPERTY(EditAnywhere, NoClear)
	UPositionArrayTraveler* PositionArrayTraveler;

   public:
	virtual void BeginPlay() override;
	URGBObjectMover();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
