#include "UART.h" // Inkluderar header filen som innehåller definitioner

void USART2_Init(void) { // Funktionen som initialiserades USART-protkokollet med innehåll av viktiga egenskaper

// Ger uart2 klocktillgång
RCC->APB1ENR |= 0x20000; // Sätter bit 17 till 1 enligt registret för att aktivera klockan.

RCC->AHB1ENR |= 0x01; // Sätter bit 0 till 1 för att aktivera GPIOA, som är port A och förser den med klock tillgång

// Aktiverar 2 pins för att UART kommunikationen ska fungera
GPIOA->MODER &= ~0x00F0; // Rensar bitarna 4-7 för att förbereda pins PA2 och PA3
GPIOA->MODER |= 0x00A0; // Bitarna 5 och 7 sätts till 1 för att aktivera alternativ funktion på pins PA2 och PA3

// Val av vilken typ alternativa funktion som ska antas för pins 
GPIOA->AFR[0] &= ~0xFF00; // Rensar bitarna 8-15 för att förbereda pins PA2 och PA3
GPIOA->AFR[0] |= 0x7700; // Bitarna 8-11 samt 12-15 sätts till formatet 0111

/* Konstruktion av enhetens kommunikation avslutas */

// UART uppbyggnad
USART2->BRR = 0x0683; // Sätter baud rate til 9600 (hexadecimalt)
USART2->CR1 = 0x000C; // Sätter igång transmitter och reciever och jobbar med 8 bitars data
USART2->CR2 = 0x000; // Kontroll register 2 nollställs, används ej
USART2->CR3 = 0x000; // Kontroll register 3 nollställs
USART2->CR1 |= 0x2000; // Aktiverar UART genom att ändra bit 13 till 1 (enligt STM)

}
// Deklarerar UART skrivfunktion 
int USART2_write(int ch){ // Deklarerar skrivfunktionen (Överföringen av data till terminalen)

  while(!(USART2->SR & 0x0080)){} // Sätter vi ett krav som kontrollerar att statusen på överföringen är tom och kan ta emot nästa karaktär (byte)
  USART2->DR = (ch & 0xFF); // Sätter överföringen av byten till dataregistret

  return ch;

}

// Deklarerar UART läsfunktion som ska motta information
int USART2_read(void){ // Deklarerar läsfunktionen (mottagning av information)

  while(!(USART2->SR & 0x0020)){} // Sätter vi ett krav som kontrollerar om det finns mer data att hämta
  return USART2->DR; // Läser ut datan

}
