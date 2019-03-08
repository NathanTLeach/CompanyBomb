#define blueIn      A8
#define whiteIn     A9
#define redIn       A10
#define cordLEDGood 22
#define cordLEDBad  23

void setup() {

pinMode(blueIn, INPUT);
pinMode(whiteIn, INPUT);
pinMode(redIn, INPUT);
pinMode(cordLEDGood, OUTPUT);
pinMode(cordLEDBad, OUTPUT);
Serial.begin(9600);

}

void loop() {
  cords();

}

boolean cords(){

  int blueLevel = analogRead(blueIn);
  int whiteLevel = analogRead(whiteIn);
  int redLevel = analogRead(redIn);

  if((blueLevel > 120 && blueLevel < 130) && 
     (whiteLevel > 380 && whiteLevel < 390) && 
     (redLevel >1020 && redLevel < 1028)){
      digitalWrite(cordLEDGood, HIGH);
      digitalWrite(cordLEDBad, LOW);
      return true;
     }else{
      digitalWrite(cordLEDGood, LOW);
      digitalWrite(cordLEDBad, HIGH);
      return false;
     }

  
}

