// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "IngameController.generated.h"

/**
 * 
 */
UCLASS()
class SIEGE_API AIngameController : public APlayerController
{
	GENERATED_BODY()

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	AIngameController();


	UPROPERTY(BlueprintReadWrite, Replicated)
		TArray<class ASiegeCharacter*> controlledNpcs;

protected:

	UFUNCTION(BlueprintCallable)
		void executeCommand(TArray<FString> words);

	// Commander or Mage
	UPROPERTY(EditDefaultsOnly)
	FString className;

private:

	void executeCommanderCommand(TArray<FString> words);
	void executeMageCommand(TArray<FString> words);


};
