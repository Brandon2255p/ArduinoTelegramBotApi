#pragma once
#include <ArduinoJson.h>

#include "TelegramChatObject.h"
#include "TelegramUserObject.h"

class TelegramMessageObject
{
public:
    TelegramMessageObject(JsonObject& json);
    long m_MessageId;
    TelegramUserObject m_From;//< Optional
    long m_Date;
    TelegramChatObject m_Chat;
    TelegramUserObject m_ForwardFrom;//< Optional
    TelegramChatObject m_ForwardFromChat;//< Optional
    String m_Text;
};
