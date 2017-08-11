// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "GenericItem.h"
#include "ItemSpawner.h"

// Sets default values
AGenericItem::AGenericItem()
{
	PrimaryActorTick.bCanEverTick = true;
	this->spawner = nullptr;
	this->collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	this->collider->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	this->collider->ComponentTags.Add(FName("Item"));
	this->collider->SetCollisionProfileName("OverlapOnlyPawn");
	this->RootComponent = this->collider;
	this->ItemMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VisualRepresentation"));
	this->ItemMesh->SetupAttachment(this->RootComponent);
	this->ItemMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
}

void AGenericItem::SetSpawner(AItemSpawner * spawner)
{
	this->spawner = spawner;
}

void AGenericItem::pickedUpItem()
{
	PrimaryActorTick.bCanEverTick = false;
	this->RemoveFromRoot();
	this->SetLifeSpan(0.1f);
	/*bool destroyCheck = this->Destroy();
	if (destroyCheck)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "delete complete");
	else
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "delete fail");*/
}

// Called when the game starts or when spawned
void AGenericItem::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void AGenericItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AGenericItem::BeginDestroy()
{
	Super::BeginDestroy();
	if (this->spawner != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "item deleted");
		this->spawner->itemSpawned = false;
	}
}