#include "MediSimCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "CardiovascularAttributeSet.h"

// Sets default values
AMediSimCharacter::AMediSimCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create the Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	// Create the Cardiovascular Attribute Set
	CardiovascularAttributes = CreateDefaultSubobject<UCardiovascularAttributeSet>(TEXT("CardiovascularAttributes"));
}

// Called when the game starts or when spawned
void AMediSimCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		InitializeAttributes();
		GiveAbilities();
	}
}

// Called every frame
void AMediSimCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMediSimCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// You can bind input to the ability system here (optional)
}

// Implement the Ability System Component interface
UAbilitySystemComponent* AMediSimCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Initialize attributes for the character
void AMediSimCharacter::InitializeAttributes()
{
	if (!AbilitySystemComponent || !CardiovascularAttributes)
	{
		return;
	}

	// You need to create a Gameplay Effect in your project that initializes the attributes
	TSubclassOf<UGameplayEffect> InitEffect;  // Assign this to your custom attribute initialization effect

	if (InitEffect)
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(InitEffect, 1, EffectContext);
		if (NewHandle.IsValid())
		{
			AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*NewHandle.Data.Get());
		}
	}
}

// Grant abilities to the character
void AMediSimCharacter::GiveAbilities()
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		// Loop through the array of default abilities and grant each to the character
		for (TSubclassOf<UGameplayAbility>& StartupAbility : DefaultAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, 1, INDEX_NONE, this));
		}
	}
}
