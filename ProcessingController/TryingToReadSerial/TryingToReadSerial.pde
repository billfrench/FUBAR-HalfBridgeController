import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

PrintWriter output;

int jjj = 0;

long startTime = 0;

void setup() 
{
  printArray(Serial.list());

  String portName = Serial.list()[4];
  myPort = new Serial(this, portName, 9600);

  size(800, 400);
  output = createWriter("output.log");
}

String mystring = "";

void draw()
{
  println("Draw...");
  startTime = System.nanoTime();
  while (jjj < 500)
  {
    while (myPort.available() > 0 && jjj < 500) {


      int inByte = myPort.read();
      
      char c = char(inByte);
      
      println(c);

      if(c != 'X')
      {
        mystring = mystring + c;
      }
      else
      {
        println(mystring);
        mystring = "";
        jjj++;
        print("jjj:");
        println(jjj);
      }

      //String inBuffer = myPort.readStringUntil('X');   
      //if (inBuffer != null) {
      //  println(inBuffer);
      //  String[] list = split(inBuffer, '|'); 
      //  if (list.length == 2)
      //  {
      //    //output.print(inBuffer);
      //    //println(inBuffer);
      //    //background(255);
      //    //fill(0);
      //    //text(iii, 10, 10);
      //    //println(inBuffer);
      //    //println(list[1]);
          //jjj++;
          //println(jjj);
      //  }
      //}
    }
  }
  println("Done.");
  println((System.nanoTime() - startTime)/500);
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  exit(); // Stops the program
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