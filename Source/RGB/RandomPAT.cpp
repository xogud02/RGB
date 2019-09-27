// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomPAT.h"
#include "Set.h"
#include "RandomStream.h"

int32 URandomPAT::GetNextIndex() {
	int32 CurrentIndex;
	IndexQueue.Dequeue(CurrentIndex);
	IndexQueue.Enqueue(CurrentIndex);
	return CurrentIndex;
}

void URandomPAT::UpdateArraySize(int32 Size) {
	TSet<int32> IndexSet;
	while (IndexSet.Num() < Size) {
		int32 Index = FMath::RandRange(0, Size - 1);
		bool Fail;
		IndexSet.Add(Index, &Fail);
		if (!Fail) {
			IndexQueue.Enqueue(Index);
		}
	}
}
