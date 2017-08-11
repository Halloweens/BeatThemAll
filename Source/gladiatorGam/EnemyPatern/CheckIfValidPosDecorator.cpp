// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "CheckIfValidPosDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"


bool UCheckIfValidPosDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	if (BlackBoard == nullptr)
	{
		return false;
	}
	
	FVector valueToCheck = BlackBoard->GetValueAsVector("Weapon/ShieldPos");

	if (valueToCheck.IsZero())
		return false;

	return true;
}