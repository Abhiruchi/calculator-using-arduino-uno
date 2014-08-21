#include <IRremote.h>

int recvLED = 13;
int recvPin = 15;

IRrecv irReciver(recvPin);
decode_results results;

// Defining the pins for the 7 segment display
byte s7segment[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
void setup()
{
  pinMode(recvLED, OUTPUT); //Configue the recvLED pin as an OUTPUT pin
  digitalWrite(recvLED, LOW); //Leave the LED off as we start

  Serial.begin(9600); // Initialize the serial port with a baud rate of 9600 bps

  irReciver.enableIRIn(); // Start the receiver
  
  for (int i=0; i<8; i++) 
  {
    pinMode(s7segment[i], OUTPUT); //Configure all pins in the 7 segments display as OUTPUT  
  }  
}
// Initializing the digits array
byte digits[][13] = {
   { 1, 1, 1, 1, 1, 1, 0, 0}, // digit 0
   { 0, 0, 1, 1, 0, 0, 0, 0}, // digit 1
   { 1, 1, 0, 1, 1, 0, 1, 0}, // digit 2
   { 0, 1, 1, 1, 1, 0, 1, 0}, // digit 3
   { 0, 0, 1, 1, 0, 1, 1, 0}, // digit 4
   { 0, 1, 1, 0, 1, 1, 1, 0}, // digit 5
   { 1, 1, 1, 0, 1, 1, 1, 0}, // digit 6
   { 0, 0, 1, 1, 1, 0, 0, 0}, // digit 7
   { 1, 1, 1, 1, 1, 1, 1, 0}, // digit 8
   { 0, 1, 1, 1, 1, 1, 1, 0}, // digit 9
   { 1, 0, 1, 1, 1, 1, 0, 0}, // add
   { 1, 1, 1, 1, 0, 1, 0, 0},  // subtract
   { 1, 0, 1, 1, 0, 1, 1, 0},   //multiply
   { 1, 1, 1, 1, 1, 1, 0, 0}  // divide
  // { 0, 1, 0, 0, 1, 0, 0, 0}  //equal
};
const unsigned long decodeHASH[] = {
  0xFF6897, // Digit 0
  0xFF30CF, // digit 1
  0xFF18E7, // digit 2 
  0xFF7A85, // digit 3
  0xFF10EF, // digit 4
  0xFF38C7, // digit 5
  0xFF5AA5,  // digit 6
  0xFF42BD, // digit 7
  0xFF4AB5, // digit 8
  0xFF52AD, // digit 9
  0xFFA857, // add
  0xFFE01F,  // subtract
  0xFF02FD,   //multiply
  0xFF22DD  // divide
};
unsigned long lastTime = 0;
int input()
{
  unsigned long recv_value;
  int p,b;
  while (!irReciver.decode(&results)) {
  }
  if (irReciver.decode(&results)) {
    recv_value = results.value; 
    Serial.println("hex value:");
    Serial.println(recv_value, HEX);
    if (  recv_value == 0xFF6897 || recv_value == 0xFF30CF || recv_value == 0xFF18E7 || recv_value == 0xFF7A85 || recv_value == 0xFF10EF || recv_value == 0xFF38C7 || recv_value == 0xFF5AA5
    || recv_value == 0xFF42BD ||recv_value == 0xFF4AB5 || recv_value == 0xFF52AD || recv_value == 0xFFA857 || recv_value == 0xFFE01F ||recv_value == 0xFF02FD || recv_value == 0xFF22DD ) //Ignore the 0x00 values recived as a result of pressing and holding a button on the remote for long
    {
      // Blink the LED each time a button is pressed
      digitalWrite(recvLED, HIGH);
      delay(10);
      digitalWrite(recvLED, LOW);  
      
      // Output the decoded hash value to th serial monitor. This is for debugging purposes only.
      Serial.println(recv_value, HEX);
      
      //Iterate through the decoded hash array values to find a match
      for (int i=0; i<=13; i++)
      {
        if ( recv_value == decodeHASH[i] ) // If the received value matches one of the values in the hash array
        {
          lastTime = millis(); // Start power saving delay timer
           p = i;
          for (int j=0; j<=8; j++)
            //Set the relevant segments HIGH or LOW as defined in the digits[][] double array
            digitalWrite(s7segment[j], digits[i][j]);
            
          break; // Exit from the inner loop as we have now toggled all required segments to display the appropriate value
        }
      }
    }  else {
      p = 122;
    }
    irReciver.resume(); // Read the next value
  }
  Serial.println("input : ");
  Serial.println(p);
  return p;
}

void loop()
{  
   int i;
   int p,rp,sum,r,a=122,b=122,c=122;
   while (!irReciver.decode(&results)) {
   }
   while (a == 122) {
   a = input();
   }
   Serial.println("loop1 :");
   Serial.println(a);
   i = a;
   delay(1000);
   while (!irReciver.decode(&results)) {
   }
   while (b == 122) {
   b = input();
   }
   Serial.println("loop2 :");
   Serial.println(b);
   i = b;
   delay(1000);
   while (!irReciver.decode(&results)) {
   }
   while (c == 122) {
   c = input();
   }
   Serial.println("loop3 :");
   Serial.println(c);
   i = c;
   delay(1000);
   if (b == 10) {    
   sum = a+c;
   } else if (b == 11) {
   sum = a-c;
   } else if (b == 12) {
   sum = a*c;
   } else if (b == 13) {
   sum = a/c;
   }
   p = sum;
   sum = sum/10;
   rp = sum*10;
   r = p - rp;
   for (int ij = 0; ij <= 9; ij++) {
     if (sum == ij) {
        i = sum;
    for (int j = 0; j <= 8; j++) {
      digitalWrite(s7segment[j], digits[i][j]);
    }
     }
   }
  
    delay(1000);
  
     for (int ij = 0; ij <= 9; ij++) {
     if (sum == ij) {
        i = r;
       for (int j = 0; j <= 8; j++) {
       digitalWrite(s7segment[j], digits[i][j]);
       }
     }
   }
   delay(1000);          
}
