// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GenericItem.h"
#include "ItemSpawner.generated.h"


UCLASS()
class GLADIATORGAM_API AItemSpawner : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		float spawnDelay;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = GamePlay)
		TArray<UClass*> typeList;


	// Sets default values for this actor's properties
	AItemSpawner();

	void itemPicked();
	bool itemSpawned;

	AGenericItem* createdItem;

private:

	float currentTime;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void Spawn();
	
};
