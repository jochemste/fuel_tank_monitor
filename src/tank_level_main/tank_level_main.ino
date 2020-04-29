
const int tankPin = A0;

const int gaugeLeds[5] = {1, 2, 3, 4, 5};

int tankVal = 0; // between 0 and 1023, steps of 0.0049V
const int stepV = 1023/(sizeof(gaugeLeds)/sizeof(int));

void setup() {
  // put your setup code here, to run once:
  for(const auto& led : gaugeLeds){
    pinMode(led, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  tankVal = analogRead(tankPin);
  int ctr=0;
  while(tankVal > stepV){
    tankVal-=stepV;
    digitalWrite(gaugeLeds[ctr++], HIGH);
  }
  while(ctr<(sizeof(gaugeLeds)/sizeof(int))){
    digitalWrite(gaugeLeds[ctr++], LOW);
  }
}
