#include <VirtualWire.h>

int Left = 5;                   // Przycisk "W lewo" podłączony do pinu numer 5 
int Forward = 4;  
int Back = 3;  
int Right= 2;  
void setup()
{
       pinMode(Left,INPUT_PULLUP);        //Definicja przycisku left jako wejscie z podciagnieciem 
       pinMode(Forward,INPUT_PULLUP);
       pinMode(Back,INPUT_PULLUP);
       pinMode(Right,INPUT_PULLUP);
    vw_set_tx_pin(10);               // Nadajnik RF podłączony do pinu numer 10 
    vw_setup(8000);                  // Prędkość transmisji 
 
}
 
 
void loop()
{ 
  char L[1] = {'L'};            //Tablica 1 znakowa 
  char F[1] = {'F'};            
  char B[1] = {'B'};            
  char R[1] = {'R'};            
  char wyl[1] ={'0'};           

  
 if (digitalRead(Left) == LOW & digitalRead(Forward) == HIGH & digitalRead(Back) == HIGH & digitalRead(Right) == HIGH)       //jeżeli przycisk1 zostanie wciśnięty
  {
    vw_send((uint8_t *)L, 1);      //wysylamy w postaci znaków 8-bitowych zawartosc tablicy L o dł 1 
    vw_wait_tx();                  // poczekaj az cala zawartosc tablicy zostanie wyslana
  }

  if (digitalRead(Left) == HIGH & digitalRead(Forward) == LOW & digitalRead(Back) == HIGH & digitalRead(Right) == HIGH)    
  {

   vw_send((uint8_t *)F, 1);      
   vw_wait_tx();                   
  }
   
   if (digitalRead(Left) == HIGH & digitalRead(Forward) == HIGH & digitalRead(Back) == LOW & digitalRead(Right) == HIGH)    
  {
   vw_send((uint8_t *)B, 1);      
   vw_wait_tx();                   
  }
  
   if (digitalRead(Left) == HIGH & digitalRead(Forward) == HIGH & digitalRead(Back) == HIGH & digitalRead(Right) == LOW)    
  {
   vw_send((uint8_t *)R, 1);     
   vw_wait_tx();                   
   
  }
 if (digitalRead(Left) == HIGH & digitalRead(Forward) == HIGH & digitalRead(Back) == HIGH & digitalRead(Right) == HIGH)   
{
    vw_send((uint8_t *)wyl, 1);     
   vw_wait_tx();                   
   
}



  

}
