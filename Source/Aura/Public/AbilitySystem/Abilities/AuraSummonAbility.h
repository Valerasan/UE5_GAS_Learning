// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraGameplayAbility.h"
#include "AuraSummonAbility.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraSummonAbility : public UAuraGameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Summoning")
	TArray<FVector> GetSpawnLocations();
	
	UFUNCTION(BlueprintPure, Category = "Summoning")
	TSubclassOf<APawn> GetRandomMinionClass();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Summoning")
	int32 NumMinions = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Summoning")
	TArray<TSubclassOf<APawn>> MinionClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Summoning")
	float MinSpawnDistance = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Summoning")
	float MaxSpawnDistance = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Summoning")
	float SpawnSpread = 90.f;
	
	
};
