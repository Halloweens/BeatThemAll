// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTDecorator.h"
#include "CheckDistanceDecorator.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORGAM_API UCheckDistanceDecorator : public UBTDecorator
{
	GENERATED_BODY()

public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Check)
		bool checkAttack = false;

		virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
