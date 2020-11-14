// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FormationSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FFormationStruct
{
    GENERATED_USTRUCT_BODY();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FVector2D> formation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString name;
};

/**
 * 
 */
UCLASS()
class SIEGE_API UFormationSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
     UPROPERTY(BlueprintReadWrite)
     TArray<FFormationStruct> formationsSaved;
	
};
