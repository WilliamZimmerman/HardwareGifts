
int b0 = 31;
int c1 = 33;
int cS1 = 35;
int d1 = 37;
int dS1 = 39;
int e1 = 41;
int f1 = 44;
int fS1 = 46;
int g1 = 49;
int gS1 = 52;
int a1 = 55;
int aS1 = 58;
int b1 = 62;
int c2 = 65;
int cS2 = 69;
/*
   Melody: A C A A B C
*/
int speakerPort = 6;
int buttonPort = 8;
int bpm = 66; //So I can change the song later
unsigned long quarter_note = (60.0 / bpm) * 1000; //duration of a quarter note in milliseconds
unsigned long eighth_note = (30.0 / bpm) * 1000; //duration of an eight note in milliseconds
unsigned long whole_note = quarter_note * 4; //assuming 4/4 measure
int melody[] = {a1, c1, a1, aS1, b1, c1};
unsigned long duration[] = {eighth_note, eighth_note, eighth_note, quarter_note, quarter_note, whole_note};
int buttonState = 0;


void setup() {
  Serial.flush();
  pinMode(speakerPort, OUTPUT);
  pinMode(buttonPort, INPUT);
}

void loop() {
  if (buttonState == 0 && digitalRead(buttonPort)) //to make sure the loop doesn't constantly go if someone hammers the button
{
  Serial.print("Button Pressed");
    buttonState = 1;
  }

  if (buttonState == 1) {
  for (int i = 0; i < sizeof(melody); ++i)
    {
      tone(speakerPort, melody[i], duration[i]);
    }
    buttonState = 0; //reset state
  }

}
