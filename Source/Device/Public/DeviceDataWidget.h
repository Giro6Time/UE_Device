// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "http.h"
#include "DeviceDataWidget.generated.h"

/**
 *
 */
UCLASS()
class DEVICE_API UDeviceDataWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* textBlock;
	UFUNCTION(BlueprintCallable)
	void SetTextBlock(UTextBlock* _textblock);
	virtual void Update(FHttpRequestPtr request, FHttpResponsePtr response, bool bSuccess);
	virtual void NativeConstruct() override;
};
