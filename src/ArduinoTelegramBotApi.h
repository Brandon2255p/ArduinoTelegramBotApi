#pragma once

#include <ArduinoJson.h>
#include <Arduino.h>
#define USE_SERIAL Serial
#include "TelegramUpdateObject.h"

class ArduinoTelegramBotApi {

};


void ParseUpdate(String payload)
{
    StaticJsonBuffer<800> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(payload, 6);
    if (!root.success()) {
        USE_SERIAL.println("Nooo - Failed to parse:");
        USE_SERIAL.println(payload);
    }
    USE_SERIAL.println("Parsed Object:");
    root.prettyPrintTo(USE_SERIAL);
    JsonArray& resultsArray = root["result"];
    for(JsonVariant& updateJson : resultsArray)
    {
        TelegramUpdateObject update = TelegramUpdateObject(updateJson.asObject());

        USE_SERIAL.print("update id ");
        USE_SERIAL.println(update.m_UpdateId);
        USE_SERIAL.print("message id ");
        USE_SERIAL.println(update.m_Message.m_MessageId);
        USE_SERIAL.print("Date ");
        USE_SERIAL.println(update.m_Message.m_Date);
        USE_SERIAL.print("User: ");
        USE_SERIAL.println(update.m_Message.m_Chat.m_FirstName);
        USE_SERIAL.print("Chat type: ");
        USE_SERIAL.println((int)update.m_Message.m_Chat.m_Type);
    }
}
