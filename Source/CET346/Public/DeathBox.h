// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "DeathBox.generated.h"

/**
 * 
 */
UCLASS()
class CET346_API ADeathBox : public ATriggerBox
{
	GENERATED_BODY()

	protected:
		virtual void BeginPlay() override;
	public:

		ADeathBox();

		UFUNCTION() 
			void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

		UPROPERTY(EditAnywhere)
			AActor* Player;
	
};
