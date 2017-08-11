// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "Spawn.h"
#include "BehaviorTree/BlackboardComponent.h"


// Sets default values
ASpawn::ASpawn()
{
/*
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (!MaxTriggers)
		MaxTriggers = 1;
		*/
}

// Called when the game starts or when spawned
void ASpawn::BeginPlay()
{

	Super::BeginPlay();

/*	for (int i = 0; i < Count; ++i)
	{
		APawn* newEnemy = GetWorld()->SpawnActor<class APawn>(CharactersToSpawn);
		newEnemy->SetActorTransform(this->SpawnLocation);
	}
	*/
}
