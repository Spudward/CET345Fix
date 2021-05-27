// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Control.generated.h"

UCLASS()
class CET346_API AControl : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AControl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;
	UPROPERTY(EditAnywhere)
	float speed;
	UPROPERTY(EditAnywhere)
	float jumpSpeed;

	bool isJumping = false;
	float time = 5;

	void Scroll(float Value);
	void Jump(float Value);
	void Timer();

	FTimerHandle TimerHandle;

	FVector CurrentVelocity;
};
