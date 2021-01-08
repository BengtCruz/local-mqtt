/**
 * @file mqtt.h
 * @author Bengt Svedling (bengtsvedling@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Arduino.h>
#include <wifi_driver.h>
#include <PubSubClient.h>
#include <analogWrite.h>

void callback_mqtt(char *topic, byte *message, unsigned int length);

void reconnect_mqtt();

void setup_mqtt();

bool client_connected();

void mqtt_loop();

void publish(const char *location, char *value);
