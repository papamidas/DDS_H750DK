#ifndef ARRVIEW_HPP
#define ARRVIEW_HPP

#include <gui_generated/arr_screen/ARRViewBase.hpp>
#include <gui/arr_screen/ARRPresenter.hpp>

class ARRView : public ARRViewBase
{
public:
    ARRView();
    virtual ~ARRView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void setARR(int value);
protected:

};

#endif // ARRVIEW_HPP
