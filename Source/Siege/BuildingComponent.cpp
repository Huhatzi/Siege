// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"


ABuildingComponent::ABuildingComponent()
{
	x_positiv = CreateDefaultSubobject<USceneComponent>(TEXT("x_positiv"));
	x_negativ = CreateDefaultSubobject<USceneComponent>(TEXT("x_negativ"));

	y_positiv = CreateDefaultSubobject<USceneComponent>(TEXT("y_positiv"));
	y_negativ = CreateDefaultSubobject<USceneComponent>(TEXT("y_negativ"));

	z_positiv = CreateDefaultSubobject<USceneComponent>(TEXT("z_positiv"));
	z_negativ = CreateDefaultSubobject<USceneComponent>(TEXT("z_negativ"));

	x_positiv->SetupAttachment(RootComponent);
	x_negativ->SetupAttachment(RootComponent);

	y_positiv->SetupAttachment(RootComponent);
	y_negativ->SetupAttachment(RootComponent);

	z_positiv->SetupAttachment(RootComponent);
	z_negativ->SetupAttachment(RootComponent);


	x_positiv_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("x_positiv_collision_test"));
	x_negativ_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("x_negativ_collision_test"));

	y_positiv_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("y_positiv_collision_test"));
	y_negativ_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("y_negativ_collision_test"));

	z_positiv_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("z_positiv_collision_test"));
	z_negativ_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("z_negativ_collision_test"));

	x_positiv_collision_test->SetupAttachment(RootComponent);
	x_negativ_collision_test->SetupAttachment(RootComponent);

	y_positiv_collision_test->SetupAttachment(RootComponent);
	y_negativ_collision_test->SetupAttachment(RootComponent);

	z_positiv_collision_test->SetupAttachment(RootComponent);
	z_negativ_collision_test->SetupAttachment(RootComponent);



}

void ABuildingComponent::update_bools()
{

}