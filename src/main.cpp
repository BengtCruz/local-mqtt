/**
 * @file main.cpp
 * @author Bengt Cruz (bengtsvedling@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "mqtt.h"

#define VERY_HIGH 100

const char *ssid = "LosMamoies";
const char *password = "VagoVaguito04";

long lastMsg = 0;
char msg[50];
int value = 0;

float temperature = 0;
float humidity = 0;

void setup_wifi()
{
    delay(10);

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    wifi_driver_init(ssid, password);

    while (wifi_driver_status())
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void setup()
{
    Serial.begin(9600);
    setup_wifi();
    setup_mqtt();
}

void loop()
{
    if (!client_connected())
    {
        reconnect_mqtt();
    }

    long now = millis();
    if (now - lastMsg > 5000)
    {
        lastMsg = now;

        // Temperature in Celsius
        temperature = temperatureRead();
        // Uncomment the next line to set temperature in Fahrenheit
        // (and comment the previous temperature line)how to know the ip address of my computer ubuntu
        char tempString[8];
        dtostrf(temperature, 1, 2, tempString);
        Serial.print("Temperature: ");
        Serial.println(tempString);
        publish("esp32/temperature", tempString);
        /*
        humidity = bme.readHumidity();

        // Convert the value to a char array
        char humString[8];
        dtostrf(humidity, 1, 2, humString);
        Serial.print("Humidity: ");
        Serial.println(humString);
        client.publish("esp32/humidity", humString);*/
    }
}
