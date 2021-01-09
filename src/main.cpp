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

/**
 * @brief Constants go here
 */
long lastMsg = 0;
char msg[50];
int value = 0;

/**
 * @brief Variable to publish
 */
float temperature = 0;
float humidity = 0;

/**
 * @brief Pins to use below
 */

void setup()
{
    Serial.begin(9600);

    setup_wifi();
    setup_mqtt();

    //pinMode(ledPin, OUTPUT);
}

void loop()
{
    if (!client_connected())
    {
        reconnect_mqtt();
    }

    client_loop();

    long now = millis();
    if (now - lastMsg > 5000)
    {
        lastMsg = now;

        // Temperature in Celsius in Processor in ECU
        temperature = temperatureRead();
        char tempString[8];
        dtostrf(temperature, 1, 2, tempString);
        Serial.print("Temperature: ");
        Serial.println(tempString);
        publish("esp32/temperature", tempString);

        //Humidity yet to be fixed
    }
}
