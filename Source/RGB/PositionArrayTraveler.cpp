// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionArrayTraveler.h"

FVector UPositionArrayTraveler::GetNextPosition() {
	int32 CurrentIndex;
	IndexQueue.Dequeue(CurrentIndex);
	IndexQueue.Enqueue(CurrentIndex);
	return Positions[CurrentIndex];
}

void UPositionArrayTraveler::SetPositions(TArray<FVector> RelativePositions, FVector InitialPosition) {
	int32 Size = RelativePositions.Num();

	auto Indexes = CreateIndexes(Size);
	for(int32 i: Indexes){
		IndexQueue.Enqueue(i);
	}

	for (auto& RelativePosition : RelativePositions) {
		Positions.Add(InitialPosition + RelativePosition);
	}
}
