#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
/*
 * Melody: A C A A# B C 
 */
int speakerPort = 0;
int buttonPort = 0;
int bpm =66;//So I can change the song later
unsigned long quarter_note = (60.0/bpm) *1000;//duration of a quarter note in milliseconds
unsigned long eight_note = (30.0/bpm) *1000;//duration of an eight note in milliseconds
unsigned long whole_note = quarter_note*4//assuming 4/4 measure
int[] melody = [NOTE_A1, NOTE_C1,NOTE_A1,NOTE_AS1, NOTE_B1, NOTE_C1];
int[] duration =[eigth_note, eigth_note, eigth_note,quarter_note, quarter_note, whole_note];
int buttonState=0;


void setup() {
  pinMode(speakerPort, OUTPUT);
  pinMode(buttonPort, INPUT);
}

void loop() {
  if(buttonState==0 && digitalRead(buttonPort)//to make sure the loop doesn't constantly go if someone hammers the button
  {
    butonState=1;
  }

 if(button_state==1){
  for(int i=0;i<sizeof(melody);++i)
  {
    tone(speakerPort,melody[i],duration[i]);
  }
  buttonState=0;//reset state
 }

}
