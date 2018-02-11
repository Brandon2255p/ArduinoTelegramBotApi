#include "TelegramSendMessage.h"
#include "Arduino.h"

TelegramSendMessage::TelegramSendMessage() :
    ConnectionBase("sendMessage")
{
}

void TelegramSendMessage::SendMessage(int chatId, const String &text)
{
    Serial.print("[HTTP] begin...\n");
    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header

    String result = GET("?chat_id=" + String(chatId) + "&text=" + text);
}

TelegramSendMessage TelegramSendMessage::Builder()
{
    return TelegramSendMessage();
}
