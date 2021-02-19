//Programa: Teste de Display LCD 16 x 2 com sensor de temperatura
//Autor: Flemeg Amorim
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Temperatura
#include <OneWire.h>
#include <DallasTemperature.h>

const int SENSOR_PIN = 13;

OneWire oneWire(SENSOR_PIN);          
DallasTemperature sensors(&oneWire);  
 
//Define os pinos que serão utilizados no display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float tempCelsius;    
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  Serial.begin(9600); 
  sensors.begin();    
}
 
void loop()
{
  sensors.requestTemperatures();             
  tempCelsius = sensors.getTempCByIndex(0);
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("GELADA MI AMIGO");
  lcd.setCursor(3, 1);
  lcd.print(String(tempCelsius) + "C");
  delay(1000);
   
  //Rolagem para a esquerda
  for (int posicao = 0; posicao < 3; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
   
  //Rolagem para a direita
  for (int posicao = 0; posicao < 6; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
}
