// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "MyCharacter.h"
#include "../Item/GenericItem.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->CurrentHp = MaxHp;
	this->Armed = true;
	this->Shielded = true;
	this->Immobilized = false;
	this->WeapondWrap = nullptr;
	this->shieldWrap = nullptr;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );	
}


void AMyCharacter::Attack()
{
	if (this->Armed)
	{
		this->isAttacking = true;
		this->Immobilized = true;
	}

}

void AMyCharacter::DeseableAll()
{
	this->SetActorEnableCollision(false);
}

void AMyCharacter::HitHandled()
{
	TArray<AActor*> actorList;
	this->Immobilized = false;
	this->isAttacking = false;
	this->WeaponCollider->GetOverlappingActors(actorList);
	for(int i = 0; i < actorList.Num(); ++i)
	{
		AMyCharacter* character =  Cast<AMyCharacter>(actorList[i]);
		if (character != this)
		{
			character->Damage(1.0f);
			FVector selLocation = this->GetActorLocation();
			UGameplayStatics::GetPlayerController(this, 0)->ClientPlaySoundAtLocation(this->weaponHit, selLocation, 1.0f, 1.0f);
		}
	}
}

void AMyCharacter::Damage(float value)
{
	this->CurrentHp -= this->Shielded ? value : value * 2;
	UGameplayStatics::SpawnEmitterAttached(Blood, WeaponCollider, NAME_None, FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset, true);
	this->equipementloosing();
	if (CurrentHp <= 0)
	{
		this->Immobilized = true;
		DeseableAll();
	}
}

void AMyCharacter::equipementloosing()
{
	float rand = FMath::RandRange(0.0f, 1.0f);
	if (rand < this->looseEquipementRate)
	{
		rand = FMath::RandRange(0.0f, 2.0f);
		if ((int)rand == 0)
		{
			this->looseShield();
		}
		else
		{
			this->looseWeapond();
		}
	}
}

void AMyCharacter::looseShield()
{
	if (WeapondWrap == nullptr)
	{
		return;
	}
	this->Shielded = false;
	this->shieldWrap->SetHiddenInGame(true, true);
	UClass* toSpawn = this->shieldEffect;
	FVector location = this->GetActorLocation();
	FRotator rotation = this->GetActorRotation();
	FActorSpawnParameters param;
	AGenericItem* item = Cast<AGenericItem>(GetWorld()->SpawnActor(toSpawn, &location, &rotation, param));
	this->Armed = false;
	this->WeapondWrap->SetHiddenInGame(true, true);
}

void AMyCharacter::looseWeapond()
{
	if (this->shieldWrap == nullptr)
	{
		return;
	}
	UClass* toSpawn = this->weaponEffect;
	FVector location = this->GetActorLocation();
	FRotator rotation = this->GetActorRotation();
	FActorSpawnParameters param;
	AGenericItem* item =  Cast<AGenericItem>(GetWorld()->SpawnActor(toSpawn, &location, &rotation, param));
	this->Shielded = false;
	this->WeapondWrap->SetHiddenInGame(true, true);
}

void AMyCharacter::pickUpWeapon(UPrimitiveComponent* otherComponent)
{
	if (otherComponent->ComponentHasTag("Item"))
	{
		if (otherComponent->ComponentHasTag("Weapon") && !this->Armed)
		{
			this->WeapondWrap->SetHiddenInGame(false, true);
			this->Armed = true;
		}
		else if (otherComponent->ComponentHasTag("Shield") && !this->Shielded)
		{
			this->shieldWrap->SetHiddenInGame(false, true);
			this->Shielded = true;
		}
		AGenericItem * item = (AGenericItem*)otherComponent;
		item->pickedUpItem();
	}
}

