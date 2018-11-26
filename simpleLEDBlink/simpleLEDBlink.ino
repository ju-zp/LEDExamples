//Simple script for demonstrating how to blink an LED and how to simulate 
//dimness and brightness. This uses an anode RGB LED. But any single color or dual 
//color LED can be used instead. Make sure the PINS that you hook you LED up to are 
//set in the LED pins below. When using a Cathode LED (connected via GND pin) switch 
//values from HIGH to LOW and LOW to HIGH. This is due to opposite polarities. 

//LED pins.
const int green = 10;
const int red = 9;
const int blue = 11;

void setup() {
  //Set pins to output.
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);

  //Set LEDS to off.(Using anode LED, switch HIGH to LOW if using cathode)
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(green, HIGH);
}

void loop() {
//  blink(red, 1000);
//  blink(green, 1000);
//  blink(blue, 1000);
//  moreOn(red);
//  moreOff(red);
}

//passing LED pin and time interval, blinks led.(Switch HIGH to LOW and vice versa if
//using cathode LED).
void blink(int led, int delayTime){
  digitalWrite(led, LOW);
  delay(delayTime);
  digitalWrite(led, HIGH);
  delay(delayTime);
}

//Simulates dimness by having the LED off more than on.
void moreOff(int led){
  digitalWrite(led, LOW);
  delay(5);
  digitalWrite(led, HIGH);
  delay(40);
}

//Simulates brightness by having the LED on more than off.
void moreOn(int led){
  digitalWrite(led, LOW);
  delay(40);
  digitalWrite(led, HIGH);
  delay(5);
}

