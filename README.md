ardunio_hid
===========

based on [Arduino Forum entry](http://forum.arduino.cc/index.php?topic=99.0).

Containting [HID Documentation](https://github.com/mkuerbis/ardunio_hid/blob/master/HID1_11.pdf?raw=true) for additional keycodes.

Here the original comment:
> When we send data to the keyboard driver, it has to be scancodes, not ascii characters. Refer to the AVR keyboard source code to obtain the scancodes. 
> Notes:
> - Modifiers (Shift, Alt, Ctrl) only modify the next character.
> - When sending modifiers, the byte that is sent must be the amount of shift (referenced in the source code) plus 0xf0.
> - Only one modifier can be used at a time.
> - Once a modifier is sent, it will remain on until one of two things happen: another byte is sent, or the same modifier is pressed on another keyboard connected to the system.
> - A delay of at least 25 milliseconds is required after each byte in order to gice the keyboard driver time to respond. A function to take care of this might be needed.
