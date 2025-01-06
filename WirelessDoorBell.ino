#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#define OLED_RESET -1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int buzzer=7;
int pir=4;

char Incoming_value = 0;
int counter=0;  
void setup() 
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
   }
    display.clearDisplay();
     display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  Serial.begin(9600);         
  pinMode(buzzer, OUTPUT);       
}

void loop()
{
  int sensorReading=digitalRead(pir);
  if (sensorReading==HIGH) {
     display.setCursor(0,0);
      display.clearDisplay();
      display.println("Welcome!");
        display.display();
  
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    if(Incoming_value == '1')             
      {
        digitalWrite(buzzer, HIGH);  
      counter++;
        display.clearDisplay();
      display.println("Visitor: ");
      display.println(counter);
       }
    else if(Incoming_value == '0')       
      digitalWrite(buzzer, LOW);   
  }     
  }                       
}
