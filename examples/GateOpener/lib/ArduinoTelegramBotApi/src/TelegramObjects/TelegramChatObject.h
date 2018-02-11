#pragma once
#include <ArduinoJson.h>
enum class ChatType {
    Private,
    Group,
    SuperGroup,
    Channel
};
class TelegramChatObject
{
public:
    TelegramChatObject(JsonObject& json);
    int m_Id;
    enum ChatType m_Type;
    String m_Title;
    String m_FirstName;
    String m_LastName;
    String m_UserName;
    bool m_AllMembersAreAdmin;
};
