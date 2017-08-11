// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Characters/MyCharacter.h"
#include "Playeur.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORGAM_API APlayeur : public AMyCharacter
{
	GENERATED_BODY()
public:

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			ACameraActor* ViewTarget;

		APlayeur();
protected:

	AMyCharacter* enemyLocked;
	TArray<AMyCharacter*> enemyList;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

		void MoveHorizontal(float value);
		void MoveVertical(float value);

		void Lock();
		void InitEnemyList();
		void SetLookAt(FVector target);

private:
	int enemyNum = -1;
	bool lockActivated = false;
	
};
