// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CastleSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FBlockData
{
    GENERATED_USTRUCT_BODY();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSubclassOf<class ABuildingComponent> blockClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FTransform blockTransform;
};

/**
 * 
 */
UCLASS()
class SIEGE_API UCastleSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
        UPROPERTY(BlueprintReadOnly)
        TArray<FBlockData> castleData;
	
};
