// Fill out your copyright notice in the Description page of Project Settings.


#include "SiegeGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "FormationSaveGame.h"
#include "CastleNamesSaveGame.h"
#include "CastleSaveGame.h"
#include "SettingsSave.h"

void USiegeGameInstance::Init()
{
	Super::Init();

	if (UGameplayStatics::DoesSaveGameExist("Formation_slot", 0))
	{
		formationSaveObject = Cast<UFormationSaveGame>(UGameplayStatics::LoadGameFromSlot("Formation_slot", 0));
	}
	else
	{
		formationSaveObject = Cast<UFormationSaveGame>(UGameplayStatics::CreateSaveGameObject(UFormationSaveGame::StaticClass()));
	}


	if (UGameplayStatics::DoesSaveGameExist("castlenames", 0))
	{
		castleNamesSaveObject = Cast<UCastleNamesSaveGame>(UGameplayStatics::LoadGameFromSlot("castlenames", 0));
	}
	else
	{
		castleNamesSaveObject = Cast<UCastleNamesSaveGame>(UGameplayStatics::CreateSaveGameObject(UCastleNamesSaveGame::StaticClass()));
	}

	if (UGameplayStatics::DoesSaveGameExist("settingssave", 0))
	{
		settingsSaveObject = Cast<USettingsSave>(UGameplayStatics::LoadGameFromSlot("settingssave", 0));
	}
	else
	{
		settingsSaveObject = Cast<USettingsSave>(UGameplayStatics::CreateSaveGameObject(USettingsSave::StaticClass()));
		settingsSaveObject->dimensions = FVector2D(700, -540);
	}

}

void USiegeGameInstance::Shutdown()
{
	Super::Shutdown();

	UGameplayStatics::SaveGameToSlot(formationSaveObject, "Formation_slot",0);
	UGameplayStatics::SaveGameToSlot(castleNamesSaveObject, "castlenames", 0);
	UGameplayStatics::SaveGameToSlot(settingsSaveObject, "settingssave", 0);

	if (castleSaveObject&&!currentlyEditing.IsEmpty())
	{
		UGameplayStatics::SaveGameToSlot(castleSaveObject, "castle_" + currentlyEditing, 0);
	}

}

void USiegeGameInstance::saveCastle(TArray<FBlockData> castleToSave)
{
	if (castleSaveObject && !currentlyEditing.IsEmpty())
	{
		castleSaveObject->castleData = castleToSave;
		UGameplayStatics::SaveGameToSlot(castleSaveObject, "castle_" + currentlyEditing, 0);
	}
}