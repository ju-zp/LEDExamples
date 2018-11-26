//LED pins
const int green = 10;
const int red = 9;
const int blue = 11;

//Values for RGB log
int redValue = 255;
int greenValue = 0;
int blueValue = 0;

void setup() {

  Serial.begin(9600);
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
//  fadeUp(red);
//  fadeDown(red);
//  simpleColorFade();
  colorFade();
  // put your main code here, to run repeatedly:

}

//fades colors together.
void colorFade(){
  analogWrite(red, 0);
  fadeUp(green);
  fadeDown(red);
  fadeUp(blue);
  fadeDown(green);
  fadeUp(red);
  fadeDown(blue);
}

//fades red, green and the blue.
void simpleColorFade(){
  fadeUp(red);
  fadeDown(red);
  fadeUp(green);
  fadeDown(green);
  fadeUp(blue);
  fadeDown(blue);
}


//Usses PWM to fade LED up.
void fadeUp(int led){
  for(int i = 255; i >= 0; i--){
    analogWrite(led, i);
    if(led == 10){
      greenValue = 255 - i; //offset for print out.
    } else if(led == 11){
      blueValue = 255 - i;
    } else if(led == 9){
      redValue = 255 - i;
    }
    Serial.println(String("RGB(") + redValue + "," + greenValue + "," + blueValue + ")");
    delay(10);
  }
}

//Uses PWM to fade LED down.
void fadeDown(int led){
  for(int i = 0; i <= 255; i++){
    analogWrite(led, i);
     if(led == 10){
      greenValue = 255 - i; //ofset for print out.
    } else if(led == 11){
      blueValue = 255 - i;
    } else if(led == 9){
      redValue = 255 - i;
    }
    Serial.println(String("RGB(") + redValue + "," + greenValue + "," + blueValue + ")");
    delay(10);
  }
}

