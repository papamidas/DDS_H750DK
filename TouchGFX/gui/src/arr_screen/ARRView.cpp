#include <gui/arr_screen/ARRView.hpp>
#include <touchgfx/utils.hpp>

ARRView::ARRView()
{

}

void ARRView::setupScreen()
{
    ARRViewBase::setupScreen();
    uint8_t arr = presenter->getARR();
    Unicode::snprintf(textAreaARRBuffer, TEXTAREAARR_SIZE, "%03d", arr);
    slider_ARR.setValue(arr);
}

void ARRView::tearDownScreen()
{
    ARRViewBase::tearDownScreen();
}

void ARRView::setARR(int value)
{
    presenter->setARR(value);
    touchgfx_printf("ARR value set: %03d\n", value);
    Unicode::snprintf(textAreaARRBuffer, TEXTAREAARR_SIZE, "%03d", value);
    textAreaARR.invalidate();
}
