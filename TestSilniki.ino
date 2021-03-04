#include <VirtualWire.h> // Wczytanie biblioteki 

#define RIGHT_MOTOR_PIN1 12    // Definowanie silnikiów na pinach 2,4,10,12
#define RIGHT_MOTOR_PIN2 10

#define LEFT_MOTOR_PIN1 4
#define LEFT_MOTOR_PIN2 2

int enA = 8;                   // Definicja wyjść Enable ze sterownika L293D
int enB =6;

void setup()
{
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);    //Ustawienie Silników jako wyjścia 
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);

  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
    vw_set_rx_pin(8);                        // odbiornik podłączamy do pinu 11
    vw_setup(8000);                          // ustawiamy transmisję danych
    vw_rx_start();                           // Rozpoczynamy odbiór danych
 
}
void loop()
{ 
    uint8_t buf[VW_MAX_MESSAGE_LEN];          //definicja buforu odbioru danych
    uint8_t buflen = VW_MAX_MESSAGE_LEN;      //definicja dlugości otrzymanych danych
    if (vw_get_message(buf, &buflen))         // jeżeli do buforu danych dotarły dane oraz transmisja została zakończona i długość danych nie przekracza 8-bitów
    {
      int i;                                  //utwórz zmienną i
      String dane;                            //utwórz zmienną string dane  
      for (i = 0; i < buflen; i++)            //jeżeli wartość i < 0 to odbieraj znaki
          {
         dane +=char(buf[i]);                 //do zmiennej string wprowadź wszystkie otrzymane znaki i je połącz
          }
          //Skręt w Lewo uruchomiony silnik prawy 
if(dane == "L")                             //jeżeli odebrane dane są równe L
      {
  digitalWrite(RIGHT_MOTOR_PIN1, HIGH);     //Na Pin 1 w silniku prawym napięcie wysokie na Pin 2 niskie 
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);

  digitalWrite(LEFT_MOTOR_PIN1, LOW);       //Na piny w silniku lewym stany niskie(silnik wyłączony) 
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
      }
         //Ruch do przodu oba silniki uruchomione 
if(dane == "F")                          
      {
  digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);

  digitalWrite(LEFT_MOTOR_PIN1, HIGH);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
      }
      //Ruch do tyłu oba silniki uruchomione 
if(dane == "B")                         
      {
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, HIGH);

  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, HIGH);
      }
           //Ruch w prawo lewy silnik uruchomiony 
if(dane == "R")                           
      {
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);

  digitalWrite(LEFT_MOTOR_PIN1, HIGH);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
      }
if( dane == "0"  )                           
     {
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);

 digitalWrite(LEFT_MOTOR_PIN1, LOW);       //Na piny w silniku lewym stany niskie(silnik wyłączony) 
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
      }
      }
    }
