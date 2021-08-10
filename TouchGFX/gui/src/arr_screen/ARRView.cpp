#include <gui/arr_screen/ARRView.hpp>
#include <touchgfx/utils.hpp>

ARRView::ARRView()
{

}

void ARRView::setupScreen()
{
    ARRViewBase::setupScreen();
}

void ARRView::tearDownScreen()
{
    ARRViewBase::tearDownScreen();
}

void ARRView::setARR(int value)
{
    arrValue = value;
    touchgfx_printf("ARR value set: %03d\n", arrValue);
    Unicode::snprintf(textAreaARRBuffer, TEXTAREAARR_SIZE, "%03d", arrValue);
    textAreaARR.invalidate();
}
