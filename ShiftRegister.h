// Copyright 2016 Jason Evans

#ifndef ShiftRegister_h
#define ShiftRegister_h

#include <Arduino.h>

class ShiftRegister {

    public:
        ShiftRegister(int latch = 5, int clock = 3, int data = 6);
        ~ShiftRegister();
        void shiftWrite(byte);
        void shiftWrite(int, boolean);

        int getLatchPin() { return latchPin; }
        int getClockPin() { return clockPin; }
        int getDataPin() { return dataPin; }

        byte getData() { return data; }
        void setData(byte data) { data = data; }

    private:
        int latchPin;
        int clockPin;
        int dataPin;
        byte data;
};

#endif
