#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "UART.h"
#include "stm32f4xx.h" // Heder fil med källkod samt anvisningar för STM projekt

// Define rätt GPIO som ansvarar för LED-funktionen
#define LED_PORT GPIOB

// Define klocksignalen
#define LED_PORT_CLOCK (1U<<1)

// Define olika pins beronde på vilken färg som används för angiven pin
#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

// Define varje mode bits till LED-färgerna
#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

// Anger dem olika LED-färgernas existens
typedef enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

// Bestämmer LED-frägens off/on till 0/1
typedef enum {
  OFF = 0,
  ON = 1
}LedState_Type;

// Class med atributer som behövs för LED skall fungera korrekt 
class Led{

  private:
      LedColor_Type color;
      LedState_Type state;

  public:

      Led(LedColor_Type _color,LedState_Type _state);
      void setState(LedState_Type _state);
      LedState_Type getState() const;

};

#endif