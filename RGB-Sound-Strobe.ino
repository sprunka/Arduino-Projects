#define LEDstripBlue 9
#define LEDstripGreen 10
#define LEDstripRed 11
#define LED_ON 0
#define LED_OFF 255
#define RED 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define MAGENTA 4
#define YELLOW 5
#define BLACK 6
#define WHITE 7

// const int buttonPin = 2;
const int soundSensorPin = 7;

// int currentState = HIGH;
// int previousState = LOW;
// int reading;
int soundState = 0;

// unsigned long timer = 0;
// unsigned long debounce = 200UL;

void setup()
{
  //Serial.begin(9600);
  pinMode(soundSensorPin, INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital Pin 7
  // initialize the pushbutton pin as an input:
  // pinMode(buttonPin, INPUT);
  pinMode(LEDstripBlue, OUTPUT);
  pinMode(LEDstripGreen, OUTPUT);
  pinMode(LEDstripRed, OUTPUT);

}

void loop()
{
  // This all feels so bass-ackwards, honestly. But it works the way I waned it to.
  // If there is a sound, it will light a (weighted) psuedo-random selected combination of LEDs.
  soundState = digitalRead(soundSensorPin);
//  int reading = digitalRead(buttonPin);
//
//  if (reading == LOW && previousState == HIGH && millis() - timer > debounce) {
//  Serial.print("READING--");
//  Serial.println(reading);
//    if (currentState == HIGH) {
//      Serial.println("SETTING CURRENT = LOW");
//      currentState = LOW;
//    } else {
//      Serial.println("SETTING CURRENT = HIGH");
//      currentState = HIGH;
//    }
//    timer = millis();
//  }
//  
  int color = random(18);

  if (soundState == 0)
  {
    if (color == GREEN) {
      // GREEN
      analogWrite(LEDstripGreen, LED_ON);
      analogWrite(LEDstripBlue, LED_OFF);
      analogWrite(LEDstripRed, LED_OFF);
    } else if (color == RED || color == 8 || color == 11 || color == 13 || color == 15) {
      //RED
      analogWrite(LEDstripBlue, LED_OFF);
      analogWrite(LEDstripGreen, LED_OFF);
      analogWrite(LEDstripRed, LED_ON);
      delay(10);
    } else if (color == BLUE || color == 9 || color == 16) {
      //BLUE
      analogWrite(LEDstripGreen, LED_OFF);
      analogWrite(LEDstripRed, LED_OFF);
      analogWrite(LEDstripBlue, LED_ON);
      delay(10);
    } else if (color == YELLOW) {
      //YELLOW
      analogWrite(LEDstripBlue, LED_OFF);
      analogWrite(LEDstripRed, LED_ON);
      analogWrite(LEDstripGreen, LED_ON);
      delay(10);
    } else if (color == MAGENTA || color == 10 || color == 12 || color == 14 || color == 17) {
      //MAGENTA
      analogWrite(LEDstripRed, LED_ON);
      analogWrite(LEDstripBlue, LED_ON);
      analogWrite(LEDstripGreen, LED_OFF);
      delay(10);
    } else if (color == CYAN) {
      //CYAN
      analogWrite(LEDstripRed, LED_OFF);
      analogWrite(LEDstripBlue, LED_ON);
      analogWrite(LEDstripGreen, LED_ON);
    } else if (color == WHITE || color == 18) {
      //WHITE
      analogWrite(LEDstripBlue, LED_ON);
      analogWrite(LEDstripGreen, LED_ON);
      analogWrite(LEDstripRed, LED_ON);
    }
    delay(25);
  } else {
   // if (currentState == HIGH) {
      // WHITE
   //   analogWrite(LEDstripBlue, LED_ON);
   //   analogWrite(LEDstripGreen, LED_ON);
   //   analogWrite(LEDstripRed, LED_ON);
   // } else {
      //BLACK
      analogWrite(LEDstripBlue, LED_OFF);
      analogWrite(LEDstripGreen, LED_OFF);
      analogWrite(LEDstripRed, LED_OFF);
  //  }
  //previousState = HIGH;
  }
}
