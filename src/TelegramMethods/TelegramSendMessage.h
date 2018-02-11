#pragma once
#include <Arduino.h>
#include "TelegramConnectionBase.h"

class TelegramSendMessage : public ConnectionBase {
public:
    void SendMessage();
    TelegramSendMessage();
    static TelegramSendMessage Builder();
    TelegramSendMessage SetReplyMarkup(const String &replyMarkupJson);
    TelegramSendMessage SetChatId(long chatId);
    TelegramSendMessage SetText(const String &text);

private:
    bool m_hasReplyMarkup;
    String m_replyMarkup;
    long m_chatId;
    bool m_hasChatId;
    String m_text;
    bool m_hasText;
};
