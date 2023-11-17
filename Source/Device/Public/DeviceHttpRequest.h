// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpRequest.h"
#include "DeviceDataWidget.h"
#include "DeviceHttpRequest.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DEVICE_API UDeviceHttpRequest : public UHttpRequest
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties

protected:

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDeviceDataWidget* dataWidget;
	
	void HttpRequest(const FString& Url, const FString& Verb, const FString& Content) override;
	virtual void HandleHttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess) override;
};
