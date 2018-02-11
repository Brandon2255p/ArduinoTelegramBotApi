#pragma once
#include <ArduinoJson.h>

#include "TelegramMessageObject.h"
#include "TelegramInlineQueryObject.h"
#include "TelegramCallbackQueryObject.h"

class TelegramUpdateObject
{
public:
    TelegramUpdateObject(JsonObject& updateObject);
    long m_UpdateId;
    TelegramMessageObject m_Message;
    TelegramMessageObject m_EditedMessage;
    TelegramMessageObject m_ChannelPost;
    TelegramMessageObject m_EditedChannelPost;
    TelegramInlineQueryObject m_InlineQuery;
    TelegramCallbackQueryObject m_CallbackQuery;
};
