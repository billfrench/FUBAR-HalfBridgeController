import controlP5.*;

/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

ControlP5 cp5;
  int v1;

  int jjj = 0;

void setup() 
{
  //size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  
      size(800, 400);  
    noStroke();
    cp5 = new ControlP5(this);
    cp5.addSlider("v1")
       .setPosition(40, 40)
       .setSize(200, 20)
       .setRange(0, 1024)
       .setValue(250)
       .setColorCaptionLabel(color(20,20,20));
}

void draw()
{
while (myPort.available() > 0) {
    String inBuffer = myPort.readStringUntil(10);   
    if (inBuffer != null) {
      String[] list = split(inBuffer,'-');      
      int iii = int(list[0]);
      jjj++;
      if(jjj>1000)
      {
        jjj=0;
        cp5.getController("v1").setValue(iii);
      }
      //println(inBuffer);
      //println(list[0]);
    }
  }
}



/*

// Wiring / Arduino Code
// Code for sensing a switch status and writing the value to the serial port.

int switchPin = 4;                       // Switch connected to pin 4

void setup() {
  pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(9600);                    // Start serial communication at 9600 bps
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
    Serial.write(1);               // send 1 to Processing
  } else {                               // If the switch is not ON,
    Serial.write(0);               // send 0 to Processing
  }
  delay(100);                            // Wait 100 milliseconds
}

*/