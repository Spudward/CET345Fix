// Copyright Epic Games, Inc. All Rights Reserved.

#include "CET346GameMode.h"
#include "CET346Character.h"

ACET346GameMode::ACET346GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ACET346Character::StaticClass();	
}
