#pragma once
#include <Arduino.h>
#include "TelegramConnectionBase.h"

class TelegramSendMessage : public ConnectionBase {
public:
    void SendMessage(int chatId, const String &text);
    TelegramSendMessage();
    static TelegramSendMessage Builder();
};
