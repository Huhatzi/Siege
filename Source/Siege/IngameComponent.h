// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "IngameComponent.generated.h"

/**
 * 
 */
UCLASS()
class SIEGE_API AIngameComponent : public AStaticMeshActor
{
	GENERATED_BODY()
	

private:
	TArray<class AIngameComponent*> connectedTo;

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void startSimulation();

	class UBoxComponent* overlapFinder;

	

	void findRoot();
	void connect();

protected:
	UPROPERTY(EditDefaultsOnly)
	float baseHealth;

public:
	AIngameComponent();

	bool isRoot;

	TArray<bool> areRoots;

	UPROPERTY(BlueprintReadOnly)
	float currentHealth;
	UFUNCTION(BlueprintCallable)
	void takeDamage(float damage);
	UFUNCTION(BlueprintCallable)
		void createConnections();
	UFUNCTION(BlueprintCallable)
		void removeIngameComponent(class AIngameComponent* component);
};

