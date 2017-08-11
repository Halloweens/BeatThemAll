// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTDecorator.h"
#include "IsEnemyAliveDecorator.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORGAM_API UIsEnemyAliveDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
	
		virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	
};
