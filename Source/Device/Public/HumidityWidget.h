// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DeviceDataWidget.h"
#include "Components/TextBlock.h"
#include "HumidityWidget.generated.h"

/**
 *
 */
UCLASS()
class DEVICE_API UHumidityWidget : public UDeviceDataWidget
{
	GENERATED_BODY()
public:
	float humidity;
	virtual void Update(FHttpRequestPtr request, FHttpResponsePtr response, bool bSuccess);

};
