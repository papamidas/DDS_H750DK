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
    virtual void upPressed();
    virtual void downPressed();
    virtual void selectDigit();
    double getFout();

protected:
    uint32_t piValue=0;
    uint8_t binaryDigit=0;
    double dacClock = 400e6/22.0;
};

#endif // PIVIEW_HPP
