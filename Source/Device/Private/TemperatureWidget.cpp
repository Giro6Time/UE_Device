// Fill out your copyright notice in the Description page of Project Settings.


#include "TemperatureWidget.h"

void UTemperatureWidget::Update(FHttpRequestPtr request, FHttpResponsePtr response, bool bSuccess)
{
    FString responseContent = response->GetContentAsString();
    UE_LOG(LogTemp, Warning, TEXT("%s"),*responseContent);
    TSharedPtr<FJsonObject> jsonObject;
    TSharedRef<TJsonReader<>> reader = TJsonReaderFactory<>::Create(responseContent);
    if (FJsonSerializer::Deserialize(reader, jsonObject))
    {
        FString id;

        if (jsonObject->TryGetStringField("temperature", id))
        {
            UE_LOG(LogTemp, Warning, TEXT("id=%s"), *id);
        }

    }
}