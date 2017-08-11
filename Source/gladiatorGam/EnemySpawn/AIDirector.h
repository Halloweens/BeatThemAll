// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AIDirector.generated.h"

UCLASS()
class GLADIATORGAM_API AAIDirector : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
		UClass*	AIClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
		TArray<AActor*>	SpawnPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
		float	GotoPlayerDelay = 5.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
		float	numberEnemy = 0.f;

	// Sets default values for this actor's properties
	AAIDirector();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	void	InitAI(ACharacter* AI);

	void	UpdateGotoPlayer();

	TArray<ACharacter*>	AIPawns;

	int32			CurrentAI = 0;
	FTimerHandle	GotoPlayerTimerHandle;

};
