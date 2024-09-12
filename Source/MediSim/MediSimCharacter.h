#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "CardiovascularAttributeSet.h"
#include "MediSimCharacter.generated.h"

UCLASS()
class MEDISIM_API AMediSimCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMediSimCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Ability System Component for handling abilities and attributes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	// Cardiovascular Attribute Set
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	UCardiovascularAttributeSet* CardiovascularAttributes;

	// Implement IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Function to initialize attributes
	void InitializeAttributes();

	// Function to grant abilities
	void GiveAbilities();

	// Array of default abilities to grant to the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;
};
