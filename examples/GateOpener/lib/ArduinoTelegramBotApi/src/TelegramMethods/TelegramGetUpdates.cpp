#include "TelegramGetUpdates.h"
#include "Arduino.h"

#define USE_SERIAL Serial

TelegramGetUpdates::TelegramGetUpdates() :
    ConnectionBase("getUpdates"),
    m_hasOffset(false),
    m_hasLimit(false),
    m_hasHandler(false)
{
}

TelegramGetUpdates TelegramGetUpdates::Builder()
{
        return TelegramGetUpdates();
}

TelegramGetUpdates TelegramGetUpdates::RegisterResponseHandler(std::function<void(String &jsonResult)> handler)
{
    m_hasHandler = true;
    m_handler = handler;
    return *this;
}

TelegramGetUpdates TelegramGetUpdates::SetOffset(int offset)
{
    m_hasOffset = true;
    m_offset = offset;
    return *this;
}

TelegramGetUpdates TelegramGetUpdates::SetLimit(int limit)
{
    if(limit < 1)
        limit = 1;
    if(limit > 100)
        limit = 100;
    m_limit = limit;
    m_hasLimit = true;
    return *this;
}

TelegramGetUpdates TelegramGetUpdates::SetTimeout(int timeout_s)
{
    if(timeout_s < 0)
        timeout_s = 0;
    m_timeout_s = timeout_s;
    m_hasTimeout = true;
    return *this;
}

void TelegramGetUpdates::GetUpdates()
{
    Serial.print("[Telegram] Getting updates...\n");
    String parameters = "?";
    if(m_hasLimit)
        parameters += "&limit=" + String(m_limit);
    if(m_hasOffset)
        parameters += "&offset=" + String(m_offset);
    if(m_hasTimeout)
        parameters += "&timeout=" + String(m_timeout_s);

    String result = GET(parameters);
    if(m_hasHandler)
    {
        USE_SERIAL.println("Handeling update resonse");
        m_handler(result);

    }
    else {
        USE_SERIAL.println("No handler registered");
    }
}
