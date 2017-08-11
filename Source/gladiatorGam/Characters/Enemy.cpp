// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "Enemy.h"


AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	waitPoint = nullptr;
	this->MaxHp = 3.0f;
	this->CurrentHp = 3.0f;
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

