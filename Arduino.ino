#include <CapacitiveSensor.h>

/**
 * Define a threshold value here to trigger a note
 * This may vary from person to person depending on 
 * Resistors used and length of conductor
 */
#define THRESHOLD 1000
/** Infinite wait means never */
#define NEVER 0xFFFFFFFF
/*Debounce time is minimum time between two notes in MS */
#define DEBOUNCE_TIME 120

/**Debounce timer
 * Simple abstraction to simplify
 * debounce timing of triggers
 */
class DebounceTimer
{
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
    DebounceTimer(long TimeMS = 500)
    {
        this->TotalTime = TimeMS;
        this->TimeLeft = TimeMS;
    }

    /**Reset and restart the timer */
    void reset()
    {
        this->TimeLeft = this->TotalTime;
        this->Started = true;
        this->Start = millis();
    }

    /**Check if the timer is finished.  Return true
     * if timer was never started
     */
    bool finished()
    {
        //Update timer
        if (this->Started == true)
        {
            this->TimeLeft = this->TotalTime - (millis() - this->Start);
        }
        else
        {
            //return true if not started so reset can also act as start
            return true;
        }
        if (this->TimeLeft <= 0)
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

CapacitiveSensor cs_2 = CapacitiveSensor(4, 2);   // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor cs_6 = CapacitiveSensor(4, 6);   // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil if desired
CapacitiveSensor cs_8 = CapacitiveSensor(4, 8);   // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil if desired
CapacitiveSensor cs_10 = CapacitiveSensor(4, 10); // 10M resistor between pins 4 & 10, pin 10 is sensor pin, add a wire and or foil if desired
DebounceTimer timer2(DEBOUNCE_TIME);
DebounceTimer timer6(DEBOUNCE_TIME);
DebounceTimer timer8(DEBOUNCE_TIME);
DebounceTimer timer10(DEBOUNCE_TIME);


void setup()
{
    //Turn off auto-calibration of sensors
    cs_2.set_CS_AutocaL_Millis(NEVER);  // turn off autocalibrate on channel 1 - just as an example
    cs_6.set_CS_AutocaL_Millis(NEVER);  // turn off autocalibrate on channel 1 - just as an example
    cs_8.set_CS_AutocaL_Millis(NEVER);  // turn off autocalibrate on channel 1 - just as an example
    cs_10.set_CS_AutocaL_Millis(NEVER); // turn off autocalibrate on channel 1 - just as an example

    //Open serial port
    Serial.begin(250000);
}

void loop()
{
    //Get capacitive sensor values
    long value2 = cs_2.capacitiveSensor(30);

    //Process Sensor.  Check if trigger is hit,
    //make sure time has passed since last pressed,
    //send note over serial.
    if ( value2 > THRESHOLD)
    {
        if (timer2.finished())
        {
            //Serial.print(value2);
            Serial.print("c");
            timer2.reset();
        }
    }

    long value6 = cs_6.capacitiveSensor(30);
    if ( value6 > THRESHOLD)
    {
        if (timer6.finished())
        {
            //Serial.print(value6);
            Serial.print("d");
            timer6.reset();
        }
    }

    long value8 = cs_8.capacitiveSensor(30);
    if ( value8 > THRESHOLD)
    {
        if (timer8.finished())
        {
            //Serial.print(value8);
            Serial.print("e");
            timer8.reset();
        }
    }

    long value10 = cs_10.capacitiveSensor(30);
    if ( value10 > THRESHOLD)
    {
        if (timer10.finished())
        {
            //Serial.print(value10);
            Serial.print("g");
            timer10.reset();
        }
    }
}
