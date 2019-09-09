// Fill out your copyright notice in the Description page of Project Settings.

#include "RGBObjectMover.h"
#include "GameFramework/Actor.h"
#include "Transform.h"

URGBObjectMover::URGBObjectMover() {
	PrimaryComponentTick.bCanEverTick = true;
}

void URGBObjectMover::BeginPlay() {
	Super::BeginPlay();
	GetOwner()->PrimaryActorTick.bCanEverTick = true;

	const auto InitialPosition = GetOwner()->GetActorLocation();
	GetOwner()->GetRootComponent()->SetMobility(EComponentMobility::Movable);

	Positions.SetNum(RelativePositions.Num());

	for (int i = 0; i < RelativePositions.Num(); i++) {
		Positions[i] = InitialPosition + RelativePositions[i];
	}
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
		return;
	}

	auto Location = GetOwner()->GetActorLocation();
	const bool IsArrived = Location == Positions[TargetIndex];
	if (IsArrived) {
		IsPaused = true;
		PauseCount = PauseLength;

		if (IsPingpong) {
			const bool IsForWardEnd = IsForward && TargetIndex == Positions.Num() - 1;
			const bool IsBackWardEnd = !IsForward && TargetIndex == 0;
			if (IsForWardEnd || IsBackWardEnd) {
				IsForward = !IsForward;
			}

			TargetIndex += IsForward ? 1 : -1;
		} else {
			TargetIndex++;
			TargetIndex %= Positions.Num();
		}

	} else {
		auto NewLocation = FMath::VInterpConstantTo(Location, Positions[TargetIndex], DeltaTime, Speed);

		GetOwner()->SetActorLocation(NewLocation);
	}
}
