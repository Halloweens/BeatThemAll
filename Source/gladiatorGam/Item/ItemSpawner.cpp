// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "ItemSpawner.h"


// Sets default values
AItemSpawner::AItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	this->currentTime = 0.0f;
	this->itemSpawned = false;
}

void AItemSpawner::itemPicked()
{
	if (this != nullptr)
		this->itemSpawned = false;
}

// Called when the game starts or when spawned
void AItemSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItemSpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//if (!itemSpawned)
	//{
		this->currentTime += DeltaTime;
		if (currentTime >= spawnDelay)
		{
			this->currentTime = 0;
			this->Spawn();
		}
	//}
}

void AItemSpawner::Spawn()
{	
	UClass* toSpawn = typeList[FMath::RandRange(0.0f, (float)itemType::COUNT)];
	FVector location = this->GetActorLocation();
	FRotator rotation = this->GetActorRotation();
	FActorSpawnParameters param;
	createdItem = Cast<AGenericItem>(GetWorld()->SpawnActor(toSpawn, &location, &rotation, param));
	this->itemSpawned = true;
	AGenericItem* item = (AGenericItem*)toSpawn;
	item->SetSpawner(this);
}

