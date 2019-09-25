// Fill out your copyright notice in the Description page of Project Settings.

#include "PingPongPAT.h"
#include "RGB.h"

int UPingPongPAT::GetNextIndex() {
	const bool IsForwardEnd = IsForWard && CurrentIndex == Size - 1;
	const bool IsBackwardEnd = !IsForWard && CurrentIndex == 0;
	if (IsForwardEnd || IsBackwardEnd) {
		IsForWard = !IsForWard;
	}

	CurrentIndex += IsForWard ? 1 : -1;
	return CurrentIndex;
}

void UPingPongPAT::UpdateArraySize(int Size) {
	UPingPongPAT::Size = Size;
}
