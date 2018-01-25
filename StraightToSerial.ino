#include <CapacitiveSensor.h>

/**Debounce timer
 * Simple abstraction to simplify
 * debounce timing of triggers
 */
class DebounceTimer{
private:
    //time left until timer expires
    long TimeLeft = 0;
    //original time set
    long TotalTime = 0;
    //start time in ms since power up
    long Start = 0;
    bool Started = false;
public:
    /**constructor
     * @param TimeMS Optional time to set timer for
     */
    DebounceTimer(long TimeMS=500){
        this->TotalTime = TimeMS;
        this->TimeLeft = TimeMS;
    }

    /**Reset and restart the timer */
    void reset() {
        this->TimeLeft = this->TotalTime;
        this->Started = true;
        this->Start = millis();
    }

    /**Check if the timer is finished.  Return true
     * if timer was never started
     */
    bool finished() {
        //Update timer
        if(this->Started == true)
        {
            this->TimeLeft = this->TotalTime - (millis() - this->Start);
        }
        else 
        {
            //return true if not started so reset can also act as start
            return true;
        }
        if(this->TimeLeft <= 0)
        {
            //stop timer
            this->Started = false;
            return true;
        }
        else
        {
            return false;
        }
    }
};

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
DebounceTimer timer1(500);

/**
 * Define a threshold value here to trigger a note
 * This may vary from person to person depending on 
 * Resistors used and length of conductor
 */
 #define THRESHOLD 500
 /** Infinite wait means never */
 #define NEVER 0xFFFFFFFF

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(NEVER);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    long value1 =  cs_4_2.capacitiveSensor(30);

    if(value1 > THRESHOLD)
    {
        if(timer1.finished())
        {
            Serial.print("a");
            timer1.reset();
        }
    }
}
