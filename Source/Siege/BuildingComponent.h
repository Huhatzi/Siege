// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "BuildingComponent.generated.h"

/**
 * 
 */
UCLASS()
class SIEGE_API ABuildingComponent : public AStaticMeshActor
{
	GENERATED_BODY()

		virtual void BeginPlay() override;

protected:

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
		class UBoxComponent* overlapFinder;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* x_positiv;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* x_negativ;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* y_positiv;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* y_negativ;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* z_positiv;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* z_negativ;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* origin;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* x_positiv_collision_test;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* x_negativ_collision_test;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* y_positiv_collision_test;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* y_negativ_collision_test;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* z_positiv_collision_test;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* z_negativ_collision_test;

private:

	bool expand_possible_x_positiv;

	bool expand_possible_x_negativ;

	bool expand_possible_y_positiv;

	bool expand_possible_y_negativ;

	bool expand_possible_z_positiv;

	bool expand_possible_z_negativ;


public:
	ABuildingComponent();

	UPROPERTY(EditDefaultsOnly)
		bool default_expand_possible_x_positiv;

	UPROPERTY(EditDefaultsOnly)
		bool default_expand_possible_x_negativ;

	UPROPERTY(EditDefaultsOnly)
		bool default_expand_possible_y_positiv;

	UPROPERTY(EditDefaultsOnly)
		bool default_expand_possible_y_negativ;

	UPROPERTY(EditDefaultsOnly)
		bool default_expand_possible_z_positiv;

	UPROPERTY(EditDefaultsOnly)
		bool default_expand_possible_z_negativ;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		TArray<bool> all_expand_bools;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		TArray<ABuildingComponent*> already_constraint;


	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TArray<UStaticMeshComponent*> all_collision_components;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = a)
	TSubclassOf<class AIngameComponent> ingame_version;


	UFUNCTION(BlueprintCallable)
		void update_bools();

	UFUNCTION(BlueprintCallable)
		void show_expandable();

	UFUNCTION(BlueprintCallable)
		void hide_expandable();



};
