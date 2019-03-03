const int keyIn = 22;


void setup() {
  pinMode(keyIn, INPUT);

  Serial.begin(9600);
}

void loop() {
  
  Serial.println(keyCheck(keyIn));

}


//Tests if all keys are turned------------------------------------------
//Returns true if all are turned, false if not-------------------------
boolean keyCheck(int inputCheck){
  boolean test = digitalRead(inputCheck);
  if(test == HIGH){
    return true;
  }else{
    return false;
  }
}


