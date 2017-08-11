// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "ChangeIsAttackingValueTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../../Source/gladiatorGam/Characters/Playeur.h"

EBTNodeResult::Type UChangeIsAttackingValueTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 * NodeMemory)
{
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	if (BlackBoard == nullptr)
		return EBTNodeResult::Failed;

	BlackBoard->SetValueAsBool("IsAttacking", valueToSet);
	APlayeur* Target = Cast<APlayeur>(BlackBoard->GetValueAsObject("playerTarget"));
	Target->Immobilized = !valueToSet;

	if (valueToSet != BlackBoard->GetValueAsBool("IsAttacking"))
		return EBTNodeResult::Failed;

	return EBTNodeResult::Succeeded;
}

