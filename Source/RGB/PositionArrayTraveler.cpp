// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionArrayTraveler.h"

FVector UPositionArrayTraveler::GetNextPosition() {
	return Positions[GetNextIndex()];
}

void UPositionArrayTraveler::SetPositions(TArray<FVector> RelativePositions, FVector InitialPosition) {
	int32 Size = RelativePositions.Num();

	UpdateArraySize(Size);

	ARGS_LOG("size %d", Size);

	for (auto& RelativePosition : RelativePositions) {
		Positions.Add(InitialPosition + RelativePosition);
	}
}
