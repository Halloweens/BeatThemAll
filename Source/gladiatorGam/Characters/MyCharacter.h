// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class GLADIATORGAM_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		float CurrentHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Immobilized;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isAttacking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		float looseEquipementRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collide)
		UBoxComponent* WeaponCollider;

	UPROPERTY(EditAnywhere, Category = Sound)
		USoundBase* weaponHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		UClass* weaponEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		UClass* shieldEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		UBoxComponent* shieldWrap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		UBoxComponent* WeapondWrap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		UCapsuleComponent* characterBody;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystem* Blood;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool  verifications =  false;

	// Sets default values for this character's properties
	AMyCharacter();

	virtual void Attack();
	bool Armed, Shielded;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void DeseableAll();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		float MaxHp = 5.0f;

	UFUNCTION(BlueprintCallable, Category = "Colliding")
	virtual void HitHandled();

	UFUNCTION(BlueprintCallable, Category = "Colliding")
	virtual void Damage(float value);

	virtual void equipementloosing();
	virtual void looseShield();
	virtual void looseWeapond();

	UFUNCTION(BlueprintCallable, Category = "Colliding")
	virtual void pickUpWeapon(UPrimitiveComponent* otherComponent);
};
