// Fill out your copyright notice in the Description page of Project Settings.

#include "RGBObjectMover.h"
#include "GameFramework/Actor.h"

URGBObjectMover::URGBObjectMover() {
	PrimaryComponentTick.bCanEverTick = true;
}

void URGBObjectMover::BeginPlay() {
	Super::BeginPlay();
	GetOwner()->PrimaryActorTick.bCanEverTick = true;
}

void URGBObjectMover::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (Positions.Num() == 0) {
		SIMPLE_LOG("array empty");
		return;
	}
	if (IsPaused) {
		if (PauseCount <= 0) {
			IsPaused = false;
		} else {
			PauseCount -= DeltaTime;
		}
	} else {
		auto Location = GetOwner()->GetActorLocation();
		if (Location == Positions[TargetIndex]) {
			IsPaused = true;
			PauseCount = PauseLength;

			const bool IsForWardEnd = IsForward && TargetIndex == Positions.Num() - 1;
			const bool IsBackWardEnd = !IsForward && TargetIndex == 0;
			if (IsForWardEnd || IsBackWardEnd) {
				IsForward = !IsForward;
			}

			TargetIndex += IsForward ? 1 : -1;

		} else {
			auto NewLocation = FMath::VInterpConstantTo(Location, Positions[TargetIndex], DeltaTime, Speed);
			
			GetOwner()->SetActorLocation(NewLocation);
		}
	}
}
