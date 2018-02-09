#include "TelegramChatObject.h"

TelegramChatObject::TelegramChatObject(JsonObject& json) :
    m_Id(json["id"]),
    m_AllMembersAreAdmin(json["all_members_are_administrators"])
{
    m_Title = json["title"].as<String>();
    m_FirstName = json["first_name"].as<String>();
    m_LastName = json["last_name"].as<String>();
    m_UserName= json["username"].as<String>();
    String chatType = json["type"];
    if(chatType.equals("private"))
        m_Type = ChatType::Private;
    if(chatType.equals("channel"))
        m_Type = ChatType::Channel;
    if(chatType.equals("group"))
        m_Type = ChatType::Group;
    if(chatType.equals("supergroup"))
        m_Type = ChatType::SuperGroup;
}
