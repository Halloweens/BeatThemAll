// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "SetWaitPositionTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../../Source/gladiatorGam/Characters/Enemy.h"


EBTNodeResult::Type USetWaitPositionTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	if (BlackBoard == nullptr)
		return EBTNodeResult::Failed;

	AActor* Target = Cast<AActor>(BlackBoard->GetValueAsObject("playerTarget"));
	AEnemy* ActorOwner = Cast<AEnemy>(BlackBoard->GetValueAsObject("SelfActor"));
	float dist = BlackBoard->GetValueAsFloat("WaitDistance");

	float ratio = dist / (Target->GetActorLocation() - ActorOwner->GetActorLocation()).Size();
	FVector waitPos = ratio * (ActorOwner->GetActorLocation() - Target->GetActorLocation()) + Target->GetActorLocation();

	BlackBoard->SetValueAsVector("WaitPosition", waitPos);

	return EBTNodeResult::Succeeded;
}