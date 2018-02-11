#include "TelegramUpdateObject.h"

TelegramUpdateObject::TelegramUpdateObject(JsonObject& updateObject) :
    m_UpdateId(updateObject["update_id"]),
    m_Message(updateObject["message"].asObject()),
    m_EditedMessage(updateObject["edited_message"].asObject()),
    m_ChannelPost(updateObject["channel_post"].asObject()),
    m_EditedChannelPost(updateObject["edited_channel_post"].asObject()),
    m_InlineQuery(updateObject["inline_query"].asObject()),
    m_CallbackQuery(updateObject["callback_query"].asObject())
{
    //m_Message = TelegramMessageObject(updateObject["message"]);
}
