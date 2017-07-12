import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class TryingToReadSerial extends PApplet {



Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

int jjj = 0;

public void setup() 
{
  printArray(Serial.list());
  
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);

  
}

public void draw()
{
  while (myPort.available() > 0) {
    String inBuffer = myPort.readStringUntil(10);   
    if (inBuffer != null) {
      String[] list = split(inBuffer, '-');      
      int iii = PApplet.parseInt(list[0]);

      //background(255);
      //fill(0);
      //text(iii, 10, 10);
      //println(inBuffer);
      println(list[1]);
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
  public void settings() {  size(800, 400); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "TryingToReadSerial" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
