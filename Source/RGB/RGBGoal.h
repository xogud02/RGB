// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "RGBGoal.generated.h"

/**
 * 
 */
UCLASS()
class RGB_API ARGBGoal : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	ARGBGoal();

protected:
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere)
	FString NextLevel;
};
