// Fill out your copyright notice in the Description page of Project Settings.

#include "PressurePlate.h"
// include draw debu helpers header file
#include "DrawDebugHelpers.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>
APressurePlate::APressurePlate()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &APressurePlate::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &APressurePlate::OnOverlapEnd);
}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
    Super::BeginPlay();

    DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 999, 0, 5);
}

void APressurePlate::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    // check if Actors do not equal nullptr and that 
    if (OtherActor && OtherActor != this)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *OverlappedActor->GetName()));
        }
    }
}

void APressurePlate::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));
        }
    }
}

