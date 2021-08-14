#ifndef MODEL_HPP
#define MODEL_HPP
#include <stdint.h>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void setDacClock_Hz(double dacf) { dacClock = dacf; }
    void setF_mHz(uint64_t f)
    {
    	f_mHz = f;
        // calculation of the phase increment value of the DDS, given the output frequency:
    	piValue = f_mHz * 0.001 * 1.0/dacClock * ((uint64_t)1 << PHASEBITS) + 0.5;
    }
    void setARR(uint8_t arr) { arrValue = arr; }
    void setAM(uint8_t am) { amValue = am; }
    uint64_t getF_mHz() { return f_mHz; }
    uint32_t getPI() { return piValue; }
    uint8_t getAM() { return amValue; }
    uint8_t getARR() { return arrValue; }
    uint8_t getPhaseBits() { return PHASEBITS; }

protected:
    ModelListener* modelListener;

    const uint8_t PHASEBITS = 32;
    uint64_t f_mHz; // DDS output frequency in Milli-Hertz
    uint32_t piValue; // Phase increment value
    uint8_t amValue;
    uint8_t arrValue;
    double dacClock;


private:
};

#endif // MODEL_HPP
