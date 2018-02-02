import processing.serial.*;
import ddf.minim.*;

Minim minim;
AudioPlayer kick;
AudioPlayer snare;
AudioPlayer clap;
AudioPlayer hat;
AudioPlayer hatO;


Serial Arduino;
int note;

void setup() {
    //size(300, 300);
    minim = new Minim(this);
    kick = minim.loadFile("Kick.mp3");
    snare = minim.loadFile("Snare.mp3");
    clap = minim.loadFile("Clap.mp3");
    hat = minim.loadFile("HihatClosed.mp3");
    hatO = minim.loadFile("HihatOpen.mp3");
    printArray(Serial.list());
    Arduino = new Serial(this, Serial.list()[0], 250000);
}

void draw() {
    if(Arduino.available() > 0) {
        note = Arduino.read();
        if(note == 'c')
        {
            kick.rewind();
            kick.play();
        }
        else if(note == 'd')
        {
            snare.rewind();
            snare.play();
        }
        else if(note == 'e')
        {
            clap.rewind();
            clap.play();
        }
        else if(note == 'g')
        {
            hat.rewind();
            hat.play();
        }
        else if(note == 'a')
        {
            hatO.rewind();
            hatO.play();
        }
        else 
        {
            println("Error: ");
            println(Arduino.read());
        }
    }
}