#pragma once
#include <ArduinoJson.h>

#include "TelegramUserObject.h"
//#include "TelegramLocationObject.h"

class TelegramInlineQueryObject
{
public:
    TelegramInlineQueryObject(JsonObject& json);
    String m_Id;
    TelegramUserObject	m_From;
//  TelegramLocationObject	m_Location;	Optional. Sender location, only for bots that request user location
    String m_Query;//	String	Text of the query (up to 512 characters)
    String m_Offset;//	String	Offset of the results to be returned, can be controlled by the bot
};
