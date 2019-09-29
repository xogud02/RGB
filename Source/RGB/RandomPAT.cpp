// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomPAT.h"
#include "Set.h"
#include "Queue.h"
#include "RandomStream.h"

TArray<int32> URandomPAT::CreateIndexes(int32 Size) {
	TSet<int32> IndexSet;
	auto Indexes = TArray<int32>();
	while (IndexSet.Num() < Size) {
		int32 Index = FMath::RandRange(0, Size - 1);
		bool Fail;
		IndexSet.Add(Index, &Fail);
		if (!Fail) {
			Indexes.Add(Index);
		}
	}
	return Indexes;
}
