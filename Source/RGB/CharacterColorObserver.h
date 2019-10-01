// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RGB.h"
#include "UObject/Interface.h"
#include "CharacterColorObserver.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCharacterColorObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RGB_API ICharacterColorObserver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void UpdateColor(EColor NewColor) PURE_VIRTUAL(UCharacterColorObserver::UpdateColor, return; );
};
