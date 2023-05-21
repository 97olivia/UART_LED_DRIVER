#include "LED.h" // Inkludera heder fil led.h

// Konstruktor LED lampa
Led::Led(LedColor_Type _color, LedState_Type _state) 
{

  this->color = _color;
  this->state = _state;

  // Aktiverar klocka till LED-port(GPIOB)
  RCC->AHB1ENR |= LED_PORT_CLOCK;

  // Faställer LED färg samt status(on/off)
  switch(_color){

    case RED: // Bestämmer portens läge för LED på on/off
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      if(this->state == ON){
        // LED på
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        // LED av
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW: // Bestämmer portens läge för LED på on/off
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        // LED på
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        // LED av
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: // Bestämmer portens läge för LED på on/off
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        // LED på
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        // LED av
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN: // Bestämmer portens läge för LED på on/off
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        // LED på
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        // LED av
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;

  }


}

void Led::setState(LedState_Type _state){

  // Bestämmer stastus för LED
  this->state = _state;

  // Kontrolerar LED färg
  switch(this->color){

    case RED:
      // Pin till output mode
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      // Status är on
      if(this->state == ON){
        // Define till aktiv pin
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        // Define till inaktiv pin
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW:
      // Pin till output mode
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      // Status är on
      if(this->state == ON){
        // Define till aktiv pin
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        // Define till inaktiv pin
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE:
      // Pin till output mode
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      // Status är on
      if(this->state == ON){
        // Define till aktiv pin
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        // Define till inaktiv pin
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:
      // Pin till output mode
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      // Status är on
      if(this->state == ON){
        // Define till aktiv pin
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        // Define till inaktiv
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{

  // Kontrolerar statsus av LED färg
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             // Returnerar LED statusen samt färg
             return this->state;
}
