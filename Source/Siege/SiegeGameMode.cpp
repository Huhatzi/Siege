// Copyright Epic Games, Inc. All Rights Reserved.

#include "SiegeGameMode.h"
#include "SiegeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASiegeGameMode::ASiegeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
