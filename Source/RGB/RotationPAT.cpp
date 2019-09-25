// Fill out your copyright notice in the Description page of Project Settings.

#include "RotationPAT.h"

int URotationPAT::GetNextIndex() {
	CurrentIndex++;
	CurrentIndex %= Size;
	return CurrentIndex;
}

void URotationPAT::UpdateArraySize(int Size) {
	URotationPAT::Size = Size;
}
