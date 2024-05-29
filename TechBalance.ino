#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int k;
unsigned int horas = 0;
unsigned int minutos = 0;
unsigned int segundos = 0;
unsigned int centesimos =0;
unsigned int milisegundos;
int reset = A1;
int inicio = A0;
int pausa = A2;
int ledRojo= 9;


void setup(){
  pinMode(pausa,INPUT);
  pinMode(reset, INPUT);
  pinMode(inicio, INPUT);
  lcd.begin(16,2);
  lcd.setCursor(3,0);
  lcd.print("CRONOMETRO");
}

void loop(){
  if (digitalRead(reset) == LOW){
  	k=0;
  }
  if (digitalRead(pausa) == LOW){
  	k=1;
  }
  if (digitalRead(inicio) == LOW){
  	k=2;
  }
  switch (k) {
    case 0:
      horas = 0;
      minutos = 0;
      segundos = 0;
      apagarLed();
    case 1:
    	delay (40);
   		apagarLed();
    case 2:
    	cronometro();
    	encenderLed();
  }}

void cronometro(){
  milisegundos = millis ();
  if(milisegundos % 10 == 0){
  centesimos++;
  if(centesimos == 100){
  centesimos = 0;
  segundos++;
  }
  if(segundos == 60){
  segundos = 0;
  minutos++;
  }
  if(minutos == 60){
  minutos = 0;
  horas++;
  }
  lcd.setCursor(4,1);
  if(horas < 10){
  lcd.print("0");
  }
  lcd.print(horas);
  lcd.print(":");
  lcd.setCursor(7,1);
  if(minutos < 10){
  lcd.print("0");
  }
  lcd.print(minutos);
  lcd.print(":");
  lcd.setCursor(10,1);
  if(segundos < 10){
  lcd.print("0");
  }
  lcd.print(segundos);
  }}

void encenderLed(){
	if(digitalRead(inicio)== LOW){
    digitalWrite(ledRojo,HIGH);
  }}

void apagarLed(){
	if(digitalRead(reset)== LOW){
    digitalWrite(ledRojo,LOW);
    }
  if(digitalRead(pausa)== LOW){
    digitalWrite(ledRojo,LOW);
  }}