#include "TelegramMessageObject.h"

TelegramMessageObject::TelegramMessageObject(JsonObject& json) :
    m_MessageId(json["message_id"]),
    m_Date(json["date"]),
    m_From(json["from"].asObject()),
    m_Chat(json["chat"].asObject()),
    m_ForwardFrom(json["forward_from"].asObject()),
    m_ForwardFromChat(json["forward_from_chat"].asObject())
{
    m_Text = json["text"].as<String>();
}
