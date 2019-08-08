// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum class EColor {
	RED,
	GREEN,
	BLUE,
	WHITE
};

FLinearColor ConvertToColor(EColor Color);
