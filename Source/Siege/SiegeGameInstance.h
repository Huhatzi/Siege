// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CastleSaveGame.h"
#include "SiegeGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SIEGE_API USiegeGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	class UFormationSaveGame* formationSaveObject;
	UPROPERTY(BlueprintReadWrite)
	class UCastleSaveGame* castleSaveObject;
	UPROPERTY(BlueprintReadOnly)
	class UCastleNamesSaveGame* castleNamesSaveObject;
	UPROPERTY(BlueprintReadWrite)
	FString currentlyEditing;
	UPROPERTY(BlueprintReadOnly)
		class USettingsSave* settingsSaveObject;

	virtual void Init() override;
	virtual void Shutdown() override;

	UFUNCTION(BlueprintCallable)
	void saveCastle(TArray<FBlockData> castleToSave);
	
};
