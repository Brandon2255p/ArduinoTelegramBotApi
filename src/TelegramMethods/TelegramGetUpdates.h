#pragma once
#include <functional>
#include <Arduino.h>
#include "TelegramConnectionBase.h"
#include "../TelegramObjects/TelegramUpdateObject.h"

class TelegramGetUpdates : public ConnectionBase {
public:
    static TelegramGetUpdates Builder();
    void GetUpdates();
    TelegramGetUpdates();
    TelegramGetUpdates SetOffset(int offset);
    TelegramGetUpdates SetLimit(int limit);
    TelegramGetUpdates SetTimeout(int timeout_s);
    TelegramGetUpdates RegisterResponseHandler(std::function<void(String &jsonResult)> handler);
private:
    int m_offset;
    bool m_hasOffset;
    int m_limit;
    bool m_hasLimit;
    int m_timeout_s;
    bool m_hasTimeout;
    std::function<void(String &jsonResult)> m_handler;
    bool m_hasHandler;
};
