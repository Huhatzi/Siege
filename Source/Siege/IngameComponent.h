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


		virtual void Tick(float DeltaSeconds) override;

		virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	

private:
	TArray<class AIngameComponent*> connectedTo;

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void startSimulation();

	class UBoxComponent* overlapFinder;

	bool simulates;

	FVector lastPosition;
	float stillSince;

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void endSimulation();

	void findRoot();
	void connect();

	void justConnect();

protected:
	UPROPERTY(EditDefaultsOnly)
	float baseHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* origin;


public:
	AIngameComponent();

	bool isRoot;

	TArray<bool> areRoots;

	UPROPERTY(BlueprintReadOnly, Replicated)
	float currentHealth;
	UFUNCTION(BlueprintCallable)
	void takeDamage(float damage);
	UFUNCTION(BlueprintCallable)
		void createConnections();
	UFUNCTION(BlueprintCallable)
		void removeIngameComponent(class AIngameComponent* component);

	UPROPERTY(BlueprintReadWrite, Replicated)
		FString ownerName;
};

