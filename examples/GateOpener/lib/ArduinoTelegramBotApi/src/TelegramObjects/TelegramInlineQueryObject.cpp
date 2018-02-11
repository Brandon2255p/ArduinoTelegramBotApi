#include "TelegramInlineQueryObject.h"

TelegramInlineQueryObject::TelegramInlineQueryObject(JsonObject& json) :
    m_From(json["from"].asObject())
    //m_Location(json["location"]),
{
    m_Id = json["id"].as<String>();
    m_Query = json["query"].as<String>();
    m_Offset = json["offset"].as<String>();
}
