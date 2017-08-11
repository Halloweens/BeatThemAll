// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "Playeur.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"


APlayeur::APlayeur()
{
	this->enemyLocked = nullptr;
}

void APlayeur::BeginPlay()
{
	Super::BeginPlay();
	this->Immobilized = true;
}

// Called every frame
void APlayeur::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (lockActivated)
	{
		if (enemyNum >= 0)
			SetLookAt(enemyList[enemyNum]->GetActorLocation());
		else
			SetLookAt(FVector(3960.f, 15.f, 165.f));
	}
	else
		SetLookAt(FVector(3960.f, 15.f, 165.f));
}

// Called to bind functionality to input
void APlayeur::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	
		Super::SetupPlayerInputComponent(InputComponent);

		InputComponent->BindAxis("MoveVertical", this, &APlayeur::MoveVertical);
		InputComponent->BindAxis("MoveHorizontal", this, &APlayeur::MoveHorizontal);

		//InputComponent->BindAxis("MouseVertical", this, &APlayeur::MouseVertical);
		//InputComponent->BindAxis("MouseHorizontal", this, &APlayeur::MouseHorizontal);

		InputComponent->BindAction("Attack", IE_Pressed, this, &APlayeur::Attack);
		InputComponent->BindAction("Lock", IE_Pressed, this, &APlayeur::Lock);
}

void APlayeur::MoveHorizontal(float value)
{
	if (!this->Immobilized)
	{
		UCameraComponent* Camera = AActor::FindComponentByClass<UCameraComponent>();
		if (Camera == nullptr)
			return;

		FRotator camRot = GetControlRotation();
		camRot.Pitch = 0.0f;
		FVector moveDir = Camera->GetRightVector();
		GetCharacterMovement()->AddInputVector(moveDir * value);
	}
}

void APlayeur::MoveVertical(float value)
{
	if (!this->Immobilized)
	{
		UCameraComponent* Camera = AActor::FindComponentByClass<UCameraComponent>();
		if (Camera == nullptr)
			return;

		FRotator camRot = GetControlRotation();
		camRot.Pitch = 0.0f;
		FVector moveDir = Camera->GetForwardVector();
		GetCharacterMovement()->AddInputVector(moveDir * value);
	}
}

void APlayeur::InitEnemyList()
{
	if (enemyList.Num() <= 0)
	{
		TActorIterator<AMyCharacter> ActorItr = TActorIterator<AMyCharacter>(GetWorld());
		while (ActorItr)
		{
			if (ActorItr->ActorHasTag("Enemy"))
				enemyList.Add(Cast<AMyCharacter>(*ActorItr));

			++ActorItr;
		}
	}
}

void APlayeur::Lock()
{
	InitEnemyList();
	lockActivated = true;
	enemyNum++;
	if (enemyNum >= enemyList.Num())
	{
		enemyNum = -1;
	}
}


void APlayeur::SetLookAt(FVector target)
{
	USpringArmComponent* Camera = AActor::FindComponentByClass<USpringArmComponent>();
	if (Camera == nullptr)
		return;

	FVector cameraPos = Camera->GetComponentLocation();
	FRotator CameraRot = UKismetMathLibrary::FindLookAtRotation(cameraPos, target);
	Camera->SetWorldRotation(CameraRot);
}