#include "TelegramSendMessage.h"
#include "Arduino.h"

TelegramSendMessage::TelegramSendMessage() :
    ConnectionBase("sendMessage"),
    m_hasReplyMarkup(false),
    m_hasChatId(false),
    m_hasText(false)
{
}

TelegramSendMessage TelegramSendMessage::SetChatId(long chatId)
{
    m_chatId = chatId;
    m_hasChatId = true;
    return *this;
}

TelegramSendMessage TelegramSendMessage::SetText(const String &text)
{
    m_text = text;
    m_hasText = true;
    return *this;
}


TelegramSendMessage TelegramSendMessage::SetReplyMarkup(const String &replyMarkupJson)
{
    m_replyMarkup = replyMarkupJson;
    m_hasReplyMarkup = true;
    return *this;
}

void TelegramSendMessage::SendMessage()
{
    String parameters = "?";
    if(m_hasChatId)
        parameters += "&chat_id=" + String(m_chatId);
    if(m_hasText)
        parameters += "&text=" + m_text;
    if(m_hasReplyMarkup)
        parameters += "&reply_markup=" + m_replyMarkup;

    String result = GET(parameters);
}

TelegramSendMessage TelegramSendMessage::Builder()
{
    return TelegramSendMessage();
}
