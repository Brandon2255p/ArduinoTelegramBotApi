#pragma once
#include <ArduinoJson.h>

class TelegramUserObject
{
public:
    TelegramUserObject(JsonObject &json);
    long m_Id;
    bool m_IsBot;
    String m_FirstName;
    String m_LastName;
    String m_UserName;
    String m_LanguageCode;
};
