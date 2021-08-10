#include <gui/am_screen/AMView.hpp>
#include <touchgfx/utils.hpp>

AMView::AMView()
{

}

void AMView::setupScreen()
{
    AMViewBase::setupScreen();
}

void AMView::tearDownScreen()
{
    AMViewBase::tearDownScreen();
}

void AMView::setAM(int value)
{
    amValue = value;
    touchgfx_printf("AM value set: %02X\n", amValue);
    Unicode::snprintf(textAreaAMBuffer, TEXTAREAAM_SIZE, "%03d", amValue);
    textAreaAM.invalidate();
}
