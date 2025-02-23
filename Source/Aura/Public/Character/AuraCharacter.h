// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/PlayerInterface.h"
#include "AuraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UNiagaraComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase, public IPlayerInterface
{
	GENERATED_BODY()
public:
	AAuraCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/** Player Interface */
	virtual int32 FindLevelForXP_Implementation(int32 InXP) const override;
	virtual void AddToXP_Implementation(int32 InXP) override;
	virtual void AddToPlayerLevel_Implementation(int32 InPlayerLevel) override;
	virtual void AddToAttributePointReward_Implementation(int32 InAttributePointReward) override;
	virtual void AddToSpellPointReward_Implementation(int32 InSpellPointReward) override;
	virtual int32 GetXP_Implementation() override;
	virtual int32 GetAttributePointReward_Implementation(int32 Level) const override;
	virtual int32 GetSpellPointReward_Implementation(int32 Level) const override;
	virtual void LevelUp_Implementation() override;
	/**End Player Interface */
	
	/** Combat Interface */
	virtual int32 GetPlayerLevel_Implementation() override;
	/**End Combat Interface */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character")
	TObjectPtr<UNiagaraComponent> LevelUpNiagaraComponent;


	
	
private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	virtual void InitAbilityActorInfo() override;

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_LevelUpParticles();
};

