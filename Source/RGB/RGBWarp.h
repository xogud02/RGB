// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RGB.h"
#include "CharacterColorObserver.h"
#include "Engine/StaticMeshActor.h"
#include "RGBWarp.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API ARGBWarp : public AStaticMeshActor, public ICharacterColorObserver
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditAnywhere)
	ARGBWarp* Destination;

	bool Warped = false;

	EColor Color = EColor::WHITE;

	const float RotateSpeed = 30;
	float CurrentRoatateSpeed = 0;

	FRotator InitialDirection;

public:
	ARGBWarp();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);
	virtual void UpdateColor(EColor NewColor) override;
	void ActivateWarp(bool Activate);
};
