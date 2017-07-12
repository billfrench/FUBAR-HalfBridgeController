void setup() {

  pinMode(LOW_SIDE_OUT, OUTPUT);
  analogWrite(LOW_SIDE_OUT, 0);
  pinMode(HIGH_SIDE_OUT, OUTPUT);
  analogWrite(HIGH_SIDE_OUT, 0);

  Serial.begin(9600);
  Timer1.initialize(62);  // Run the PWM at ~16kHz ... this seems to be kinda normal

}
void loop() {

  FUSE_SHUNT_READING = analogRead(FUSE_IN_PIN);
  if (FUSE_SHUNT_READING > 630)
  {
    OUTPUT_PWM = 0;
    Timer1.pwm(LOW_SIDE_OUT, OUTPUT_PWM);  // Fuse is over amps, set PWM to zero
  }
  else
  {
    
    int ThrottleReading = analogRead(THROTTLE_IN_PIN);

    // the timerone library for some reason needs 0 to 1024 ... not 1023!
    ThrottleReading = map(ThrottleReading, 200, 800, 0, 1024);
    ThrottleReading = constrain(ThrottleReading, 0, 1024);

    OUTPUT_PWM = ThrottleLUT[ThrottleReading];  // this allows for an exponential throttle curve

    Timer1.pwm(LOW_SIDE_OUT, OUTPUT_PWM);
    
  }
  //    Serial.print(T);
  //    Serial.print("|");
  Serial.print(FUSE_SHUNT_READING);
  Serial.print("|");
  Serial.print(OUTPUT_PWM);
  Serial.print("X");
}

