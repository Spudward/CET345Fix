// Fill out your copyright notice in the Description page of Project Settings.


#include "Control.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Misc/App.h"
#include <time.h>

// Sets default values
AControl::AControl()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//set lowest number player?
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	//https://unrealcpp.com/receive-player-input/
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));

	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(0.0f, 500.0f, 0.0f));
	OurCamera->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AControl::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("works"));
	
}

// Called every frame
void AControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isJumping == true) {
		CurrentVelocity.Z = 1 * jumpSpeed;
	}

	if (!CurrentVelocity.IsZero()) {
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void AControl::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Jump", this, &AControl::Jump);
	InputComponent->BindAxis("MoveRight", this, &AControl::Scroll);
}

void AControl::Scroll(float Value)
{
	CurrentVelocity.X = FMath::Clamp(Value, -1.0f, 1.0f) * speed;
}

void AControl::Jump(float Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("starts"));
	isJumping = true;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AControl::Timer, 0.0f, false, 3.0f);
}

void AControl::Timer() {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ends"));
	isJumping = false;
}

