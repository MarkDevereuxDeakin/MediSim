#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CardiovascularAttributeSet.generated.h"

// Macro to define attribute accessors
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class MEDISIM_API UCardiovascularAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UCardiovascularAttributeSet();

    // Attribute replication functions
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    // Health attributes
    UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Health_Current)
    FGameplayAttributeData Health_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Health", Replicated)
    FGameplayAttributeData Health_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Health", Replicated)
    FGameplayAttributeData Health_Max;
    UFUNCTION()
    void OnRep_Health_Current(const FGameplayAttributeData& OldHealth);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, Health_Current)

        // Heart Rate attributes
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_HeartRate_Current)
    FGameplayAttributeData HeartRate_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData HeartRate_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData HeartRate_Max;
    UFUNCTION()
    void OnRep_HeartRate_Current(const FGameplayAttributeData& OldHeartRate);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, HeartRate_Current)

        // Systolic Blood Pressure
        UPROPERTY(BlueprintReadOnly, Category = "Blood Pressure", ReplicatedUsing = OnRep_SystolicBloodPressure_Current)
    FGameplayAttributeData SystolicBloodPressure_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Blood Pressure", Replicated)
    FGameplayAttributeData SystolicBloodPressure_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Blood Pressure", Replicated)
    FGameplayAttributeData SystolicBloodPressure_Max;
    UFUNCTION()
    void OnRep_SystolicBloodPressure_Current(const FGameplayAttributeData& OldSystolicBloodPressure);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, SystolicBloodPressure_Current)

        // Diastolic Blood Pressure
        UPROPERTY(BlueprintReadOnly, Category = "Blood Pressure", ReplicatedUsing = OnRep_DiastolicBloodPressure_Current)
    FGameplayAttributeData DiastolicBloodPressure_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Blood Pressure", Replicated)
    FGameplayAttributeData DiastolicBloodPressure_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Blood Pressure", Replicated)
    FGameplayAttributeData DiastolicBloodPressure_Max;
    UFUNCTION()
    void OnRep_DiastolicBloodPressure_Current(const FGameplayAttributeData& OldDiastolicBloodPressure);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, DiastolicBloodPressure_Current)

        // Pulse Pressure
        UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", ReplicatedUsing = OnRep_PulsePressure_Current)
    FGameplayAttributeData PulsePressure_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData PulsePressure_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData PulsePressure_Max;
    UFUNCTION()
    void OnRep_PulsePressure_Current(const FGameplayAttributeData& OldPulsePressure);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, PulsePressure_Current)

        // Mean Arterial Pressure
        UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", ReplicatedUsing = OnRep_MeanArterialPressure_Current)
    FGameplayAttributeData MeanArterialPressure_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData MeanArterialPressure_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData MeanArterialPressure_Max;
    UFUNCTION()
    void OnRep_MeanArterialPressure_Current(const FGameplayAttributeData& OldMeanArterialPressure);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, MeanArterialPressure_Current)

        // Capillary Refill Time
        UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", ReplicatedUsing = OnRep_CapillaryRefillTime_Current)
    FGameplayAttributeData CapillaryRefillTime_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData CapillaryRefillTime_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData CapillaryRefillTime_Max;
    UFUNCTION()
    void OnRep_CapillaryRefillTime_Current(const FGameplayAttributeData& OldCapillaryRefillTime);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, CapillaryRefillTime_Current)

        // Jugular Venous Pressure
        UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", ReplicatedUsing = OnRep_JugularVenousPressure_Current)
    FGameplayAttributeData JugularVenousPressure_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData JugularVenousPressure_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData JugularVenousPressure_Max;
    UFUNCTION()
    void OnRep_JugularVenousPressure_Current(const FGameplayAttributeData& OldJugularVenousPressure);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, JugularVenousPressure_Current)

        // Heart Rhythm
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_HeartRhythm_Current)
    FGameplayAttributeData HeartRhythm_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData HeartRhythm_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData HeartRhythm_Max;
    UFUNCTION()
    void OnRep_HeartRhythm_Current(const FGameplayAttributeData& OldHeartRhythm);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, HeartRhythm_Current)

        // PR Interval
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_PRInterval_Current)
    FGameplayAttributeData PRInterval_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData PRInterval_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData PRInterval_Max;
    UFUNCTION()
    void OnRep_PRInterval_Current(const FGameplayAttributeData& OldPRInterval);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, PRInterval_Current)

        // QRS Duration
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_QRSDuration_Current)
    FGameplayAttributeData QRSDuration_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData QRSDuration_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData QRSDuration_Max;
    UFUNCTION()
    void OnRep_QRSDuration_Current(const FGameplayAttributeData& OldQRSDuration);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, QRSDuration_Current)

        // QT Interval
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_QTInterval_Current)
    FGameplayAttributeData QTInterval_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData QTInterval_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData QTInterval_Max;
    UFUNCTION()
    void OnRep_QTInterval_Current(const FGameplayAttributeData& OldQTInterval);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, QTInterval_Current)

        // ST Segment
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_STSegment_Current)
    FGameplayAttributeData STSegment_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData STSegment_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData STSegment_Max;
    UFUNCTION()
    void OnRep_STSegment_Current(const FGameplayAttributeData& OldSTSegment);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, STSegment_Current)

        // Total Cholesterol
        UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", ReplicatedUsing = OnRep_TotalCholesterol_Current)
    FGameplayAttributeData TotalCholesterol_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", Replicated)
    FGameplayAttributeData TotalCholesterol_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", Replicated)
    FGameplayAttributeData TotalCholesterol_Max;
    UFUNCTION()
    void OnRep_TotalCholesterol_Current(const FGameplayAttributeData& OldTotalCholesterol);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, TotalCholesterol_Current)

        // LDL Cholesterol
        UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", ReplicatedUsing = OnRep_LDLCholesterol_Current)
    FGameplayAttributeData LDLCholesterol_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", Replicated)
    FGameplayAttributeData LDLCholesterol_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", Replicated)
    FGameplayAttributeData LDLCholesterol_Max;
    UFUNCTION()
    void OnRep_LDLCholesterol_Current(const FGameplayAttributeData& OldLDLCholesterol);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, LDLCholesterol_Current)

        // HDL Cholesterol
        UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", ReplicatedUsing = OnRep_HDLCholesterol_Current)
    FGameplayAttributeData HDLCholesterol_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", Replicated)
    FGameplayAttributeData HDLCholesterol_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", Replicated)
    FGameplayAttributeData HDLCholesterol_Max;
    UFUNCTION()
    void OnRep_HDLCholesterol_Current(const FGameplayAttributeData& OldHDLCholesterol);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, HDLCholesterol_Current)

        // Triglycerides
        UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", ReplicatedUsing = OnRep_Triglycerides_Current)
    FGameplayAttributeData Triglycerides_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", Replicated)
    FGameplayAttributeData Triglycerides_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cholesterol", Replicated)
    FGameplayAttributeData Triglycerides_Max;
    UFUNCTION()
    void OnRep_Triglycerides_Current(const FGameplayAttributeData& OldTriglycerides);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, Triglycerides_Current)

        // Troponin
        UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", ReplicatedUsing = OnRep_Troponin_Current)
    FGameplayAttributeData Troponin_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData Troponin_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData Troponin_Max;
    UFUNCTION()
    void OnRep_Troponin_Current(const FGameplayAttributeData& OldTroponin);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, Troponin_Current)

        // Stroke Volume
        UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", ReplicatedUsing = OnRep_StrokeVolume_Current)
    FGameplayAttributeData StrokeVolume_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData StrokeVolume_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData StrokeVolume_Max;
    UFUNCTION()
    void OnRep_StrokeVolume_Current(const FGameplayAttributeData& OldStrokeVolume);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, StrokeVolume_Current)

        // Cardiac Output
        UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", ReplicatedUsing = OnRep_CardiacOutput_Current)
    FGameplayAttributeData CardiacOutput_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData CardiacOutput_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData CardiacOutput_Max;
    UFUNCTION()
    void OnRep_CardiacOutput_Current(const FGameplayAttributeData& OldCardiacOutput);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, CardiacOutput_Current)

        // Ejection Fraction
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_EjectionFraction_Current)
    FGameplayAttributeData EjectionFraction_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData EjectionFraction_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData EjectionFraction_Max;
    UFUNCTION()
    void OnRep_EjectionFraction_Current(const FGameplayAttributeData& OldEjectionFraction);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, EjectionFraction_Current)

        // Valve Function
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_ValveFunction_Current)
    FGameplayAttributeData ValveFunction_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData ValveFunction_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData ValveFunction_Max;
    UFUNCTION()
    void OnRep_ValveFunction_Current(const FGameplayAttributeData& OldValveFunction);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, ValveFunction_Current)

        // Creatine Kinase
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_CreatineKinase_Current)
    FGameplayAttributeData CreatineKinase_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData CreatineKinase_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData CreatineKinase_Max;
    UFUNCTION()
    void OnRep_CreatineKinase_Current(const FGameplayAttributeData& OldCreatineKinase);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, CreatineKinase_Current)

        // B-Natriuretic Peptide
        UPROPERTY(BlueprintReadOnly, Category = "Heart", ReplicatedUsing = OnRep_BNPeptide_Current)
    FGameplayAttributeData BNPeptide_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData BNPeptide_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Heart", Replicated)
    FGameplayAttributeData BNPeptide_Max;
    UFUNCTION()
    void OnRep_BNPeptide_Current(const FGameplayAttributeData& OldBNPeptide);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, BNPeptide_Current)

        // Carotid Intima-Media Thickness (CIMT)
        UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", ReplicatedUsing = OnRep_CarotidIntimaMediaThickness_Current)
    FGameplayAttributeData CarotidIntimaMediaThickness_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData CarotidIntimaMediaThickness_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData CarotidIntimaMediaThickness_Max;
    UFUNCTION()
    void OnRep_CarotidIntimaMediaThickness_Current(const FGameplayAttributeData& OldCIMT);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, CarotidIntimaMediaThickness_Current)

        // Coronary Angiography (Stenosis)
        UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", ReplicatedUsing = OnRep_CoronaryAngiography_Current)
    FGameplayAttributeData CoronaryAngiography_Current;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData CoronaryAngiography_Min;
    UPROPERTY(BlueprintReadOnly, Category = "Cardiovascular", Replicated)
    FGameplayAttributeData CoronaryAngiography_Max;
    UFUNCTION()
    void OnRep_CoronaryAngiography_Current(const FGameplayAttributeData& OldCoronaryAngiography);
    ATTRIBUTE_ACCESSORS(UCardiovascularAttributeSet, CoronaryAngiography_Current)

protected:
    // Helper function to clamp the current value between min and max
    virtual void ClampAttribute(FGameplayAttributeData& CurrentAttr, const FGameplayAttributeData& MinAttr, const FGameplayAttributeData& MaxAttr);
    
};
