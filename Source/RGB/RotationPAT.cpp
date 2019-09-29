// Fill out your copyright notice in the Description page of Project Settings.

#include "RotationPAT.h"

TArray<int32> URotationPAT::CreateIndexes(int32 Size) {
	auto Indexes = TArray<int32>();
	Indexes.SetNum(Size);
	for(int32 i=0;i<Size;i++){
		Indexes[i] = i;
	}
	return Indexes;
}
