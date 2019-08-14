// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define ARGS_LOG(x, ...) UE_LOG(LogTemp, Warning, TEXT(x), __VA_ARGS__);
#define SIMPLE_LOG(x) ARGS_LOG(x);

UENUM()
enum class EColor {
	RED,
	GREEN,
	BLUE,
	WHITE
};

FLinearColor ConvertToColor(EColor Color);

EColor ConvertToEnum(FString Name);
