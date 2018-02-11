#include "TelegramUserObject.h"

TelegramUserObject::TelegramUserObject(JsonObject& json) :
    m_Id(json["id"]),
    m_IsBot(json["is_bot"])
{
    m_FirstName = json["first_name"].as<String>();
    m_LastName = json["last_name"].as<String>();
    m_UserName = json["username"].as<String>();
    m_LanguageCode = json["language_code"].as<String>();
}
