#include <TimerOne.h>

int LOW_OUT = 14;
int HIGH_OUT = 15;
int FULLGO = 200;
int KINDAGO = 200;
int STOP = 255;
int THROTTLE_IN_PIN = 21;

// 200 to 800


void setup() {
  // put your setup code here, to run once:  
  
  pinMode(LOW_OUT,OUTPUT);
  analogWrite(LOW_OUT,STOP);
  pinMode(HIGH_OUT,OUTPUT);
  digitalWrite(HIGH_OUT, HIGH);
  //analogWrite(HIGH_OUT,255);
  Serial.begin(9600);
  Timer1.initialize(62);
}

void loop() {
  // put your main code here, to run repeatedly:
  int T = analogRead(THROTTLE_IN_PIN);
  int TMapped = map(T,200,800,1024,0);

  int TFinal = constrain(TMapped,0,1024);
  
  Serial.print(T);
  Serial.print("-");
  Serial.println(TFinal);

  Timer1.pwm(LOW_OUT,TFinal);

}
