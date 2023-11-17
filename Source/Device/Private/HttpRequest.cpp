
#include "HttpRequest.h"

UHttpRequest::UHttpRequest()
{
}



void UHttpRequest::HttpRequest(const FString& Url, const FString& Verb, const FString& Content)
{
    TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(Url);
    Request->SetVerb(Verb);
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetContentAsString(Content);
    Request->OnProcessRequestComplete().BindLambda([](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            if (bWasSuccessful)
            {
                FString ResponseContent = Response->GetContentAsString();
                UE_LOG(LogTemp, Warning, TEXT("ok"));
                TSharedPtr<FJsonObject> JsonObject;
                TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseContent);
                if (FJsonSerializer::Deserialize(Reader, JsonObject))
                {
                    FString id;
                    FString name;

                    if (JsonObject->TryGetStringField("id", id))
                    {
                        UE_LOG(LogTemp, Warning, TEXT("id=%s"), *id);
                    }

                    if (JsonObject->TryGetStringField("name", name))
                    {
                        UE_LOG(LogTemp, Warning, TEXT("name=%s"), *name);
                    }
                }

            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("err"));
            }
        });
    Request->OnProcessRequestComplete().BindUObject(this, &UHttpRequest::HandleHttpRequestComplete);
    Request->ProcessRequest();
}
void UHttpRequest::HandleHttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
    if (bSuccess && Response.IsValid() && Response->GetContentLength() > 0)
    {
        FString JsonResponse = Response->GetContentAsString();
        OnHttpRequestComplete.Broadcast(JsonResponse);
    }
}