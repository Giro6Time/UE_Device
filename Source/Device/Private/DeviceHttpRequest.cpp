// Fill out your copyright notice in the Description page of Project Settings.


#include "DeviceHttpRequest.h"


void UDeviceHttpRequest::HttpRequest(const FString& Url, const FString& Verb, const FString& Content)
{
    TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(Url);
    Request->SetVerb(Verb);
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetContentAsString(Content);
    Request->OnProcessRequestComplete().BindUObject(this, &UDeviceHttpRequest::HandleHttpRequestComplete);
    Request->ProcessRequest();
}
void UDeviceHttpRequest::HandleHttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
    if (bSuccess && Response.IsValid() && Response->GetResponseCode() == EHttpResponseCodes::Ok)
    {

        if (dataWidget!=nullptr)
        {
            dataWidget->Update(Request, Response, bSuccess);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("%d"),Response->GetResponseCode());
    }
}
