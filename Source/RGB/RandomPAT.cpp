// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomPAT.h"
#include "Set.h"
#include "RandomStream.h"

int URandomPAT::GetNextIndex() {
	int CurrentIndex;
	IndexQueue.Dequeue(CurrentIndex);
	IndexQueue.Enqueue(CurrentIndex);
	return CurrentIndex;
}

void URandomPAT::UpdateArraySize(int Size) {
	TSet<int> IndexSet;
	while (IndexSet.Num() < Size) {
		int Index = FMath::RandRange(0, Size - 1);
		bool Succeed;
		IndexSet.Add(Index, &Succeed);
		if (Succeed) {
			IndexQueue.Enqueue(Index);
		}
	}
}
