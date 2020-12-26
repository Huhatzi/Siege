// Fill out your copyright notice in the Description page of Project Settings.


#include "IngameComponent.h"
#include "Components/BoxComponent.h"

AIngameComponent::AIngameComponent()
{
	overlapFinder = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlapper"));
	overlapFinder->SetupAttachment(GetStaticMeshComponent());
	overlapFinder->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	overlapFinder->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	overlapFinder->SetBoxExtent(FVector(50.f));
	overlapFinder->SetRelativeScale3D(FVector(1.1f));

	SetReplicates(true);
	baseHealth = 100;
	currentHealth = baseHealth;
}

void AIngameComponent::takeDamage(float damage)
{
	currentHealth -= damage;

	if (currentHealth <= 0)
	{
		startSimulation();
		return;
	}
}

void AIngameComponent::findRoot()
{
	TArray<AActor*> Result;
	overlapFinder->GetOverlappingActors(Result, AStaticMeshActor::StaticClass());
	for (int i = 0; i < Result.Num(); i++)
	{
		if (Result[i]&&Result[i]->ActorHasTag(FName("floor")))
		{
			isRoot = true;
		}
	}

}

void AIngameComponent::createConnections()
{
	findRoot();
	if (isRoot)
	{
		connect();
	}
}

void AIngameComponent::connect()
{
	TArray<AActor*> Result;

	overlapFinder->GetOverlappingActors(Result,AIngameComponent::StaticClass());
	Result.Remove(this);
	for (int i = 0; i < Result.Num(); i++)
	{
		class AIngameComponent* casted = Cast<class AIngameComponent>(Result[i]);
		if (casted)
		{
			connectedTo.Add(casted);
			if (casted->isRoot)
			{
				areRoots.Add(true);
			}
			else
			{
				areRoots.Add(casted->areRoots.Contains(true));
			}
		}
	}

	for (int i = 0; i < connectedTo.Num(); i++)
	{
		if (!connectedTo[i]->isRoot && !connectedTo[i]->areRoots.Contains(true))
		{
			connectedTo[i]->connect();
		}
	}
}

void AIngameComponent::removeIngameComponent(class AIngameComponent* component)
{
	if (component&&connectedTo.Contains(component))
	{
		currentHealth -= baseHealth / connectedTo.Num();
		
		areRoots.RemoveAt(connectedTo.Find(component));
		connectedTo.Remove(component);

		if (!areRoots.Contains(true) || connectedTo.Num()==0 || currentHealth <= 0)
		{
			startSimulation();
		}
	}
}

void AIngameComponent::startSimulation_Implementation()
{
	currentHealth = 0;

	for (int i = 0; i < connectedTo.Num(); i++)
	{
		if (connectedTo[i])
		{
			connectedTo[i]->removeIngameComponent(this);
		}
	}

	connectedTo.Empty();
	areRoots.Empty();

	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetSimulatePhysics(true);

}

bool AIngameComponent::startSimulation_Validate()
{
	return true;
}
