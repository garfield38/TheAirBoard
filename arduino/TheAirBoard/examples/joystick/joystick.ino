/*
Brushbot/Airship proportional control program
- download the Android app: http://remotexy.com/en/download/
- order and populate the dual motor drive PCB for brushbot: https://oshpark.com/shared_projects/fyhMVHcY
- or directly connect micro motors to PINs 10/11 and GND for airship
- use smartphone internal G-sensor to pilot robot

The AirBoard is a thumb-size, Arduino-compatible, wireless,
ubiquitous computer designed to sketch Internet-of-Things, fast!

Visit http://www.theairboard.cc

Check readme.txt and license.txt for more information.
All text above must be included in any redistribution.
*/

#define REMOTEXY_MODE__SOFTWARESERIAL
#define REMOTEXY_SERIAL_RX 0
#define REMOTEXY_SERIAL_TX 1
#define REMOTEXY_SERIAL_SPEED 9600
#define LEFT  10
#define RIGHT 11

#include <TheAirBoard_pinout.h>
#include <SoftwareSerial.h>
#include <RemoteXY.h>

unsigned char RemoteXY_CONF[] =
  { 2,0,9,0,1,5,5,9,25,11
  ,49,49,2 }; 

struct {
  signed char joystick_1_x; /* =-100..100 x-coordinate joystick position */
  signed char joystick_1_y; /* =-100..100 y-coordinate joystick position */
  unsigned char connect_flag;
} RemoteXY;

void setup() {
  analogWrite(RIGHT, 0);
  analogWrite(LEFT, 0);
  RemoteXY_Init(); 
}

void loop() { 
  RemoteXY_Handler();
  analogWrite(RIGHT, map(RemoteXY.joystick_1_x, -100, 100, 0, 255));
  analogWrite(LEFT, map(RemoteXY.joystick_1_y, -100, 100, 0, 255));
}