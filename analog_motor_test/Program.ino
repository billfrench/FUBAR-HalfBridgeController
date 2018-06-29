void setup() {

  pinMode(LOW_SIDE_OUT, OUTPUT);
  analogWrite(LOW_SIDE_OUT, 0);
  pinMode(HIGH_SIDE_OUT, OUTPUT);
  analogWrite(HIGH_SIDE_OUT, 0);

  Serial.begin(9600);
  Timer1.initialize(62);  // Run the PWM at ~16kHz ... this seems to be kinda normal

  Serial.println("LETS|GOX");
  Serial.println(AMP_CUTOUT);

}

int ThrottleReading = 0;
void loop() {

  FUSE_SHUNT_READING = analogRead(FUSE_IN_PIN);
  if (FUSE_SHUNT_READING < AMP_CUTOUT)
  {
    Timer1.pwm(LOW_SIDE_OUT, CUTOUT_PWM);  // Fuse is over amps, set PWM to CUTOUT_PWM (used to be zero, but now a definable constant, to help keep the motor energized a bit.
    
  }
  else
  {

    ThrottleReading = analogRead(THROTTLE_IN_PIN);

    // the timerone library for some reason needs 0 to 1024 ... not 1023!
    // issue filed: https://github.com/PaulStoffregen/TimerOne/issues/19
    ThrottleReading = map(ThrottleReading, 200, 800, 0, 1024);  //Throttle reads from about 200-800 for zero to full throttle
    ThrottleReading = constrain(ThrottleReading, 0, 1024);

    OUTPUT_PWM = ThrottleLUT[ThrottleReading];  // this lookup table allows for an exponential throttle curve
    Timer1.pwm(LOW_SIDE_OUT, OUTPUT_PWM);

  }
////    Serial.print(ThrottleReading);
////    Serial.print(",");
// Serial.print(FUSE_SHUNT_READING);
//   Serial.print(",");
//    Serial.println(OUTPUT_PWM);
//    if (OUTPUT_PWM == 50)
//    {
//      Serial.println("********");
//    }
////    Serial.print("X");
}

