// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTDecorator.h"
#include "CheckIfValidPosDecorator.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORGAM_API UCheckIfValidPosDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
		virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
