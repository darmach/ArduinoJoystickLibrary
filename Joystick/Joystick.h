/*
  Joystick.h

  
  This is a modification done by Jakub Darmach of original Joystick.h 
  from https://github.com/MHeironimus/ArduinoJoystickLibrary by Matthew Heironimus.
  
  Axes have been modified to 10 bit range, accepting and delivering 1024 bits of precision.
  Rest of the features (buttons, hats and so on) were removed (commented out) as I want to 
  go step by step enabling them, learning about HID descriptor on the way.

  Original credits:
  Copyright (c) 2015, Matthew Heironimus

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef JOYSTICK_h
#define JOYSTICK_h

#include "HID.h"

#if ARDUINO < 10606
#error The Joystick library requires Arduino IDE 1.6.6 or greater. Please update your IDE.
#endif

#if !defined(USBCON)
#error The Joystick library can only be used with a USB MCU (e.g. Arduino Leonardo, Arduino Micro, etc.).
#endif

#if !defined(_USING_HID)

#warning "Using legacy HID core (non pluggable)"

#else
//================================================================================
//================================================================================
//  Joystick (Gamepad)

class Joystick_
{
private:
	bool     autoSendState;
	int16_t	 xAxis;
	int16_t	 yAxis;
	int16_t	 zAxis;
	int16_t	 xAxisRotation;
	int16_t	 yAxisRotation;
	int16_t	 zAxisRotation;
	uint32_t buttons;
	uint16_t  throttle;
	uint16_t  rudder;
	int16_t	 hatSwitch[2];
	

public:
	Joystick_();

	void begin(bool initAutoSendState = true);
	void end();

	void setXAxis(int16_t value);
	void setYAxis(int16_t value);
	void setZAxis(int16_t value);

	void setXAxisRotation(int16_t value);
	void setYAxisRotation(int16_t value);
	void setZAxisRotation(int16_t value);

	void setButton(uint8_t button, uint8_t value);
	void pressButton(uint8_t button);
	void releaseButton(uint8_t button);

	void setThrottle(uint16_t value);
	void setRudder(uint16_t value);

	void setHatSwitch(int8_t hatSwitch, int16_t value);

	void sendState();
};
extern Joystick_ Joystick;

#endif
#endif
