/*

 Keyboard sketch
 by Andrew McDaniel
 
 Copyright (c) 2010 Andrew McDaniel
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

/*
When we send data to the keyboard driver, it has to be
 scancodes, not ascii characters. Refer to the AVR keyboard
 source code to obtain the scancodes. 
 Notes:
 -Modifiers (Shift, Alt, Ctrl) only modify the next character.
 -When sending modifiers, the byte that is sent must be the amount
 of shift (referenced in the source code) plus 0xf0.
 -Only one modifier can be used at a time.
 -Once a modifier is sent, it will remain on until one of two things
 happen: another byte is sent, or the same modifier is pressed on 
 another keyboard connected to the system.
 -A delay of at least 25 milliseconds is required after each byte in
 order to gice the keyboard driver time to respond. A function to 
 take care of this might be needed.
 */

// Letter keys
byte SC_A = 0x04;            
byte SC_B = 0x05;            
byte SC_C = 0x06;
byte SC_D = 0x07;
byte SC_E = 0x08;
byte SC_F = 0x09;
byte SC_G = 0x0a;
byte SC_H = 0x0b;
byte SC_I = 0x0c;
byte SC_J = 0x0d;
byte SC_K = 0x0e;
byte SC_L = 0x0f;
byte SC_M = 0x10;
byte SC_N = 0x11;
byte SC_O = 0x12;
byte SC_P = 0x13;
byte SC_Q = 0x14;
byte SC_R = 0x15;
byte SC_S = 0x16;
byte SC_T = 0x17;
byte SC_U = 0x18;
byte SC_V = 0x19;
byte SC_W = 0x1a;
byte SC_X = 0x1b;
byte SC_Y = 0x1c;
byte SC_Z = 0x1d;
// Controll keys
byte SC_ESCAPE = 0x29;
byte SC_TAB = 0x2b;
byte SC_BCKSPC = 0x2a;
byte SC_SPACE = 0x2c;
byte SC_ENTER = 0x28;
// Mod keys
byte MOD_CTRL = 0xf0;
byte MOD_ALT = 0xf2;
byte MOD_SHIFT = 0xf1;
// Function Keys

// Arrow keys
byte SC_UP_ARROW = 0x52;
byte SC_DOWN_ARROW = 0x51;
byte SC_LEFT_ARROW = 0x50;
byte SC_RIGHT_ARROW = 0xef;

void setup()
{
  delay(6000); //  Give the keyboard driver time to boot
  Serial.begin(9600);
}

void loop()
{
  sendSCByte(MOD_SHIFT);
  sendSCByte(SC_A);
  sendSCByte(SC_R);
  sendSCByte(SC_D);
  sendSCByte(SC_U);
  sendSCByte(SC_I);
  sendSCByte(SC_N);
  sendSCByte(SC_O);
  sendSCByte(SC_SPACE);
  sendSCString("This is being sent FROM THE ");
}

void sendSCByte(byte byteToSend)
{
  Serial.print(byteToSend);
  delay(25);
}

void sendSCString(String stringToSend)
{
  byte charByte;
  int lengthOfString = stringToSend.length();
  for ( int i = 0; i < lengthOfString; i++)
  {
    charByte = stringToSend.charAt(i);
    if(charByte >= 0x61 && charByte <= 0x7a)
      sendSCByte(charByte - 0x5d);
    else if(charByte >= 0x41 && charByte <= 0x5a)
    {
      sendSCByte(MOD_SHIFT);
      sendSCByte(charByte - 0x3d);
    }
    else if(charByte == 0x20)
      sendSCByte(SC_SPACE);
  }
}

