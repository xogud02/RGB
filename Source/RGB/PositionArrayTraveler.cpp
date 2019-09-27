// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionArrayTraveler.h"

FVector UPositionArrayTraveler::GetNextPosition() {
	return Positions[GetNextIndex()];
}

void UPositionArrayTraveler::SetPositions(TArray<FVector> RelativePositions, FVector InitialPosition) {
	int Size = RelativePositions.Num();
	Positions.SetNum(Size);
	UpdateArraySize(Size);

	for (int i = 0; i < Size; i++) {
		Positions[i] = InitialPosition + RelativePositions[i];
	}
}
