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
int pinDHT11 = 27;
SimpleDHT11 dht11(pinDHT11);
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

        int err = dht11.read2(&temperature, &humidity, NULL);

        //Char pointer (strings) for storage.
        char tempString[8];
        char humdString[8];

        //Temperature print out and publish
        dtostrf(temperature, 1, 2, tempString);
        Serial.print("Temperature: ");
        Serial.println(tempString);
        publish("esp32/temperature", tempString);

        //HUmidity print out and publish
        dtostrf(humidity, 1, 2, humdString);
        Serial.print("Humidity: ");
        Serial.println(humdString);
        publish("esp32/humidity", humdString);
    }
}
