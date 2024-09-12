// Copywrite Notice


#include "CardiovascularAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"

// Default constructor
UCardiovascularAttributeSet::UCardiovascularAttributeSet()
{
    // Set default values for all parameters (Current, Min, Max)
    Health_Current = 100.0f;
    Health_Min = 0.0f;
    Health_Max = 100.0f;

    HeartRate_Current = 72.0f;  // Average resting heart rate
    HeartRate_Min = 50.0f;
    HeartRate_Max = 200.0f;

    SystolicBloodPressure_Current = 120.0f;
    SystolicBloodPressure_Min = 90.0f;
    SystolicBloodPressure_Max = 180.0f;

    DiastolicBloodPressure_Current = 80.0f;
    DiastolicBloodPressure_Min = 60.0f;
    DiastolicBloodPressure_Max = 120.0f;

    PulsePressure_Current = 40.0f;
    PulsePressure_Min = 20.0f;
    PulsePressure_Max = 100.0f;

    MeanArterialPressure_Current = 93.0f;
    MeanArterialPressure_Min = 60.0f;
    MeanArterialPressure_Max = 120.0f;

    CapillaryRefillTime_Current = 1.0f;
    CapillaryRefillTime_Min = 0.5f;
    CapillaryRefillTime_Max = 2.5f;

    JugularVenousPressure_Current = 3.0f;
    JugularVenousPressure_Min = 1.0f;
    JugularVenousPressure_Max = 6.0f;

    HeartRhythm_Current = 1.0f;  // Normal sinus rhythm (represented as a number)
    HeartRhythm_Min = 0.0f;      // Abnormal rhythm
    HeartRhythm_Max = 2.0f;      // 2 for upper bound of normal rhythms

    PRInterval_Current = 0.16f;  // Normal PR interval in seconds
    PRInterval_Min = 0.12f;
    PRInterval_Max = 0.20f;

    QRSDuration_Current = 0.10f;  // Normal QRS duration in seconds
    QRSDuration_Min = 0.06f;
    QRSDuration_Max = 0.12f;

    QTInterval_Current = 0.40f;  // Normal QT interval in seconds
    QTInterval_Min = 0.30f;
    QTInterval_Max = 0.46f;

    STSegment_Current = 0.0f;    // Normal ST segment deviation (baseline)
    STSegment_Min = -0.2f;       // ST depression
    STSegment_Max = 0.2f;        // ST elevation

    TotalCholesterol_Current = 180.0f;  // Normal cholesterol level
    TotalCholesterol_Min = 100.0f;
    TotalCholesterol_Max = 240.0f;

    LDLCholesterol_Current = 100.0f;
    LDLCholesterol_Min = 50.0f;
    LDLCholesterol_Max = 190.0f;

    HDLCholesterol_Current = 60.0f;
    HDLCholesterol_Min = 30.0f;
    HDLCholesterol_Max = 100.0f;

    Triglycerides_Current = 150.0f;
    Triglycerides_Min = 50.0f;
    Triglycerides_Max = 500.0f;

    Troponin_Current = 0.01f;  // Normal troponin level close to 0
    Troponin_Min = 0.0f;
    Troponin_Max = 10.0f;      // Elevated levels indicate myocardial injury

    StrokeVolume_Current = 70.0f;  // Normal stroke volume in mL
    StrokeVolume_Min = 50.0f;
    StrokeVolume_Max = 120.0f;

    CardiacOutput_Current = 5.0f;  // Normal cardiac output in L/min
    CardiacOutput_Min = 3.0f;
    CardiacOutput_Max = 8.0f;

    EjectionFraction_Current = 60.0f;  // Normal EF 55-70%
    EjectionFraction_Min = 30.0f;
    EjectionFraction_Max = 70.0f;

    ValveFunction_Current = 1.0f;  // Normal valve function
    ValveFunction_Min = 0.0f;      // Impaired
    ValveFunction_Max = 1.0f;      // Normal

    CarotidIntimaMediaThickness_Current = 0.6f;  // Normal CIMT in mm
    CarotidIntimaMediaThickness_Min = 0.4f;
    CarotidIntimaMediaThickness_Max = 1.5f;

    CoronaryAngiography_Current = 0.0f;  // 0 means no stenosis
    CoronaryAngiography_Min = 0.0f;
    CoronaryAngiography_Max = 100.0f;  // Stenosis percentage
}


// Health
void UCardiovascularAttributeSet::OnRep_Health_Current(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, Health_Current, OldHealth);
    ClampAttribute(Health_Current, Health_Min, Health_Max);
}

// Heart Rate
void UCardiovascularAttributeSet::OnRep_HeartRate_Current(const FGameplayAttributeData& OldHeartRate)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, HeartRate_Current, OldHeartRate);
    ClampAttribute(HeartRate_Current, HeartRate_Min, HeartRate_Max);
}

// Systolic Blood Pressure
void UCardiovascularAttributeSet::OnRep_SystolicBloodPressure_Current(const FGameplayAttributeData& OldSystolicBloodPressure)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, SystolicBloodPressure_Current, OldSystolicBloodPressure);
    ClampAttribute(SystolicBloodPressure_Current, SystolicBloodPressure_Min, SystolicBloodPressure_Max);
}

// Diastolic Blood Pressure
void UCardiovascularAttributeSet::OnRep_DiastolicBloodPressure_Current(const FGameplayAttributeData& OldDiastolicBloodPressure)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, DiastolicBloodPressure_Current, OldDiastolicBloodPressure);
    ClampAttribute(DiastolicBloodPressure_Current, DiastolicBloodPressure_Min, DiastolicBloodPressure_Max);
}

// Pulse Pressure
void UCardiovascularAttributeSet::OnRep_PulsePressure_Current(const FGameplayAttributeData& OldPulsePressure)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, PulsePressure_Current, OldPulsePressure);
    ClampAttribute(PulsePressure_Current, PulsePressure_Min, PulsePressure_Max);
}

// Mean Arterial Pressure
void UCardiovascularAttributeSet::OnRep_MeanArterialPressure_Current(const FGameplayAttributeData& OldMeanArterialPressure)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, MeanArterialPressure_Current, OldMeanArterialPressure);
    ClampAttribute(MeanArterialPressure_Current, MeanArterialPressure_Min, MeanArterialPressure_Max);
}

// Capillary Refill Time
void UCardiovascularAttributeSet::OnRep_CapillaryRefillTime_Current(const FGameplayAttributeData& OldCapillaryRefillTime)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, CapillaryRefillTime_Current, OldCapillaryRefillTime);
    ClampAttribute(CapillaryRefillTime_Current, CapillaryRefillTime_Min, CapillaryRefillTime_Max);
}

// Jugular Venous Pressure
void UCardiovascularAttributeSet::OnRep_JugularVenousPressure_Current(const FGameplayAttributeData& OldJugularVenousPressure)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, JugularVenousPressure_Current, OldJugularVenousPressure);
    ClampAttribute(JugularVenousPressure_Current, JugularVenousPressure_Min, JugularVenousPressure_Max);
}

// Heart Rhythm
void UCardiovascularAttributeSet::OnRep_HeartRhythm_Current(const FGameplayAttributeData& OldHeartRhythm)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, HeartRhythm_Current, OldHeartRhythm);
    ClampAttribute(HeartRhythm_Current, HeartRhythm_Min, HeartRhythm_Max);
}

// PR Interval
void UCardiovascularAttributeSet::OnRep_PRInterval_Current(const FGameplayAttributeData& OldPRInterval)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, PRInterval_Current, OldPRInterval);
    ClampAttribute(PRInterval_Current, PRInterval_Min, PRInterval_Max);
}

// QRS Duration
void UCardiovascularAttributeSet::OnRep_QRSDuration_Current(const FGameplayAttributeData& OldQRSDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, QRSDuration_Current, OldQRSDuration);
    ClampAttribute(QRSDuration_Current, QRSDuration_Min, QRSDuration_Max);
}

// QT Interval
void UCardiovascularAttributeSet::OnRep_QTInterval_Current(const FGameplayAttributeData& OldQTInterval)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, QTInterval_Current, OldQTInterval);
    ClampAttribute(QTInterval_Current, QTInterval_Min, QTInterval_Max);
}

// ST Segment
void UCardiovascularAttributeSet::OnRep_STSegment_Current(const FGameplayAttributeData& OldSTSegment)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, STSegment_Current, OldSTSegment);
    ClampAttribute(STSegment_Current, STSegment_Min, STSegment_Max);
}

// Total Cholesterol
void UCardiovascularAttributeSet::OnRep_TotalCholesterol_Current(const FGameplayAttributeData& OldTotalCholesterol)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, TotalCholesterol_Current, OldTotalCholesterol);
    ClampAttribute(TotalCholesterol_Current, TotalCholesterol_Min, TotalCholesterol_Max);
}

// LDL Cholesterol
void UCardiovascularAttributeSet::OnRep_LDLCholesterol_Current(const FGameplayAttributeData& OldLDLCholesterol)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, LDLCholesterol_Current, OldLDLCholesterol);
    ClampAttribute(LDLCholesterol_Current, LDLCholesterol_Min, LDLCholesterol_Max);
}

// HDL Cholesterol
void UCardiovascularAttributeSet::OnRep_HDLCholesterol_Current(const FGameplayAttributeData& OldHDLCholesterol)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, HDLCholesterol_Current, OldHDLCholesterol);
    ClampAttribute(HDLCholesterol_Current, HDLCholesterol_Min, HDLCholesterol_Max);
}

// Triglycerides
void UCardiovascularAttributeSet::OnRep_Triglycerides_Current(const FGameplayAttributeData& OldTriglycerides)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, Triglycerides_Current, OldTriglycerides);
    ClampAttribute(Triglycerides_Current, Triglycerides_Min, Triglycerides_Max);
}

// Troponin
void UCardiovascularAttributeSet::OnRep_Troponin_Current(const FGameplayAttributeData& OldTroponin)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, Troponin_Current, OldTroponin);
    ClampAttribute(Troponin_Current, Troponin_Min, Troponin_Max);
}

// Stroke Volume
void UCardiovascularAttributeSet::OnRep_StrokeVolume_Current(const FGameplayAttributeData& OldStrokeVolume)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, StrokeVolume_Current, OldStrokeVolume);
    ClampAttribute(StrokeVolume_Current, StrokeVolume_Min, StrokeVolume_Max);
}

// Cardiac Output
void UCardiovascularAttributeSet::OnRep_CardiacOutput_Current(const FGameplayAttributeData& OldCardiacOutput)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, CardiacOutput_Current, OldCardiacOutput);
    ClampAttribute(CardiacOutput_Current, CardiacOutput_Min, CardiacOutput_Max);
}

// Ejection Fraction
void UCardiovascularAttributeSet::OnRep_EjectionFraction_Current(const FGameplayAttributeData& OldEjectionFraction)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, EjectionFraction_Current, OldEjectionFraction);
    ClampAttribute(EjectionFraction_Current, EjectionFraction_Min, EjectionFraction_Max);
}

// Valve Function
void UCardiovascularAttributeSet::OnRep_ValveFunction_Current(const FGameplayAttributeData& OldValveFunction)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, ValveFunction_Current, OldValveFunction);
    ClampAttribute(ValveFunction_Current, ValveFunction_Min, ValveFunction_Max);
}

void UCardiovascularAttributeSet::OnRep_CreatineKinase_Current(const FGameplayAttributeData& OldCreatineKinase)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, CreatineKinase_Current, OldCreatineKinase);
    ClampAttribute(CreatineKinase_Current, CreatineKinase_Min, CreatineKinase_Max);
}

void UCardiovascularAttributeSet::OnRep_BNPeptide_Current(const FGameplayAttributeData& OldBNPeptide)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, BNPeptide_Current, OldBNPeptide);
    ClampAttribute(BNPeptide_Current, BNPeptide_Min, BNPeptide_Max);
}

// Carotid Intima-Media Thickness (CIMT)
void UCardiovascularAttributeSet::OnRep_CarotidIntimaMediaThickness_Current(const FGameplayAttributeData& OldCIMT)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, CarotidIntimaMediaThickness_Current, OldCIMT);
    ClampAttribute(CarotidIntimaMediaThickness_Current, CarotidIntimaMediaThickness_Min, CarotidIntimaMediaThickness_Max);
}

// Coronary Angiography (Stenosis)
void UCardiovascularAttributeSet::OnRep_CoronaryAngiography_Current(const FGameplayAttributeData& OldCoronaryAngiography)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCardiovascularAttributeSet, CoronaryAngiography_Current, OldCoronaryAngiography);
    ClampAttribute(CoronaryAngiography_Current, CoronaryAngiography_Min, CoronaryAngiography_Max);
}

void UCardiovascularAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // Health
    if (Attribute == GetHealth_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, Health_Min.GetCurrentValue(), Health_Max.GetCurrentValue());
    }
    // Heart Rate
    else if (Attribute == GetHeartRate_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, HeartRate_Min.GetCurrentValue(), HeartRate_Max.GetCurrentValue());
    }
    // Systolic Blood Pressure
    else if (Attribute == GetSystolicBloodPressure_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, SystolicBloodPressure_Min.GetCurrentValue(), SystolicBloodPressure_Max.GetCurrentValue());
    }
    // Diastolic Blood Pressure
    else if (Attribute == GetDiastolicBloodPressure_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, DiastolicBloodPressure_Min.GetCurrentValue(), DiastolicBloodPressure_Max.GetCurrentValue());
    }
    // Pulse Pressure
    else if (Attribute == GetPulsePressure_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, PulsePressure_Min.GetCurrentValue(), PulsePressure_Max.GetCurrentValue());
    }
    // Mean Arterial Pressure
    else if (Attribute == GetMeanArterialPressure_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, MeanArterialPressure_Min.GetCurrentValue(), MeanArterialPressure_Max.GetCurrentValue());
    }
    // Capillary Refill Time
    else if (Attribute == GetCapillaryRefillTime_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, CapillaryRefillTime_Min.GetCurrentValue(), CapillaryRefillTime_Max.GetCurrentValue());
    }
    // Jugular Venous Pressure
    else if (Attribute == GetJugularVenousPressure_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, JugularVenousPressure_Min.GetCurrentValue(), JugularVenousPressure_Max.GetCurrentValue());
    }
    // Heart Rhythm
    else if (Attribute == GetHeartRhythm_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, HeartRhythm_Min.GetCurrentValue(), HeartRhythm_Max.GetCurrentValue());
    }
    // PR Interval
    else if (Attribute == GetPRInterval_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, PRInterval_Min.GetCurrentValue(), PRInterval_Max.GetCurrentValue());
    }
    // QRS Duration
    else if (Attribute == GetQRSDuration_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, QRSDuration_Min.GetCurrentValue(), QRSDuration_Max.GetCurrentValue());
    }
    // QT Interval
    else if (Attribute == GetQTInterval_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, QTInterval_Min.GetCurrentValue(), QTInterval_Max.GetCurrentValue());
    }
    // ST Segment
    else if (Attribute == GetSTSegment_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, STSegment_Min.GetCurrentValue(), STSegment_Max.GetCurrentValue());
    }
    // Total Cholesterol
    else if (Attribute == GetTotalCholesterol_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, TotalCholesterol_Min.GetCurrentValue(), TotalCholesterol_Max.GetCurrentValue());
    }
    // LDL Cholesterol
    else if (Attribute == GetLDLCholesterol_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, LDLCholesterol_Min.GetCurrentValue(), LDLCholesterol_Max.GetCurrentValue());
    }
    // HDL Cholesterol
    else if (Attribute == GetHDLCholesterol_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, HDLCholesterol_Min.GetCurrentValue(), HDLCholesterol_Max.GetCurrentValue());
    }
    // Triglycerides
    else if (Attribute == GetTriglycerides_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, Triglycerides_Min.GetCurrentValue(), Triglycerides_Max.GetCurrentValue());
    }
    // Troponin
    else if (Attribute == GetTroponin_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, Troponin_Min.GetCurrentValue(), Troponin_Max.GetCurrentValue());
    }
    // Stroke Volume
    else if (Attribute == GetStrokeVolume_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, StrokeVolume_Min.GetCurrentValue(), StrokeVolume_Max.GetCurrentValue());
    }
    // Cardiac Output
    else if (Attribute == GetCardiacOutput_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, CardiacOutput_Min.GetCurrentValue(), CardiacOutput_Max.GetCurrentValue());
    }
    // Ejection Fraction
    else if (Attribute == GetEjectionFraction_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, EjectionFraction_Min.GetCurrentValue(), EjectionFraction_Max.GetCurrentValue());
    }
    // Valve Function
    else if (Attribute == GetValveFunction_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, ValveFunction_Min.GetCurrentValue(), ValveFunction_Max.GetCurrentValue());
    }
    // Creatine Kinase
    else if (Attribute == GetCreatineKinase_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, CreatineKinase_Min.GetCurrentValue(), CreatineKinase_Max.GetCurrentValue());
    }
    // B-Natriuretic Peptide
    else if (Attribute == GetBNPeptide_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, BNPeptide_Min.GetCurrentValue(), BNPeptide_Max.GetCurrentValue());
    }
    // Carotid Intima-Media Thickness (CIMT)
    else if (Attribute == GetCarotidIntimaMediaThickness_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, CarotidIntimaMediaThickness_Min.GetCurrentValue(), CarotidIntimaMediaThickness_Max.GetCurrentValue());
    }
    // Coronary Angiography (Stenosis)
    else if (Attribute == GetCoronaryAngiography_CurrentAttribute())
    {
        NewValue = FMath::Clamp(NewValue, CoronaryAngiography_Min.GetCurrentValue(), CoronaryAngiography_Max.GetCurrentValue());
    }
}


//Handle additional logic after a gameplay effect modifies an attribute
void UCardiovascularAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    // Use Data to handle attribute changes
    FGameplayAttribute Attribute = Data.EvaluatedData.Attribute;

    if (Attribute == GetHealth_CurrentAttribute())
    {
        ClampAttribute(Health_Current, Health_Min, Health_Max);
    }
    else if (Attribute == GetHeartRate_CurrentAttribute())
    {
        ClampAttribute(HeartRate_Current, HeartRate_Min, HeartRate_Max);
    }
    else if (Attribute == GetSystolicBloodPressure_CurrentAttribute())
    {
        ClampAttribute(SystolicBloodPressure_Current, SystolicBloodPressure_Min, SystolicBloodPressure_Max);
    }
    else if (Attribute == GetDiastolicBloodPressure_CurrentAttribute())
    {
        ClampAttribute(DiastolicBloodPressure_Current, DiastolicBloodPressure_Min, DiastolicBloodPressure_Max);
    }
    else if (Attribute == GetPulsePressure_CurrentAttribute())
    {
        ClampAttribute(PulsePressure_Current, PulsePressure_Min, PulsePressure_Max);
    }
    else if (Attribute == GetMeanArterialPressure_CurrentAttribute())
    {
        ClampAttribute(MeanArterialPressure_Current, MeanArterialPressure_Min, MeanArterialPressure_Max);
    }
    else if (Attribute == GetStrokeVolume_CurrentAttribute())
    {
        ClampAttribute(StrokeVolume_Current, StrokeVolume_Min, StrokeVolume_Max);
    }
    else if (Attribute == GetCardiacOutput_CurrentAttribute())
    {
        ClampAttribute(CardiacOutput_Current, CardiacOutput_Min, CardiacOutput_Max);
    }
    else if (Attribute == GetCapillaryRefillTime_CurrentAttribute())
    {
        ClampAttribute(CapillaryRefillTime_Current, CapillaryRefillTime_Min, CapillaryRefillTime_Max);
    }
    else if (Attribute == GetJugularVenousPressure_CurrentAttribute())
    {
        ClampAttribute(JugularVenousPressure_Current, JugularVenousPressure_Min, JugularVenousPressure_Max);
    }
    else if (Attribute == GetHeartRhythm_CurrentAttribute())
    {
        ClampAttribute(HeartRhythm_Current, HeartRhythm_Min, HeartRhythm_Max);
    }
    else if (Attribute == GetPRInterval_CurrentAttribute())
    {
        ClampAttribute(PRInterval_Current, PRInterval_Min, PRInterval_Max);
    }
    else if (Attribute == GetQRSDuration_CurrentAttribute())
    {
        ClampAttribute(QRSDuration_Current, QRSDuration_Min, QRSDuration_Max);
    }
    else if (Attribute == GetQTInterval_CurrentAttribute())
    {
        ClampAttribute(QTInterval_Current, QTInterval_Min, QTInterval_Max);
    }
    else if (Attribute == GetSTSegment_CurrentAttribute())
    {
        ClampAttribute(STSegment_Current, STSegment_Min, STSegment_Max);
    }
    else if (Attribute == GetTotalCholesterol_CurrentAttribute())
    {
        ClampAttribute(TotalCholesterol_Current, TotalCholesterol_Min, TotalCholesterol_Max);
    }
    else if (Attribute == GetLDLCholesterol_CurrentAttribute())
    {
        ClampAttribute(LDLCholesterol_Current, LDLCholesterol_Min, LDLCholesterol_Max);
    }
    else if (Attribute == GetHDLCholesterol_CurrentAttribute())
    {
        ClampAttribute(HDLCholesterol_Current, HDLCholesterol_Min, HDLCholesterol_Max);
    }
    else if (Attribute == GetTriglycerides_CurrentAttribute())
    {
        ClampAttribute(Triglycerides_Current, Triglycerides_Min, Triglycerides_Max);
    }
    else if (Attribute == GetTroponin_CurrentAttribute())
    {
        ClampAttribute(Troponin_Current, Troponin_Min, Troponin_Max);
    }
    else if (Attribute == GetCreatineKinase_CurrentAttribute())
    {
        ClampAttribute(CreatineKinase_Current, CreatineKinase_Min, CreatineKinase_Max);
    }
    else if (Attribute == GetBNPeptide_CurrentAttribute())
    {
        ClampAttribute(BNPeptide_Current, BNPeptide_Min, BNPeptide_Max);
    }
    else if (Attribute == GetEjectionFraction_CurrentAttribute())
    {
        ClampAttribute(EjectionFraction_Current, EjectionFraction_Min, EjectionFraction_Max);
    }
    else if (Attribute == GetValveFunction_CurrentAttribute())
    {
        ClampAttribute(ValveFunction_Current, ValveFunction_Min, ValveFunction_Max);
    }
    else if (Attribute == GetCarotidIntimaMediaThickness_CurrentAttribute())
    {
        ClampAttribute(CarotidIntimaMediaThickness_Current, CarotidIntimaMediaThickness_Min, CarotidIntimaMediaThickness_Max);
    }
    else if (Attribute == GetCoronaryAngiography_CurrentAttribute())
    {
        ClampAttribute(CoronaryAngiography_Current, CoronaryAngiography_Min, CoronaryAngiography_Max);
    }

}

// Function to replicate cardiovascular attributes across the network
void UCardiovascularAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // Replicate Health attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, Health_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, Health_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, Health_Max, COND_None, REPNOTIFY_Always);

    // Replicate Heart Rate attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, HeartRate_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, HeartRate_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, HeartRate_Max, COND_None, REPNOTIFY_Always);

    // Replicate Systolic and Diastolic Blood Pressure attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, SystolicBloodPressure_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, SystolicBloodPressure_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, SystolicBloodPressure_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, DiastolicBloodPressure_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, DiastolicBloodPressure_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, DiastolicBloodPressure_Max, COND_None, REPNOTIFY_Always);

    // Replicate Pulse Pressure attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, PulsePressure_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, PulsePressure_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, PulsePressure_Max, COND_None, REPNOTIFY_Always);

    // Replicate Mean Arterial Pressure attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, MeanArterialPressure_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, MeanArterialPressure_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, MeanArterialPressure_Max, COND_None, REPNOTIFY_Always);

    // Replicate Capillary Refill Time attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CapillaryRefillTime_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CapillaryRefillTime_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CapillaryRefillTime_Max, COND_None, REPNOTIFY_Always);

    // Replicate Jugular Venous Pressure attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, JugularVenousPressure_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, JugularVenousPressure_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, JugularVenousPressure_Max, COND_None, REPNOTIFY_Always);

    // Replicate Heart Rhythm, PR Interval, QRS Duration, QT Interval, ST Segment attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, HeartRhythm_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, HeartRhythm_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, HeartRhythm_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, PRInterval_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, PRInterval_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, PRInterval_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, QRSDuration_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, QRSDuration_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, QRSDuration_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, QTInterval_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, QTInterval_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, QTInterval_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, STSegment_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, STSegment_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, STSegment_Max, COND_None, REPNOTIFY_Always);

    // Replicate Cholesterol attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, TotalCholesterol_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, TotalCholesterol_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, TotalCholesterol_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, LDLCholesterol_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, LDLCholesterol_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, LDLCholesterol_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, HDLCholesterol_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, HDLCholesterol_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, HDLCholesterol_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, Triglycerides_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, Triglycerides_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, Triglycerides_Max, COND_None, REPNOTIFY_Always);

    // Replicate new Troponin, Stroke Volume, and Cardiac Output attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, Troponin_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, Troponin_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, Troponin_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, StrokeVolume_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, StrokeVolume_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, StrokeVolume_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CardiacOutput_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CardiacOutput_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CardiacOutput_Max, COND_None, REPNOTIFY_Always);

    // Replicate remaining Ejection Fraction, Valve Function, CIMT, Coronary Angiography attributes
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, EjectionFraction_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, EjectionFraction_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, EjectionFraction_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, ValveFunction_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, ValveFunction_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, ValveFunction_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CarotidIntimaMediaThickness_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CarotidIntimaMediaThickness_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CarotidIntimaMediaThickness_Max, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CoronaryAngiography_Current, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CoronaryAngiography_Min, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCardiovascularAttributeSet, CoronaryAngiography_Max, COND_None, REPNOTIFY_Always);
}
// Helper function to clamp an attribute between its min and max values
void UCardiovascularAttributeSet::ClampAttribute(FGameplayAttributeData& CurrentAttr, const FGameplayAttributeData& MinAttr, const FGameplayAttributeData& MaxAttr)
{
    float MinValue = MinAttr.GetCurrentValue();
    float MaxValue = MaxAttr.GetCurrentValue();
    float CurrentValue = FMath::Clamp(CurrentAttr.GetCurrentValue(), MinValue, MaxValue);
    CurrentAttr.SetBaseValue(CurrentValue);
    CurrentAttr.SetCurrentValue(CurrentValue);
}

