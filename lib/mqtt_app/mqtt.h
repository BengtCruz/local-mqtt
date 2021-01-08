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

/**
 * @brief 
 * 
 * @param topic 
 * @param message 
 * @param length 
 */
void callback_mqtt(char *topic, byte *message, unsigned int length);

/**
 * @brief 
 * 
 */
void reconnect_mqtt();

/**
 * @brief Set the up mqtt object
 * 
 */
void setup_mqtt();

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool client_connected();

/**
 * @brief 
 * 
 */
void mqtt_loop();

/**
 * @brief 
 * 
 * @param variable 
 * @param value 
 */
void publish(const char *variable, char *value);
