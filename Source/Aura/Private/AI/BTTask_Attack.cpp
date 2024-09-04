// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_Attack.h"

#include "AIController.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GEngine->AddOnScreenDebugMessage(1, 0.5f, FColor::Green, *AIOwner->GetName());
	return Super::ExecuteTask(OwnerComp, NodeMemory);



}
