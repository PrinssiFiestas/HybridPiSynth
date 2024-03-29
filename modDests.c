#include <string.h>
#include <math.h>
#include "HybridPiSynth.h"

void initModDests()
{
    modDestCount = 0; // Also used for indexing

    #define SET_MOD_DEST_NAME(X)       strcpy(modDests[modDestCount].name,X)
    #define SET_MOD_DEST_KEY(X)        strcpy(modDests[modDestCount].key,X)
    #define MOD_DEST_INIT_VALUE        modDests[modDestCount].modSources[dcIndex].amount
    #define MOD_DEST_UPDATE_METHOD     modDests[modDestCount].updateValue

    //----------------------------------------------------

    // OSCILLATOR 1 FREQUENCY

    SET_MOD_DEST_NAME("Osc freq");
    SET_MOD_DEST_KEY("f1");
    MOD_DEST_INIT_VALUE = 0.9;
    osc1freqIndex = modDestCount;

    modDestCount++;

    // OSCILLATOR 1 FINE TUNING

    SET_MOD_DEST_NAME("Osc 1 fine freq");
    SET_MOD_DEST_KEY("fine1");
    MOD_DEST_INIT_VALUE = 0.5;
    osc1fineIndex = modDestCount;

    modDestCount++;

    // OSCILLATOR 1 SHAPE

/*     SET_MOD_DEST_NAME("Osc 1 shape");
    SET_MOD_DEST_KEY("shape1");
    oscShapeIndex = modDestCount;

    modDestCount++; */

    // OSCILLATOR 1 PULSE WIDTH

    SET_MOD_DEST_NAME("Osc 1 PWM");
    SET_MOD_DEST_KEY("pwm1");
    MOD_DEST_INIT_VALUE = 0.5;
    osc1PWMindex = modDestCount;

    modDestCount++;

    // OSCILLATOR 2 FREQUENCY

    SET_MOD_DEST_NAME("Osc 2 freq");
    SET_MOD_DEST_KEY("f2");
    MOD_DEST_INIT_VALUE = 0.9;
    osc2freqIndex = modDestCount;

    modDestCount++;

    // OSCILLATOR 2 FINE TUNING

    SET_MOD_DEST_NAME("Osc 2 fine freq");
    SET_MOD_DEST_KEY("fine2");
    MOD_DEST_INIT_VALUE = 0.51; // Sligth detuning
    osc2fineIndex = modDestCount;

    modDestCount++;

    // OSCILLATOR 2 SHAPE

/*     SET_MOD_DEST_NAME("Osc 2 shape");
    SET_MOD_DEST_KEY("shape2");
    osc2shapeIndex = modDestCount;

    modDestCount++; */

    // OSCILLATOR 2 PULSE WIDTH

    SET_MOD_DEST_NAME("Osc 2 PWM");
    SET_MOD_DEST_KEY("pwm2");
    MOD_DEST_INIT_VALUE = 0.5;
    osc2PWMindex = modDestCount;

    modDestCount++;

    // ATTACK

    SET_MOD_DEST_NAME("Attack");
    SET_MOD_DEST_KEY("a");
    attackIndex = modDestCount;
    void attackMethod(double paramIn)
    {
        modDests[attackIndex].value = pow(10, -8*paramIn);
        modDests[attackIndex].secondaryValue = 1 - modDests[attackIndex].value;
    }
    MOD_DEST_UPDATE_METHOD = attackMethod;

    modDestCount++;

    // DECAY

    SET_MOD_DEST_NAME("Decay");
    SET_MOD_DEST_KEY("d");
    MOD_DEST_INIT_VALUE = 0.5;
    decayIndex = modDestCount;
    void decayMethod(double paramIn)
    {
        modDests[decayIndex].value = pow(10, -8*paramIn);
        modDests[decayIndex].secondaryValue = 1 - modDests[decayIndex].value;
    }
    MOD_DEST_UPDATE_METHOD = decayMethod;

    modDestCount++;

    // SUSTAIN

    SET_MOD_DEST_NAME("Sustain");
    SET_MOD_DEST_KEY("s");
    MOD_DEST_INIT_VALUE = 0.5;
    sustainIndex = modDestCount;

    modDestCount++;

    // RELEASE

    SET_MOD_DEST_NAME("Release");
    SET_MOD_DEST_KEY("r");
    MOD_DEST_INIT_VALUE = 0.5;
    releaseIndex = modDestCount;
    void releaseMethod(double paramIn)
    {
        modDests[releaseIndex].value = pow(10, -8*paramIn);
        modDests[releaseIndex].secondaryValue = 1 - modDests[releaseIndex].value;
    }
    MOD_DEST_UPDATE_METHOD = releaseMethod;

    modDestCount++;

    // VCA AUDIO INPUT

    SET_MOD_DEST_NAME("VCA Input");
    SET_MOD_DEST_KEY("vcain");
    modDests[modDestCount].modSources[saw1index].amount = 0.5; // saw -> vcain initial modulation amount
    vcaIndex = modDestCount;

    modDestCount++;

    // VCA CV INPUT

    SET_MOD_DEST_NAME("VCA CV");
    SET_MOD_DEST_KEY("vcacv");
    modDests[modDestCount].modSources[adsrIndex].amount = 1; // adsr -> vcacv initial modulation amount
    vcaCVindex = modDestCount;

    modDestCount++;

    // OUTPUT 1

    SET_MOD_DEST_NAME("Output 1");
    SET_MOD_DEST_KEY("out1");
    modDests[modDestCount].modSources[vcaOutIndex].amount = 1; // vca -> out1 initial modulation amount
    out1index = modDestCount;

    modDestCount++;

    // OUTPUT 2

    SET_MOD_DEST_NAME("Output 2");
    SET_MOD_DEST_KEY("out2");
    modDests[modDestCount].modSources[adsrIndex].amount = 1; // adsr -> out2 initial modulation amount
    out2index = modDestCount;

    modDestCount++;
}