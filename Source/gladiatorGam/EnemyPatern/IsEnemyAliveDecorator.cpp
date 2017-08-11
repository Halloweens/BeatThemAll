// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "IsEnemyAliveDecorator.h"
#include "../../Source/gladiatorGam/Characters/Enemy.h"
#include "BehaviorTree/BlackboardComponent.h"


bool UIsEnemyAliveDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AController* Controller = Cast<AController>(OwnerComp.GetOwner());
	AEnemy* AI = Cast<AEnemy>((Controller != nullptr) ? Controller->GetPawn() : nullptr);
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	//AEnemy* Target = Cast<AEnemy>(BlackBoard->GetValueAsObject("SelfActor"));
	if (BlackBoard == nullptr || AI == nullptr)
	{
		return false;
	}

	if (AI->CurrentHp <= 0)
		return false;

	return true;
}

