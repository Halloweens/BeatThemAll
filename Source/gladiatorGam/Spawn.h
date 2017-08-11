// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Spawn.generated.h"

UCLASS()
class GLADIATORGAM_API ASpawn : public AActor
{
	GENERATED_BODY()

public:
		bool triggered;

		

	/* List of character types to spawn at or near the Spawn Location */
	UPROPERTY(EditAnywhere, Category = "Spawner")
		TSubclassOf<class ACharacter> CharactersToSpawn;

	/* Spawn location. If not set, no enemies spawn. */
	UPROPERTY(EditAnywhere, Category = "Spawner")
		FTransform SpawnLocation;

	/* Number of copies of each type of character to spawn */
	UPROPERTY(EditAnywhere, Category = "Spawner")
		int32 Count;

	/* This value indicates the maximum number of times the spawner will trigger enemies. If zero, the default of 1 is assumed. */
	UPROPERTY(EditAnywhere, Category = "Spawner")
		int32 MaxTriggers;
	
	// Sets default values for this actor's properties
	ASpawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	void	InitAI(APawn* AI);

};
