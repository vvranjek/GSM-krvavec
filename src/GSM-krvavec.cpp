// Do not remove the include below
#include "GSM-krvavec.h"

#include <GPRS_Shield_Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#define PIN_TX    7
#define PIN_RX    8
#define RADIATOR_PIN PIN2
#define BAUDRATE  9600

#define MESSAGE_LENGTH 160
char message[MESSAGE_LENGTH];
int messageIndex = 0;

char phone[16];
char datetime[24];

char radiator[] = "RADIATOR";

GPRS gprs(PIN_TX,PIN_RX,BAUDRATE);//RX,TX,PWR,BaudRate

void setup() {

    pinMode(RADIATOR_PIN, OUTPUT);
    digitalWrite(RADIATOR_PIN, LOW);

    gprs.checkPowerUp();
    Serial.begin(57600);
    while(!gprs.init()) {
        Serial.print("init error\r\n");
        delay(1000);
    }
    delay(3000);
    Serial.println("Init Success, please send SMS message to me!");
}

void loop() {
    messageIndex = gprs.isSMSunread();
    if (messageIndex > 0) { //At least, there is one UNREAD SMS
        gprs.readSMS(messageIndex, message, MESSAGE_LENGTH, phone, datetime);
        //In order not to full SIM Memory, is better to delete it
        gprs.deleteSMS(messageIndex);
        Serial.print("From number: ");
        Serial.println(phone);
        Serial.print("Datetime: ");
        Serial.println(datetime);
        Serial.print("Recieved Message: ");
        Serial.println(message);

        const char * radiator_ptr = strcasestr(message, radiator);
        if(radiator != NULL) {
            if (strcasestr(radiator_ptr+sizeof(radiator), "ON")) {
                digitalWrite(RADIATOR_PIN, HIGH);
                gprs.sendSMS(phone, (char*)"Radiator ON - OK!");
            }

            else if (strcasestr(radiator_ptr+sizeof(radiator), "OFF")) {
                digitalWrite(RADIATOR_PIN, LOW);
                gprs.sendSMS(phone, (char*)"Radiator ON - OK!");
            }

            else if (strcasestr(radiator_ptr+sizeof(radiator), "STATE")) {
                if (digitalRead(RADIATOR_PIN)) {
                    gprs.sendSMS(phone, (char*)"Radiator ON");
                }
                else {
                    gprs.sendSMS(phone, (char*)"Radiator OFF");
                }
            }
            else if (strcasestr(radiator_ptr+sizeof(radiator), "CHECK")) {
                if (digitalRead(RADIATOR_PIN)) {
                    gprs.sendSMS(phone, (char*)"Radiator ON");
                }
                else {
                    gprs.sendSMS(phone, (char*)"Radiator OFF");
                }
            }

            else {

            }
        }
    }
}
