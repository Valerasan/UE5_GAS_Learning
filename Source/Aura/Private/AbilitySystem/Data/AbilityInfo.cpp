// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/AbilityInfo.h"

#include "Aura/AuraLogChannels.h"

FAuraAbilityInfo UAbilityInfo::FindAbilityInfoFromTag(const FGameplayTag& AbilityTag, bool bLogNotFound)
{
	for (const FAuraAbilityInfo& Info : AbilityInformation)
	{
		if (Info.AbilityTag == AbilityTag)
		{
			return Info;
		}
	}

	if (bLogNotFound)
		UE_LOG(LogAura, Error, TEXT("Can`t find info for ability [%s] on AbilityInfo [%s]"), *AbilityTag.ToString(), *GetNameSafe(this));
	
	return FAuraAbilityInfo();
}
