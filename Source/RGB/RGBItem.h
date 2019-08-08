// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RGB.h"
#include "Engine/StaticMeshActor.h"
#include "RGBItem.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API ARGBItem : public AStaticMeshActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	EColor Color = EColor::WHITE;
	
public:
	ARGBItem();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	UFUNCTION()
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
