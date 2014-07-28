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
// Letter keys
const byte SC_A = 0x04;            
const byte SC_B = 0x05;            
const byte SC_C = 0x06;
const byte SC_D = 0x07;
const byte SC_E = 0x08;
const byte SC_F = 0x09;
const byte SC_G = 0x0a;
const byte SC_H = 0x0b;
const byte SC_I = 0x0c;
const byte SC_J = 0x0d;
const byte SC_K = 0x0e;
const byte SC_L = 0x0f;
const byte SC_M = 0x10;
const byte SC_N = 0x11;
const byte SC_O = 0x12;
const byte SC_P = 0x13;
const byte SC_Q = 0x14;
const byte SC_R = 0x15;
const byte SC_S = 0x16;
const byte SC_T = 0x17;
const byte SC_U = 0x18;
const byte SC_V = 0x19;
const byte SC_W = 0x1a;
const byte SC_X = 0x1b;
const byte SC_Y = 0x1c;
const byte SC_Z = 0x1d;
// Controll keys
const byte SC_ESCAPE = 0x29;
const byte SC_TAB = 0x2b;
const byte SC_BCKSPC = 0x2a;
const byte SC_SPACE = 0x2c;
const byte SC_ENTER = 0x28;
// Mod keys
const byte MOD_CTRL = 0xf0;
const byte MOD_ALT = 0xf2;
const byte MOD_SHIFT = 0xf1;
// Function Keys
const byte SC_F1 = 0x3a;
const byte SC_F2 = 0x3b;
const byte SC_F3 = 0x3c;
const byte SC_F4 = 0x3d;
const byte SC_F5 = 0x3e;
const byte SC_F6 = 0x3f;
const byte SC_F7 = 0x40;
const byte SC_F8 = 0x41;
const byte SC_F9 = 0x42;
const byte SC_F10 = 0x43;
const byte SC_F11 = 0x44;
const byte SC_F12 = 0x45;
// Arrow keys
const byte SC_UP_ARROW = 0x52;
const byte SC_DOWN_ARROW = 0x51;
const byte SC_LEFT_ARROW = 0x50;
const byte SC_RIGHT_ARROW = 0xef;

void setup()
{
  delay(6000); //  Give the keyboard driver time to boot
  Serial.begin(9600);
}

void loop()
{
  // example code
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

