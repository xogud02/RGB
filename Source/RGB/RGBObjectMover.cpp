// Fill out your copyright notice in the Description page of Project Settings.

#include "RGBObjectMover.h"
#include "GameFramework/Actor.h"
#include "PingPongPAT.h"
#include "Transform.h"

URGBObjectMover::URGBObjectMover() {
	PrimaryComponentTick.bCanEverTick = true;
}

void URGBObjectMover::BeginPlay() {
	Super::BeginPlay();
	GetOwner()->PrimaryActorTick.bCanEverTick = true;

	GetOwner()->GetRootComponent()->SetMobility(EComponentMobility::Movable);

	if(!PositionArrayTraveler){
		PositionArrayTraveler = NewObject<UPingPongPAT>();
	}
	
	const auto InitialPosition = GetOwner()->GetActorLocation();
	TargetPosition = InitialPosition;
	PositionArrayTraveler->SetPositions(RelativePositions, InitialPosition);
}

void URGBObjectMover::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsPaused) {
		if (PauseCount <= 0) {
			IsPaused = false;
		} else {
			PauseCount -= DeltaTime;
		}
		return;
	}

	auto Location = GetOwner()->GetActorLocation();
	const bool IsArrived = Location == TargetPosition;
	if (IsArrived) {
		IsPaused = true;
		PauseCount = PauseLength;

		TargetPosition = PositionArrayTraveler->GetNextPosition();

	} else {
		auto NewLocation = FMath::VInterpConstantTo(Location, TargetPosition, DeltaTime, Speed);

		GetOwner()->SetActorLocation(NewLocation);
	}
}
