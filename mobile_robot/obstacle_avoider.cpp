/* Swarm Embeded Robotic Platform (SERP),is a low cost robust robot designed for robotics hobbyists and enthusiasts.
It has been extensively developed on STM32, has an onboard  power suppy, IR array ( 7 Sensors), Ulatrasonic sensors, motor drivers
It is used to build a wide range of robots. 
Here we demosntrate a Obstacle Avoider
*/


// A program for a Obstacle Avoider Using STM32

const int trigPin = PA12;
const int echoPin = PA11;


// defining variables
long duration;
int distance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(PB5,OUTPUT);
pinMode(PB6,OUTPUT);
pinMode(PB7,OUTPUT);
pinMode(PB8,OUTPUT);


digitalWrite(PB5,LOW);
digitalWrite(PB6,LOW);
digitalWrite(PB7,LOW);
digitalWrite(PB8,LOW);


Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);

delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds

duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.println(distance);

if(distance > 20)
{

digitalWrite(PB5,HIGH);
digitalWrite(PB6,LOW);
digitalWrite(PB7,HIGH);
digitalWrite(PB8,LOW);
  
}


if(distance <= 20)
{

digitalWrite(PB5,LOW);
digitalWrite(PB6,HIGH);
digitalWrite(PB7,HIGH);
digitalWrite(PB8,LOW);  

delay(1000);
digitalWrite(PB5,HIGH);
digitalWrite(PB6,LOW);
digitalWrite(PB7,HIGH);
digitalWrite(PB8,LOW);

delay(2000);

digitalWrite(PB5,HIGH);
digitalWrite(PB6,LOW);
digitalWrite(PB7,LOW);
digitalWrite(PB8,HIGH);

delay(1000);


}
