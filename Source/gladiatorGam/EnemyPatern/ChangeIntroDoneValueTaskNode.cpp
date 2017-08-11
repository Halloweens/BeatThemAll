// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "ChangeIntroDoneValueTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChangeIntroDoneValueTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 * NodeMemory)
{
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	if (BlackBoard == nullptr)
		return EBTNodeResult::Failed;

	BlackBoard->SetValueAsBool("IntroDone", valueToSet);

	if (valueToSet != BlackBoard->GetValueAsBool("IntroDone"))
		return EBTNodeResult::Failed;

	return EBTNodeResult::Succeeded;
}



