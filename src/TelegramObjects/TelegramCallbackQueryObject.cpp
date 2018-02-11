#include "TelegramCallbackQueryObject.h"

TelegramCallbackQueryObject::TelegramCallbackQueryObject(JsonObject& json) :
m_Id(json["id"]),
m_From(json["from"].asObject()),
m_Message(json["message"].asObject())
{
    m_ChatInstance = json["inline_message_id"].as<String>();
    m_Data = json["data"].as<String>();
    m_GameShortName = json["game_short_name"].as<String>();
}
