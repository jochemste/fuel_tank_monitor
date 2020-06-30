#include <LiquidCrystal.h>

const int tankPin = A0;

//const int gaugeLeds[5] = {1, 2, 3, 4, 5};
LiquidCrystal lcd(A1, A2, A3, A4, A5, A6);

int tankVal = 0; // between 0 and 1023, steps of 0.0049V
//const int stepV = 1023/(sizeof(gaugeLeds)/sizeof(int));

void setup() {
  // put your setup code here, to run once:
  //for(const auto& led : gaugeLeds){
  //  pinMode(led, OUTPUT);
  //}

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(0);
  lcd.print("%");
}

void loop() {
  // put your main code here, to run repeatedly:
  tankVal = analogRead(tankPin);
  float percentage = 5.0*((float)tankVal/1023.0);

  lcd.clear();
  lcd.print((int)percentage);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print(tankVal);

  delay(10000);
  
  //int ctr=0;
  //while(tankVal > stepV){
  //  tankVal-=stepV;
  //  digitalWrite(gaugeLeds[ctr++], HIGH);
  //}
  //while(ctr<(sizeof(gaugeLeds)/sizeof(int))){
  //  digitalWrite(gaugeLeds[ctr++], LOW);
  //}
}
