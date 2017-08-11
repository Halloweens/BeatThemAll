// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "AIDirector.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


// Sets default values
AAIDirector::AAIDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAIDirector::BeginPlay()
{
	Super::BeginPlay();
	
	if (AIClass == nullptr)
	{
		return;
	}
	
	ACharacter* DefaultAI = AIClass->GetDefaultObject<ACharacter>();
	float offset = DefaultAI->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

	AIPawns.SetNum(SpawnPoints.Num());
	for (size_t i = 0; i < SpawnPoints.Num(); ++i)
	{
		FVector Location = SpawnPoints[i]->GetActorLocation();
		Location.Z += offset;

		FRotator Rotation = SpawnPoints[i]->GetActorRotation();
		FActorSpawnParameters Params;
		Params.bNoCollisionFail = true;

		AIPawns[i] = Cast<ACharacter>(GetWorld()->SpawnActor(AIClass, &Location, &Rotation, Params));
		AIPawns[i]->SpawnDefaultController();

		this->numberEnemy = SpawnPoints.Num();

		InitAI(AIPawns[i]);
	}

	UpdateGotoPlayer();
}

// Called every frame
void AAIDirector::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void	AAIDirector::InitAI(ACharacter* AI)
{
	if (AI == nullptr)
	{
		return;
	}

	AAIController*	AIController = Cast<AAIController>(AI->GetController());
	if (AIController == nullptr)
	{
		return;
	}

	UBlackboardComponent* BlackBoard = AIController->FindComponentByClass<UBlackboardComponent>();
	if (BlackBoard == nullptr)
	{
		return;
	}
	BlackBoard->SetValueAsObject("playerTarget", UGameplayStatics::GetPlayerPawn(this, 0));
	BlackBoard->SetValueAsObject("SelfActor", AI);
	BlackBoard->SetValueAsFloat("WaitDistance", 500.f);
	BlackBoard->SetValueAsFloat("AttackDistance", 100.f);
	BlackBoard->SetValueAsFloat("MoveSpeed", 100.f);
	BlackBoard->SetValueAsVector("WaitPosition", FVector().ZeroVector);
	BlackBoard->SetValueAsBool("IntroDone", false);

}

void	AAIDirector::UpdateGotoPlayer()
{
	for (int32 i = 0; i < AIPawns.Num(); ++i)
	{
		ACharacter* AI = AIPawns[i];
		if (AI == nullptr)
		{
			continue;
		}
		AAIController*	AIController = Cast<AAIController>(AI->GetController());
		if (AIController == nullptr)
		{
			continue;
		}
		UBlackboardComponent* BlackBoard = AIController->FindComponentByClass<UBlackboardComponent>();
		if (BlackBoard == nullptr)
		{
			continue;
		}

		if (i == CurrentAI)
			BlackBoard->SetValueAsBool("FollowPlayer", true);
		
	}

	CurrentAI = (CurrentAI + 1) % AIPawns.Num();
	GetWorld()->GetTimerManager().SetTimer(GotoPlayerTimerHandle, this, &AAIDirector::UpdateGotoPlayer, 1.0f, false, GotoPlayerDelay);
}

