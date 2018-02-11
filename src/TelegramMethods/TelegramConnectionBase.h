#pragma once
#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

class ConnectionBase
{
public:
protected:
    String m_Token = String("");
    String m_Fingerprint =  String("c6 5b fa 5b f7 57 0c 6a 02 85 c1 6f a7 19 6c 36 32 b4 28 21");
    const String m_BaseUrl =  "https://api.telegram.org/bot";
    ConnectionBase(const String action) : m_Action(action){};
    String m_Action;
    String GET(const String parameters);
};
