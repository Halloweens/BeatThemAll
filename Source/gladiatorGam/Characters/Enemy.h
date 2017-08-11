// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Characters/MyCharacter.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORGAM_API AEnemy : public AMyCharacter
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* waitPoint;
	AEnemy();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

};
