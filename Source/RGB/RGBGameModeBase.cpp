// Fill out your copyright notice in the Description page of Project Settings.


#include "RGBGameModeBase.h"
#include "RGBCharacter.h"

ARGBGameModeBase::ARGBGameModeBase() {
	DefaultPawnClass = ARGBCharacter::StaticClass();
}
