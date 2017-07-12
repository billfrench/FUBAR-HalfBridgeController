import processing.serial.*;

Serial myPort;  // The serial port

long startTime = 0;
long lastTime = 0;
long xcount = 0;
long ccount = 0;
String aline = "";
PrintWriter output;

long linestoread = 1000;

void setup() {
  // List all the available serial ports
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[4], 9600);

  println("creating writer...");
  output = createWriter("output.log");
  startTime = System.nanoTime();
  //println(startTime);

  while (xcount <= linestoread) {
    //print(xcount);
    print("");
    while (myPort.available() > 0 ) {
      int inByte = myPort.read();

      char c = char(inByte);
      //print(c);


      if (inByte=='X')
      {
        dealwithstring(aline);
        aline="";
        //println("LINE");
      } else
      {
        //println("C");
        ccount++;
        aline += c;
      }

      //print(c);
    }
  }
  cleanup();
  exit();
}



//void draw() {
//}  

void dealwithstring(String s) {
  //println(s);
  output.print(xcount);
  output.print(",");
  //long thisTime = System.nanoTime() - startTime;
  //long timePassed = thisTime - lastTime;
  //lastTime = thisTime;
  //output.print(thisTime);
  //output.print(",");
  //output.print(timePassed);
  //output.print(",");
  output.println(s);
  xcount++;
}

void cleanup() {
  long ttime = (System.nanoTime() - startTime);///500;
  long ltime = ttime/linestoread;
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  println("Done.");

  long Bsec = (ccount * 1000000000)  / (ttime);
  long bsec = Bsec * 8;
  println(ttime);
  println(ltime);
  println(ccount);
  println(Bsec);
  println(bsec);
}