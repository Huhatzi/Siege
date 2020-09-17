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


protected:


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

	TArray<UStaticMeshComponent*> all_collision_components;



public:
	ABuildingComponent();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool expand_possible_x_positiv;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool expand_possible_x_negativ;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool expand_possible_y_positiv;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool expand_possible_y_negativ;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool expand_possible_z_positiv;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool expand_possible_z_negativ;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		TArray<bool> all_expand_bools;

	UFUNCTION(BlueprintCallable)
		void update_bools();

	UFUNCTION(BlueprintCallable)
		void show_expandable();

	UFUNCTION(BlueprintCallable)
		void hide_expandable();



};
