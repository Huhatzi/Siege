// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CastleNamesSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class SIEGE_API UCastleNamesSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
		UPROPERTY(BlueprintReadOnly)
		TArray<FString> castleNames;
};
