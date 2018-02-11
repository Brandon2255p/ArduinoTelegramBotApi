#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

#include "TelegramMethods/TelegramSendMessage.h"
#include "TelegramMethods/TelegramGetUpdates.h"

#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;
bool NotifyReset = true;
bool SignalOpenGate = false;
bool SignalOpenDoor = false;
long UpdateId = 0;

long mainUserid = ;
String token = ;
const char* ssid =
const char* password = ;

int GatePin = 14;
int DoorPin = 12;

void setup() {
    pinMode(GatePin, OUTPUT);
    pinMode(DoorPin, OUTPUT);
    digitalWrite(GatePin, LOW);
    digitalWrite(DoorPin, LOW);

    ConnectionBase::SetToken(token);
    USE_SERIAL.begin(115200);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1500);
    }

    WiFi.mode(WIFI_STA);
    WiFiMulti.addAP(ssid, password);

}

void HandleUpdate(String &jsonResult)
{
    USE_SERIAL.println("Got UPDATE!");
    USE_SERIAL.println(ESP.getFreeHeap());
    StaticJsonBuffer<800> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(jsonResult, 5);
    if (!root.success()) {
        USE_SERIAL.println("Nooo - Failed to parse:");
        return;
    }
    USE_SERIAL.println("Parsed Object:");
    JsonArray& resultsArray = root["result"];
    for(JsonVariant& updateJson : resultsArray)
    {
        TelegramUpdateObject update = TelegramUpdateObject(updateJson.asObject());
        USE_SERIAL.print("Current update id = ");
        USE_SERIAL.println(update.m_UpdateId);
        UpdateId = update.m_UpdateId + 1;
        USE_SERIAL.println(update.m_Message.m_Text);
        if(update.m_Message.m_Text.equals("Open Gate"))
        {
            SignalOpenGate = true;
        }
        if(update.m_Message.m_Text.equals("Open Door"))
        {
            SignalOpenDoor = true;
        }
    }
}

String SendKeyboard()
{
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    JsonArray& keyboard = root.createNestedArray("keyboard");
    JsonArray& row1 = keyboard.createNestedArray();
    row1.add("Open Gate");
    row1.add("Open Door");
    row1.add("Help");
    String result;
    root.printTo(result);
    return result;
}

void OpenGate()
{
    yield();
    digitalWrite(GatePin, HIGH);
    delay(1000);
    digitalWrite(GatePin, LOW);
}

void OpenDoor()
{
    yield();
    digitalWrite(DoorPin, HIGH);
    delay(1000);
    digitalWrite(DoorPin, LOW);
}

void loop() {
    if((WiFiMulti.run() == WL_CONNECTED)) {
        if(NotifyReset)
        {
            NotifyReset = false;
            TelegramSendMessage::Builder().SetChatId(mainUserid).SetReplyMarkup(SendKeyboard()).SetText( "I'm online. Last reset = " + ESP.getResetReason()).SendMessage();
        }
        if(SignalOpenDoor)
        {
            SignalOpenDoor = false;
            TelegramSendMessage::Builder().SetChatId(mainUserid).SetText("Opening the door, master").SendMessage();
            OpenGate();
        }
        if(SignalOpenGate)
        {
            SignalOpenGate = false;
            TelegramSendMessage::Builder().SetChatId(mainUserid).SetText("Opening the gate, master").SendMessage();
            OpenDoor();
        }
        TelegramGetUpdates::Builder().SetOffset(UpdateId).SetTimeout(10).SetLimit(1).RegisterResponseHandler(std::bind(HandleUpdate, std::placeholders::_1)).GetUpdates();
    }
}
