// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JsonUtilities.h"
#include "GameFramework/Actor.h"
#include "http.h"
#include "Delegates/Delegate.h"
#include "Delegates/DelegateCombinations.h"
#include "Components/ActorComponent.h"
#include "HttpRequest.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHttpRequestComplete, const FString&, JsonResponse);
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DEVICE_API UHttpRequest : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UHttpRequest();

protected:

public:
	UPROPERTY(BlueprintAssignable)
	FOnHttpRequestComplete OnHttpRequestComplete;

	UFUNCTION(BlueprintCallable)
	virtual void HttpRequest(const FString& Url, const FString& Verb, const FString& Content);
	virtual void HandleHttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);
};
