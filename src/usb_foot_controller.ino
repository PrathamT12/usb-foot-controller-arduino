#include <MIDIUSB.h>

//***********************************************************************

//PINS

#define fs1Pin 2
#define fs2Pin 3
#define fs3Pin 4
#define fs4Pin 5
#define fs5Pin 6




//FOOTSWITCH 1 
int currentfs1state;
int lastfs1state;

//FOOTSWITCH 2
int currentfs2state;
int lastfs2state;

//FOOTSWITCH 3 
int currentfs3state;
int lastfs3state;

//FOOTSWITCH 4
int currentfs4state;
int lastfs4state;

//FOOTSWITCH 5
int currentfs5state;
int lastfs5state;

int counter=  0;
int counter2= 0;
int counter3= 0;
int counter4= 0;
int counter5= 0;


//***********************************************************************

void setup() {
  
  Serial.begin(115200);
  pinMode(fs1Pin, INPUT_PULLUP);
  pinMode(fs2Pin, INPUT_PULLUP);
  pinMode(fs3Pin, INPUT_PULLUP);
  pinMode(fs4Pin, INPUT_PULLUP);
  pinMode(fs5Pin, INPUT_PULLUP);
  
}

//***********************************************************************

void loop() {
  
 

 //FOOTSWITCH 1
currentfs1state = digitalRead(fs1Pin);
if (currentfs1state == 0 && lastfs1state == 1)
  {
    
    if(counter%2==0){
      controlChange(0, 85, 0);
      MidiUSB.flush();
      counter++;
    }
    else {
      controlChange(0, 85, 127);
      MidiUSB.flush();
      counter++;
    //Serial.println(currentfs2state);
  }
  
  }   
   //FOOTSWITCH 2
currentfs2state = digitalRead(fs2Pin);
if (currentfs2state == 0 && lastfs2state == 1)
  {
    
    if(counter2%2==0){
      controlChange(0, 86, 0);
      MidiUSB.flush();
      counter2++;
    }
    else {
      controlChange(0, 86, 127);
      MidiUSB.flush();
      counter2++;
    //Serial.println(currentfs2state);
  }
  
  }   
   //FOOTSWITCH 3
currentfs3state = digitalRead(fs3Pin);
if (currentfs3state == 0 && lastfs3state == 1)
  {
    
    if(counter3%2==0){
      controlChange(0, 87, 0);
      MidiUSB.flush();
      counter3++;
    }
    else {
      controlChange(0, 87, 127);
      MidiUSB.flush();
      counter3++;
    //Serial.println(currentfs2state);
  }
  
  }   
   //FOOTSWITCH 4
currentfs4state = digitalRead(fs4Pin);
if (currentfs4state == 0 && lastfs4state == 1)
  {
    
    if(counter4%2==0){
      controlChange(0, 88, 0);
      MidiUSB.flush();
      counter4++;
    }
    else {
      controlChange(0, 88, 127);
      MidiUSB.flush();
      counter4++;
    //Serial.println(currentfs2state);
  }
  
  }   
   //FOOTSWITCH 5
currentfs5state = digitalRead(fs5Pin);
if (currentfs5state == 0 && lastfs5state == 1)
  {
    
    if(counter5%2==0){
      controlChange(0, 89, 0);
      MidiUSB.flush();
      counter5++;
    }
    else {
      controlChange(0, 89, 127);
      MidiUSB.flush();
      counter5++;
    //Serial.println(currentfs2state);
  }
  
  }   
lastfs1state = currentfs1state;
delay(50);

lastfs2state = currentfs2state;
delay(50);
lastfs3state = currentfs3state;
delay(50);
lastfs4state = currentfs4state;
delay(50);
lastfs5state = currentfs5state;

delay(50);

}

//***************************************************************************************************

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}
void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
  }
