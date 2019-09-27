// Fill out your copyright notice in the Description page of Project Settings.

#include "RotationPAT.h"

int32 URotationPAT::GetNextIndex() {
	CurrentIndex++;
	CurrentIndex %= Size;
	return CurrentIndex;
}

void URotationPAT::UpdateArraySize(int32 Size) {
	URotationPAT::Size = Size;
}
