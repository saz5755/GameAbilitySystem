#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"


void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	
	if (!AttributeSet)
	{
		UE_LOG(LogTemp, Error, TEXT("AttributeSet is not set!"));
		return;
	}

	if (!AuraAttributeSet)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to cast AttributeSet to UAuraAttributeSet"));
		return;
	}

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
}
	
