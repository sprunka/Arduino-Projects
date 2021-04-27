#define LEDstripBlue 9
#define LEDstripGreen 10
#define LEDstripRed 11

void setup()
{
  Serial.begin(9600);
  pinMode(7, INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital Pin 7
  pinMode(LEDstripBlue, OUTPUT);
  pinMode(LEDstripGreen, OUTPUT);
  pinMode(LEDstripRed, OUTPUT);

}

void loop()
{
  // This all feels so bass-ackwards, honestly. But it works the way I waned it to.
  // If there is a sound, it will light a randomly selected combination of LEDs.
  boolean soundstate = digitalRead(7);

  int color = random(7);

  if (soundstate == 0 && color == 0) {
    analogWrite(LEDstripBlue, 255);
    analogWrite(LEDstripGreen, 0);
    analogWrite(LEDstripRed, 0);
    delay(10);
  } else if (soundstate == 0 && color == 1) {
    analogWrite(LEDstripGreen, 255);
    analogWrite(LEDstripBlue, 0);
    analogWrite(LEDstripRed, 0);
    delay(10);
  } else if (soundstate == 0 && color == 2) {
    analogWrite(LEDstripBlue, 0);
    analogWrite(LEDstripGreen, 0);
    analogWrite(LEDstripRed, 255);
    delay(10);
  } else if (soundstate == 0 && color == 3) {
    analogWrite(LEDstripGreen, 0);
    analogWrite(LEDstripRed, 255);
    analogWrite(LEDstripBlue, 255);
    delay(10);
  } else if (soundstate == 0 && color == 4) {
    analogWrite(LEDstripBlue, 0);
    analogWrite(LEDstripRed, 255);
    analogWrite(LEDstripGreen, 255);
    delay(10);
  } else if (soundstate == 0 && color == 5) {
    analogWrite(LEDstripRed, 0);
    analogWrite(LEDstripBlue, 255);
    analogWrite(LEDstripGreen, 255);
    delay(10);
  } else if (soundstate == 0 && color == 6) {
    analogWrite(LEDstripBlue, 255);
    analogWrite(LEDstripGreen, 255);
    analogWrite(LEDstripRed, 255);
    delay(10);
  } else {
    analogWrite(LEDstripBlue, 255);
    analogWrite(LEDstripGreen, 255);
    analogWrite(LEDstripRed, 255);
  }
}
