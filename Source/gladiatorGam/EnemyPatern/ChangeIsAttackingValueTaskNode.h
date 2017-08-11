// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChangeIsAttackingValueTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORGAM_API UChangeIsAttackingValueTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Check)
		bool valueToSet;
	
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
