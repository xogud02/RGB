// Fill out your copyright notice in the Description page of Project Settings.


#include "RGBCharacterAnimInstance.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "GameFramework\Character.h"

URGBCharacterAnimInstance::URGBCharacterAnimInstance() {

}

void URGBCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);
	auto Pawn = TryGetPawnOwner();
	if (!IsValid(Pawn)) {
		return;
	}

	CurrentPawnSpeed = Pawn->GetVelocity().Size();
	auto Character = Cast<ACharacter>(Pawn);
	if (!Character) {
		return;
	}
	bInAir = Character->GetCharacterMovement()->IsFalling();
}
