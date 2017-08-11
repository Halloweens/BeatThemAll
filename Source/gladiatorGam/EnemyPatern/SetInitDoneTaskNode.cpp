// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "SetInitDoneTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USetInitDoneTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	if (BlackBoard == nullptr)
		return EBTNodeResult::Failed;

	BlackBoard->SetValueAsBool("InitDone", valueToSet);
	
	if (valueToSet != BlackBoard->GetValueAsBool("InitDone"))
		return EBTNodeResult::Failed;

	return EBTNodeResult::Succeeded;
}

