// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GenericItem.generated.h"

class AItemSpawner;

UENUM(BlueprintType)
enum class itemType : uint8
{
	WEAPON,
	SHIELD,
	//HEAL,
	COUNT
};


UCLASS()
class GLADIATORGAM_API AGenericItem : public AActor
{


	GENERATED_BODY()

public:
	AGenericItem();
	void SetSpawner(AItemSpawner* spawner);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	itemType type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	USkeletalMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	UBoxComponent* collider;

	void pickedUpItem();

private:	

	virtual void BeginDestroy() override;
	
	
	AItemSpawner* spawner;
	// Sets default values for this actor's properties

	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

};
