// Fill out your copyright notice in the Description page of Project Settings.


#include "IngameController.h"
#include "SiegeCharacter.h"
#include "Net/UnrealNetwork.h"


AIngameController::AIngameController()
{
	className = "Commander";
}

void AIngameController::executeCommand(TArray<FString> words)
{
	ASiegeCharacter* ownedCharacter = GetPawn<ASiegeCharacter>();
	if (ownedCharacter && ownedCharacter->alive)
	{
		if (className=="Commander")
		{
			executeCommanderCommand(words);
		}
		else
			if (className == "Mage")
			{
				executeMageCommand(words);
			}

	}

}

void AIngameController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AIngameController, controlledNpcs);

}

void AIngameController::executeCommanderCommand(TArray<FString> words)
{

}

void AIngameController::executeMageCommand(TArray<FString> words)
{

}