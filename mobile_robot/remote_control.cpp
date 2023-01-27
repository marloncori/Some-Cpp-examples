/* Swarm Embeded Robotic Platform (SERP),is a low cost robust robot designed for robotics hobbyists and enthusiasts.
It has been extensively developed on STM32, has an onboard  power suppy, IR array ( 7 Sensors), Ulatrasonic sensors, motor drivers
It is used to build a wide range of robots. 
Here we demosntrate a Bluetooth Controlled RC car
*/


// A program for a Bluetooth Controlled RC car Using STM32


char given;  // The Incomming data wil be stored in the variabe called given



void setup() {

// Declaring  the pins to be connected to the motor driver 

pinMode(PB5,OUTPUT);  // PB5 is the Right Motor Forward pin
pinMode(PB6,OUTPUT);  // PB6 is the Right Motor Backward pin
pinMode(PB7,OUTPUT);  // PB7 is the Left Motor Forward pin
pinMode(PB8,OUTPUT);  // PB7 is the Left Motor Backward pin

// Initilizing  the pins to low    
digitalWrite(PB5,LOW);
digitalWrite(PB6,LOW);
digitalWrite(PB7,LOW);
digitalWrite(PB8,LOW);

Serial.begin(9600);
}

void loop() {

// Check if Serial Data is available 

if(Serial.available()>0)
{
  given = Serial.read();  // store incomming data in given 

if ( given == 'F')  // Forward command is recieved 
{
  
Serial.println("F");
digitalWrite(PB5,HIGH);
digitalWrite(PB6,LOW);
digitalWrite(PB7,HIGH);
digitalWrite(PB8,LOW);
  
}


if ( given == 'S')  // Stop command is recieved 
{
Serial.println("S");
digitalWrite(PB5,LOW);
digitalWrite(PB6,LOW);
digitalWrite(PB7,LOW);
digitalWrite(PB8,LOW);  
}


if ( given == 'B')  // Back command is recieved 
{
Serial.println("B");
digitalWrite(PB5,LOW);
digitalWrite(PB6,HIGH);
digitalWrite(PB7,HIGH);
digitalWrite(PB8,LOW);  
}


if ( given == 'L') // Left command is recieved 
{
 Serial.println("L");
digitalWrite(PB5,HIGH);
digitalWrite(PB6,LOW);
digitalWrite(PB7,LOW);
//digitalWrite(PB8,HIGH);  
}

/*
if ( given == 'R') // Right command is recieved 
{
Serial.println("R");
digitalWrite(PB5,LOW);
digitalWrite(PB6,HIGH);
digitalWrite(PB7,HIGH);
digitalWrite(PB8,LOW);  
}
*/

}
}