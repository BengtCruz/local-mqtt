#include <mqtt.h>

WiFiClient espClient;
PubSubClient client(espClient);
const char *mqtt_server = "192.168.43.71";

void mqtt_loop()
{
    client.loop();
}

void callback_mqtt(char *topic, byte *message, unsigned int length)
{
    Serial.print("Message arrived on topic: ");
    Serial.print(topic);
    Serial.print(". Message: ");
    String messageTemp;

    for (int i = 0; i < length; i++)
    {
        Serial.print((char)message[i]);
        messageTemp += (char)message[i];
    }
    Serial.println();

    // Feel free to add more if statements to control more GPIOs with MQTT

    // If a message is received on the topic esp32/output, you check if the message is either "on" or "off".
    // Changes the output state according to the message
    if (String(topic) == "esp32/output")
    {
        Serial.print("Changing output to ");
        if (messageTemp == "on")
        {
            Serial.println("on");
            analogWrite(BUILTIN_LED, HIGH);
        }
        else if (messageTemp == "off")
        {
            Serial.println("off");
            analogWrite(BUILTIN_LED, LOW);
        }
    }
}

void setup_mqtt()
{
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback_mqtt);
}
void reconnect_mqtt()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect("ESP8266Client"))
        {
            Serial.println("connected");
            // Subscribe
            client.subscribe("esp32/output");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

bool client_connected()
{
    return client.connected();
}

void publish(const char *variable, char *value)
{
    client.publish(variable, value);
}