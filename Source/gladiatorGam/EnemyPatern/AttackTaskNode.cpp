// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "AttackTaskNode.h"
#include "../../Source/gladiatorGam/Characters/Enemy.h"


EBTNodeResult::Type UAttackTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 * NodeMemory)
{
	AController* Controller = Cast<AController>(OwnerComp.GetOwner());
	AEnemy* ActorOwner = Cast<AEnemy>((Controller != nullptr) ? Controller->GetPawn() : nullptr);

	if (ActorOwner == nullptr)
		return EBTNodeResult::Failed;

	ActorOwner->Attack();

	return EBTNodeResult::Succeeded;
}

