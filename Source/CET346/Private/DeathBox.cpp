// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathBox.h"
#include "DrawDebugHelpers.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>


ADeathBox::ADeathBox() {
	OnActorBeginOverlap.AddDynamic(this, &ADeathBox::OnOverlapBegin);

}

void ADeathBox::BeginPlay() {
	Super::BeginPlay();

	Player = Cast<APawn>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0 , 5);
}

void ADeathBox::OnOverlapBegin(class AActor* OverLappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {

		if (OtherActor == Player) {
			//ReloadScene
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
					UGameplayStatics::LoadStreamLevel(this, "MainMenu");
		}
	}
}

