#include "TelegramConnectionBase.h"
#include "Arduino.h"

#define USE_SERIAL Serial

String ConnectionBase::m_Token = "";

void ConnectionBase::SetToken(String &token)
{
    m_Token = token;
}

String ConnectionBase::GET(const String parameters){
    yield();
    HTTPClient http;
    http.setTimeout(30000);
    String url = m_BaseUrl + m_Token + "/" + m_Action + parameters;
    Serial.println(url);
    http.begin(url, m_Fingerprint); //HTTP
    int httpCode =  http.GET();
    USE_SERIAL.println("Got http reponse");
    if(httpCode == HTTP_CODE_OK)
    {
        String result = http.getString();
        http.end();
        yield();
        return result;
    };
    USE_SERIAL.println(http.errorToString(httpCode));
    http.end();
    yield();
    return "";
}
