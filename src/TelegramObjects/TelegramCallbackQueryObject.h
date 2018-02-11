#pragma once
#include <ArduinoJson.h>

#include "TelegramMessageObject.h"

class TelegramCallbackQueryObject
{
public:
    TelegramCallbackQueryObject(JsonObject& json);
    int m_Id;
    TelegramUserObject m_From;
    TelegramMessageObject m_Message;
    String m_InlineMessageId;
    String m_ChatInstance;
    String m_Data;
    String m_GameShortName;
};
