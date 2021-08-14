#ifndef AMVIEW_HPP
#define AMVIEW_HPP

#include <gui_generated/am_screen/AMViewBase.hpp>
#include <gui/am_screen/AMPresenter.hpp>

class AMView : public AMViewBase
{
public:
    AMView();
    virtual ~AMView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void setAM(int value);
protected:

};

#endif // AMVIEW_HPP
