// Fill out your copyright notice in the Description page of Project Settings.


#include "DeviceDataWidget.h"

void UDeviceDataWidget::SetTextBlock(UTextBlock* _textblock)
{
	textBlock = _textblock;
}

void UDeviceDataWidget::Update(FHttpRequestPtr request, FHttpResponsePtr response, bool bSuccess)
{
	UE_LOG(LogTemp, Warning, TEXT("Get Message"));
}

void UDeviceDataWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//textBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("DeviceData")));
	if (textBlock)
	{
		textBlock->SetText(FText::FromString("QWQ"));
	}
}