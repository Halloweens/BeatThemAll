// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "CheckDistanceDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"


bool UCheckDistanceDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AController* Controller = Cast<AController>(OwnerComp.GetOwner());
	AActor* AI = (Controller != nullptr) ? Controller->GetPawn() : nullptr;
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	if (BlackBoard == nullptr || AI == nullptr)
	{
		return false;
	}

	AActor* Target = Cast<AActor>(BlackBoard->GetValueAsObject("playerTarget"));
	FVector WaitPos = BlackBoard->GetValueAsVector("WaitPosition");
	float maxDistance = BlackBoard->GetValueAsFloat("WaitDistance");

	if (Target == nullptr)
	{
		return false;
	}

	if (FVector().Dist(Target->GetActorLocation(), WaitPos) > maxDistance + 10.f || FVector().Dist(Target->GetActorLocation(), WaitPos) < maxDistance - 10.f)
	{
		return true;
	}
	return false;
}

