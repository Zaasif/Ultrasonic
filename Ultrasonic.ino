#define echoPin 11 // Echo Pin
#define trigPin 12 // Trigger Pin
#define LEDG 6// Onboard LED
#define LEDR 5

int maximumRange = 110; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDG, OUTPUT); 
 pinMode(LEDR, OUTPUT);
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of t nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 Serial.println(distance);
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 digitalWrite(LEDG, HIGH);
  digitalWrite(LEDR, LOW);
 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 digitalWrite(LEDG, LOW);
 digitalWrite(LEDR, HIGH); 
 }
 
 //Delay 50ms before next reading.
 delay(50);
}
