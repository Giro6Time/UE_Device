// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "http.h"
#include "DeviceDataWidget.h"
#include "TemperatureWidget.generated.h"

/**
 *
 */
UCLASS()
class DEVICE_API UTemperatureWidget : public UDeviceDataWidget
{
	GENERATED_BODY()
public:
	float temperature;
	virtual void Update(FHttpRequestPtr request, FHttpResponsePtr response, bool bSuccess);

};
