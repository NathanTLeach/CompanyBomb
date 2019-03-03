const int switchBadLED  = 47; //LEDs to indicate if switches have been solved
const int switchGoodLED = 48;
const int greenSwitch   = 49;
const int blueSwitch    = 50;
const int redSwitch     = 51; //input ports of all switches 
const int yellowSwitch  = 52;
const int purpleSwitch  = 53;
boolean switches        = false;


void setup() {

  //initialize switch ports and inputs
  for(int i = greenSwitch; i <= purpleSwitch; i++){
    pinMode(i, INPUT);
  }
  
  //initialize LED ports as outputs
  pinMode(switchBadLED, OUTPUT);
  pinMode(switchGoodLED, OUTPUT);
  
  Serial.begin(9600); //for testing, delete later

}

void loop() {

  //boolean switches = switchCheck(greenSwitch, blueSwitch, redSwitch, yellowSwitch, purpleSwitch, switchBadLED, switchGoodLED, prevSwitchCheck);
  switches = switchCheck(greenSwitch, blueSwitch, redSwitch, yellowSwitch, purpleSwitch, switchBadLED, switchGoodLED, switches);

  
  Serial.println(switches); //for testing, delete later

}


/** Method to check if the switches have been solved
*   takes the input number of the switch ports and input number of LED ports
*   delays for a certain time to avoid random switching
*   returns boolean, whether puzzle has been solved
 */
boolean switchCheck(int green, int blue, int red, int yellow, int purple, int badLED, int goodLED, boolean lastCheck){

//Once condition has been met and delay has happened it keeps re-counting the delay which we don't want
//Need to make it so that count doesn't reset to zero if it has already counted up and only reset if
//switches are changed back to being in the wrong states

  boolean greenCheck   = digitalRead(green);
  boolean blueCheck    = digitalRead(blue);
  boolean redCheck     = digitalRead(red);      //Checks the states of all switches
  boolean yellowCheck  = digitalRead(yellow);
  boolean purpleCheck  = digitalRead(purple);
 
  boolean allGood = !greenCheck && blueCheck && redCheck && !yellowCheck && purpleCheck; //true if switches are in correct state
  //boolean delayDone = false;                    //was trying for some timing, questionable
  int count = 0;                                //was trying for some timeing, questionable
  //return(allGood);

  if(lastCheck && allGood){
    return true;   
  }else if(!lastCheck && allGood){
    return false;
  }else{
    return false;
  }





  
//  if(allGood){
//    
//    
//    while(allGood && count < 200){              //trying to figure out some delay here
//      count++;
//      delay(10);
//      //Serial.println(count);
//      if(count >= 200){
//        int count = 201;
//        return true;
//      }
//      }else{
//        delayDone = false;
//      }
//    }
//    
//  }else{
//    count = 0;                                  //another timing thing that may or may not work
//    return false;
//  }

//  if(delayDone){
//    return true;                              //was trying to do a timing thing
//  }else{
//    return false;
//  }
}











