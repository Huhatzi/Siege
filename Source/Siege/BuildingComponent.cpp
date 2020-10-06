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
	x_positiv->SetRelativeLocation(FVector(100.f, 0.f, 0.f));

	x_negativ->SetupAttachment(RootComponent);
	x_negativ->SetRelativeLocation(FVector(-100.f, 0.f, 0.f));

	y_positiv->SetupAttachment(RootComponent);
	y_positiv->SetRelativeLocation(FVector(0.f, 100.f, 0.f));

	y_negativ->SetupAttachment(RootComponent);
	y_negativ->SetRelativeLocation(FVector(0.f, -100.f, 0.f));

	z_positiv->SetupAttachment(RootComponent);
	z_positiv->SetRelativeLocation(FVector(0.f, 0.f, 100.f));

	z_negativ->SetupAttachment(RootComponent);
	z_negativ->SetRelativeLocation(FVector(0.f, 0.f, -100.f));

	SetReplicates(true);

	x_positiv_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("x_positiv_collision_test"));
	x_negativ_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("x_negativ_collision_test"));

	y_positiv_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("y_positiv_collision_test"));
	y_negativ_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("y_negativ_collision_test"));

	z_positiv_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("z_positiv_collision_test"));
	z_negativ_collision_test = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("z_negativ_collision_test"));

	x_positiv_collision_test->SetupAttachment(x_positiv);
	x_negativ_collision_test->SetupAttachment(x_negativ);

	y_positiv_collision_test->SetupAttachment(y_positiv);
	y_negativ_collision_test->SetupAttachment(y_negativ);

	z_positiv_collision_test->SetupAttachment(z_positiv);
	z_negativ_collision_test->SetupAttachment(z_negativ);

	x_positiv_collision_test->ComponentTags.Add("xp");
	x_negativ_collision_test->ComponentTags.Add("xn");

	y_positiv_collision_test->ComponentTags.Add("yp");
	y_negativ_collision_test->ComponentTags.Add("yn");

	z_positiv_collision_test->ComponentTags.Add("zp");
	z_negativ_collision_test->ComponentTags.Add("zn");



	x_positiv_collision_test->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	x_negativ_collision_test->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;

	y_positiv_collision_test->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	y_negativ_collision_test->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;

	z_positiv_collision_test->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	z_negativ_collision_test->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;



	x_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	x_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	y_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	y_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	z_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	z_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	x_positiv_collision_test->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	x_negativ_collision_test->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	y_positiv_collision_test->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	y_negativ_collision_test->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	z_positiv_collision_test->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	z_negativ_collision_test->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	x_positiv_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Ignore);
	x_negativ_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Ignore);

	y_positiv_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Ignore);
	y_negativ_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Ignore);

	z_positiv_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Ignore);
	z_negativ_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Ignore);



	x_positiv_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	x_negativ_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

	y_positiv_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	y_negativ_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

	z_positiv_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	z_negativ_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

	x_positiv_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	x_negativ_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	y_positiv_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	y_negativ_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	z_positiv_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	z_negativ_collision_test->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);


	
	
	GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Ignore);
	GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Overlap);
	GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);
	GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);

	x_positiv_collision_test->SetWorldScale3D(FVector(0.95f));
	x_negativ_collision_test->SetWorldScale3D(FVector(0.95));

	y_positiv_collision_test->SetWorldScale3D(FVector(0.95f));
	y_negativ_collision_test->SetWorldScale3D(FVector(0.95f));

	z_positiv_collision_test->SetWorldScale3D(FVector(0.95f));
	z_negativ_collision_test->SetWorldScale3D(FVector(0.95f));

	all_collision_components.Add(x_positiv_collision_test);
	all_collision_components.Add(x_negativ_collision_test);

	all_collision_components.Add(y_positiv_collision_test);
	all_collision_components.Add(y_negativ_collision_test);

	all_collision_components.Add(z_positiv_collision_test);
	all_collision_components.Add(z_negativ_collision_test);

	default_expand_possible_x_positiv = true;
	default_expand_possible_x_negativ = true;

	default_expand_possible_y_positiv = true;
	default_expand_possible_y_negativ = true;

	default_expand_possible_z_positiv = true;
	default_expand_possible_z_negativ = true;


	expand_possible_x_positiv = default_expand_possible_x_positiv;
	expand_possible_x_negativ = default_expand_possible_x_negativ;
	expand_possible_y_positiv = default_expand_possible_y_positiv;
	expand_possible_y_negativ = default_expand_possible_y_negativ;
	expand_possible_z_positiv = default_expand_possible_z_positiv;
	expand_possible_z_negativ = default_expand_possible_z_negativ;


	all_expand_bools.Add(default_expand_possible_x_positiv);
	all_expand_bools.Add(default_expand_possible_x_negativ);

	all_expand_bools.Add(default_expand_possible_y_positiv);
	all_expand_bools.Add(default_expand_possible_y_negativ);

	all_expand_bools.Add(default_expand_possible_z_positiv);
	all_expand_bools.Add(default_expand_possible_z_negativ);


	x_positiv_collision_test->SetHiddenInGame(true);
	x_negativ_collision_test->SetHiddenInGame(true);

	y_positiv_collision_test->SetHiddenInGame(true);
	y_negativ_collision_test->SetHiddenInGame(true);

	z_positiv_collision_test->SetHiddenInGame(true);
	z_negativ_collision_test->SetHiddenInGame(true);

	x_positiv_collision_test->CastShadow = false;
	x_negativ_collision_test->CastShadow = false;

	y_positiv_collision_test->CastShadow = false;
	y_negativ_collision_test->CastShadow = false;

	z_positiv_collision_test->CastShadow = false;
	z_negativ_collision_test->CastShadow = false;





	UpdateOverlapsMethodDuringLevelStreaming = EActorUpdateOverlapsMethod::AlwaysUpdate;

}

void ABuildingComponent::BeginPlay()
{
	Super::BeginPlay();


	if (default_expand_possible_x_positiv)
		x_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (default_expand_possible_x_negativ)
		x_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (default_expand_possible_y_positiv)
		y_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (default_expand_possible_y_negativ)
		y_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (default_expand_possible_z_positiv)
		z_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (default_expand_possible_z_negativ)
		z_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);


}

void ABuildingComponent::update_bools()
{
	TArray<AActor*> actor_array;


	expand_possible_x_positiv = default_expand_possible_x_positiv;
	expand_possible_x_negativ = default_expand_possible_x_negativ;
	expand_possible_y_positiv = default_expand_possible_y_positiv;
	expand_possible_y_negativ = default_expand_possible_y_negativ;
	expand_possible_z_positiv = default_expand_possible_z_positiv;
	expand_possible_z_negativ = default_expand_possible_z_negativ;

	if(expand_possible_x_positiv)
	x_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (expand_possible_x_negativ)
	x_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (expand_possible_y_positiv)
	y_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (expand_possible_y_negativ)
	y_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (expand_possible_z_positiv)
	z_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (expand_possible_z_negativ)
	z_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);


	for (int32 Index1 = 0; Index1 != all_collision_components.Num(); ++Index1)
	{
		actor_array.Empty();

		all_collision_components[Index1]->GetOverlappingActors(actor_array);

		if (actor_array.Contains(this))
			actor_array.Remove(this);

		if (actor_array.Num()>0)
		{
				switch (Index1) 
				{
					case 0: 
						expand_possible_x_positiv = false;
						x_positiv_collision_test->SetHiddenInGame(true);
						x_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);
						break;
					
					case 1: 
						expand_possible_x_negativ = false;
						x_negativ_collision_test->SetHiddenInGame(true);
						x_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);
						break;
					
					case 2: 
						expand_possible_y_positiv = false;
						y_positiv_collision_test->SetHiddenInGame(true);
						y_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);
						break;

					case 3: 
						expand_possible_y_negativ = false;
						y_negativ_collision_test->SetHiddenInGame(true);
						y_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);
						break;
					
					case 4: 
						expand_possible_z_positiv = false;
						z_positiv_collision_test->SetHiddenInGame(true);
						z_positiv_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);
						break;
					
					case 5: 
						expand_possible_z_negativ = false;
						z_negativ_collision_test->SetHiddenInGame(true);
						z_negativ_collision_test->SetCollisionEnabled(ECollisionEnabled::NoCollision);
						break;
				
				}
		}
		
	}

	all_expand_bools[0] = expand_possible_x_positiv;
	all_expand_bools[1] = expand_possible_x_negativ;
	all_expand_bools[2] = expand_possible_y_positiv;
	all_expand_bools[3] = expand_possible_y_negativ;
	all_expand_bools[4] = expand_possible_z_positiv;
	all_expand_bools[5] = expand_possible_z_negativ;



}

void ABuildingComponent::show_expandable()
{


	if (expand_possible_x_positiv)	{
		x_positiv_collision_test->SetHiddenInGame(false);
	}

	if (expand_possible_x_negativ)	{
		x_negativ_collision_test->SetHiddenInGame(false);
	}

	if (expand_possible_y_positiv) {
		y_positiv_collision_test->SetHiddenInGame(false);
	}

	if (expand_possible_y_negativ) {
		y_negativ_collision_test->SetHiddenInGame(false);
	}

	if (expand_possible_z_positiv) {
		z_positiv_collision_test->SetHiddenInGame(false);
	}

	if (expand_possible_z_negativ) {
		z_negativ_collision_test->SetHiddenInGame(false);
	}
	
}

void ABuildingComponent::hide_expandable()
{
	for (auto& component : all_collision_components)
	{
		component->SetHiddenInGame(true);
	}
}
