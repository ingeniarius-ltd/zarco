/*
 * Copyright (c) 2015 Ingeniarius, Lda. All rights reserved. 
 */

#include <Wire.h>
int sonarID[16] = { 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
//int novoE[16] = { 0xE0, 0xE2, 0xE4, 0xE6, 0xE8, 0xEA, 0xEC, 0xEE, 0xF0, 0xF2, 0xF4, 0xF6, 0xF8, 0xFA, 0xFC, 0xFE};

void setup()
{
  Wire.begin();                // join i2c bus (address optional for master)
  Serial.begin(115200);          // start serial communication at 9600bps

  delay(500);
}

int reading = 0;

void loop()
{
  
  for(int index=0;index<16;index++){
    // step 1: instruct sensor to read echoes
    Wire.beginTransmission(sonarID[index]); // transmit to device #112 (0x70)
                                 // the address specified in the datasheet is 224 (0xE0)
                                 // but i2c adressing uses the high 7 bits so it's 112
    Wire.write(byte(0x00));      // sets register pointer to the command register (0x00)  
    Wire.write(byte(0x51));      // command sensor to measure in "inches" (0x50)
                                 // use 0x51 for centimeters
                                 // use 0x52 for ping microseconds
    Wire.endTransmission();      // stop transmitting
  
    // step 2: wait for readings to happen
    delay(70);                   // datasheet suggests at least 65 milliseconds
  
    // step 3: instruct sensor to return a particular echo reading
    Wire.beginTransmission(sonarID[index]); // transmit to device #112
    Wire.write(byte(0x02));      // sets register pointer to echo #1 register (0x02)
    Wire.endTransmission();      // stop transmitting
  
    // step 4: request reading from sensor
    Wire.requestFrom(sonarID[index], 2);    // request 2 bytes from slave device #112
  
    Serial.print("[");
    // step 5: receive reading from sensor
    if(2 <= Wire.available())    // if two bytes were received
    {
      reading = Wire.read();  // receive high byte (overwrites previous reading)
      reading = reading << 8;    // shift high byte to be high 8 bits
      reading |= Wire.read(); // receive low byte as lower 8 bits
      Serial.print(reading);   // print the reading
    }
    Serial.print("]");
  
    delay(200);                 
  }
  Serial.println("");
  delay(250);                  // wait a bit since people have to read the output :)
}




// The following code changes the address of a Devantech Ultrasonic Range Finder (SRF10 or SRF08)
// usage: changeAddress(0x70, 0xE6);

void changeAddress(byte oldAddress, byte newAddress)
{
  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));
  Wire.write(byte(0xA0));
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));
  Wire.write(byte(0xAA));
  Wire.endTransmission();
  delay(50);
  
  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));
  Wire.write(byte(0xA5));
  Wire.endTransmission();
  delay(50);

  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));
  Wire.write(newAddress);
  Wire.endTransmission();
  delay(50);
}


