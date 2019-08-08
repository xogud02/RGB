// Fill out your copyright notice in the Description page of Project Settings.

#include "RGB.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, RGB, "RGB" );

FLinearColor ConvertToColor(EColor Color) {
	switch (Color) {
	case EColor::RED:
		return FLinearColor::Red;
	case EColor::GREEN:
		return FLinearColor::Green;
	case EColor::BLUE:
		return FLinearColor::Blue;
	case EColor::WHITE:
	default:
		return FLinearColor::White;
	}
}
