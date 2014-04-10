int sensor1 = 4;    // analog in 4
int sensor2 = 5;    // analog in 5
                                                
int LED1 = 3;    // digital 3
int LED2 = 5;    // digital 5
                       
int readVal1;    // voltage value read from analogRead(sensor1)
int readVal2;    // voltage value read from analogRead(sensor2)

int light = 100;    // set light threshold

void setup(){
  Serial.begin(9600);    //  setup serial
  pinMode(LED1, OUTPUT);    //sets up digital 3 as output pin
  pinMode(LED2, OUTPUT);    //sets up digital 5 as output pin
}

void loop(){
  readVal1 = analogRead(sensor1);    // read voltage from sensor1
  readVal2 = analogRead(sensor2);    // read voltage from sensor2

  /* Voltage in readVal values are not actual voltages, but scaled voltages.
     The Arduino reads voltages from 0V to 5V and scales them to an integer
     value of 0 to 1024. The readVal values store these scaled integers. */
     
  if(readVal1 >= light){    // check if light
    digitalWrite(LED1, LOW);    // if light, turn off led
  }else{                      
    digitalWrite(LED1, HIGH);    // if dark, turn on led
  }
  
  if(readVal2 >= light){    // check if light
    digitalWrite(LED2, LOW);    // if light, turn off led
  }else{                      
    digitalWrite(LED2, HIGH);    // if dark, turn on led
  }
}
