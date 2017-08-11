// Fill out your copyright notice in the Description page of Project Settings.

#include "gladiatorGam.h"
#include "HaveWeaponDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../../Source/gladiatorGam/Characters/Enemy.h"
#include "../../Source/gladiatorGam/Item/ItemSpawner.h"

namespace WeaponAndShieldSetter
{

	void SetWeaponToGet(UBlackboardComponent* BlackBoard, TArray<AItemSpawner*> itemSpawnerList)
	{
		for (int i = 0; i < itemSpawnerList.Num(); i++)
		{
			if (itemSpawnerList[i]->itemSpawned)
			{
				if (itemSpawnerList[i]->createdItem->ActorHasTag("Weapon"))
				{
					BlackBoard->SetValueAsVector("Weapon/ShieldPos", itemSpawnerList[i]->createdItem->GetActorLocation());
					return;
				}
			}
		}

		BlackBoard->SetValueAsVector("Weapon/ShieldPos", FVector());
	}

	void SetShieldToGet(UBlackboardComponent* BlackBoard, TArray<AItemSpawner*> itemSpawnerList)
	{
		for (int i = 0; i < itemSpawnerList.Num(); i++)
		{
			if (itemSpawnerList[i]->itemSpawned)
			{
				if (itemSpawnerList[i]->createdItem->ActorHasTag("Shield"))
				{
					BlackBoard->SetValueAsVector("Weapon/ShieldPos", itemSpawnerList[i]->createdItem->GetActorLocation());
					return;
				}
			}
		}

		BlackBoard->SetValueAsVector("Weapon/ShieldPos", FVector());
	}
}


bool UHaveWeaponDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AController* Controller = Cast<AController>(OwnerComp.GetOwner());
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	if (BlackBoard == nullptr)
	{
		return false;
	}

	AEnemy* AI = Cast<AEnemy>(BlackBoard->GetValueAsObject("SelfActor"));

	if (AI->Armed && AI->Shielded)
	{
		return false;
	}

	TArray<AItemSpawner*> itemSpawnerList;
	TActorIterator<AItemSpawner> ActorItr = TActorIterator<AItemSpawner>(GetWorld());
	while (ActorItr)
	{
		if (ActorItr->ActorHasTag("ItemSpawner"))
			itemSpawnerList.Add(Cast<AItemSpawner>(*ActorItr));

		++ActorItr;
	}

	//set value
	if (!AI->Armed)
		WeaponAndShieldSetter::SetWeaponToGet(BlackBoard, itemSpawnerList);
	if (!AI->Shielded)
		WeaponAndShieldSetter::SetShieldToGet(BlackBoard, itemSpawnerList);

	return true;
}