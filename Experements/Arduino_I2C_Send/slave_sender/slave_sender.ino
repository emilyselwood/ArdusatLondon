// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
int led = 13;
void setup()
{
  Serial.begin(9600);
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onRequest(requestEvent); // register event
}

void loop()
{
  digitalWrite(led, HIGH);
  Serial.print("heart");
  delay(250);
  digitalWrite(led, LOW);
  Serial.print(" beat\n");
  delay(250);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  
  Wire.write("hello world"); // respond with message of 6 bytes
                       // as expected by master
  Serial.print("!!!!!!!!!!!!!! Event !!!!!!!!!!\n");
}
