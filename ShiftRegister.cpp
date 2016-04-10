/* Copyright 2016 Jason Evans */

#include <Arduino.h>
#include <ShiftRegister.h>

ShiftRegister::ShiftRegister(int latch, int clock, int data) : latchPin(latch), clockPin(clock), dataPin(data) {
    pinMode(latchPin, OUTPUT);  // Pin connected to ST_CP of 74HC595
    pinMode(clockPin, OUTPUT);  // Pin connected to SH_CP of 74HC595
    pinMode(dataPin, OUTPUT);  // Pin connected to DS of 74HC595
}

ShiftRegister::~ShiftRegister() {}

/**
 * [ShiftRegister::shiftWrite description]
 * @param number [description]
 */
void ShiftRegister::shiftWrite(byte data) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, data);
    digitalWrite(latchPin, HIGH);
}

/**
 * This function lets you make the shift register outputs HIGH or LOW in exactly
 * the same way that you use digitalWrite().
 *
 * Like digitalWrite(), this function takes two parameters:
 *    "desiredPin" is the shift register output pin you want to affect (0-7)
 *    "desiredState" is whether you want that output to be HIGH or LOW
 *
 * Inside the Arduino, numbers are stored as arrays of "bits", each of which is
 * a single 1 or 0 value. Because a "byte" type is also eight bits, we'll use a
 * byte (which we named "data" at the top of this sketch) to send data to the
 * shift register. If a bit in the byte is "1", the output will be HIGH. If the
 * bit is "0", the output will be LOW.
 *
 * To turn the individual bits in "data" on and off, we'll use a new Arduino
 * commands called bitWrite(), which can make individual bits in a number 1 or 0.
 *
 * @param desiredPin   the shift register output pin you want to affect (0-7)
 * @param desiredState is whether you want that output to be HIGH or LOW
 */
void ShiftRegister::shiftWrite(int desiredPin, boolean desiredState) {
    bitWrite(data, desiredPin, desiredState);
    shiftWrite(data);
}
