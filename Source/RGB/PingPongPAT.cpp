// Fill out your copyright notice in the Description page of Project Settings.

#include "PingPongPAT.h"
#include "Array.h"

TArray<int32> UPingPongPAT::CreateIndexes(int32 Size) {
	auto Indexes = TArray<int32>();
	for(int32 i = 0; i < Size - 1; i++){
		Indexes.Add(i);
	}
	for(int32 i = 0; i < Size - 1; i++){
		Indexes.Add(Size - 1 - i);
	}
	return Indexes;
}
//012101210