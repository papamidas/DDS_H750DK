#ifndef PIVIEW_HPP
#define PIVIEW_HPP

#include <gui_generated/pi_screen/PIViewBase.hpp>
#include <gui/pi_screen/PIPresenter.hpp>

class PIView : public PIViewBase
{
public:
    PIView();
    virtual ~PIView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void upClicked(uint64_t step);
    void downClicked(uint64_t step);
    virtual void buttonUP0Clicked() { upClicked(1); }
    virtual void buttonUP1Clicked() { upClicked(10); }
    virtual void buttonUP2Clicked() { upClicked(100); }
    virtual void buttonUP3Clicked() { upClicked(1000); }
    virtual void buttonUP4Clicked() { upClicked(10000); }
    virtual void buttonUP5Clicked() { upClicked(100000); }
    virtual void buttonUP6Clicked() { upClicked(1000000); }
    virtual void buttonUP7Clicked() { upClicked(10000000); }
    virtual void buttonUP8Clicked() { upClicked(100000000); }
    virtual void buttonUP9Clicked() { upClicked(1000000000); }
    virtual void buttonDOWN0Clicked() { downClicked(1); }
    virtual void buttonDOWN1Clicked() { downClicked(10); }
    virtual void buttonDOWN2Clicked() { downClicked(100); }
    virtual void buttonDOWN3Clicked() { downClicked(1000); }
    virtual void buttonDOWN4Clicked() { downClicked(10000); }
    virtual void buttonDOWN5Clicked() { downClicked(100000); }
    virtual void buttonDOWN6Clicked() { downClicked(1000000); }
    virtual void buttonDOWN7Clicked() { downClicked(10000000); }
    virtual void buttonDOWN8Clicked() { downClicked(100000000); }
    virtual void buttonDOWN9Clicked() { downClicked(1000000000); }
    uint32_t getPI();

protected:
    uint64_t f_mHz;

    const uint8_t PHASEBITS = 32;
    double dacClock = 400e6/22.0;
    double dacperiod_s = 1/dacClock;
};

#endif // PIVIEW_HPP

