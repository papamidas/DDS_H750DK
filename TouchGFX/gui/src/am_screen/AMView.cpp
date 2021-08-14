#include <gui/am_screen/AMView.hpp>
#include <touchgfx/utils.hpp>

AMView::AMView()
{

}

void AMView::setupScreen()
{
    AMViewBase::setupScreen();
    uint8_t am = presenter->getAM();
    Unicode::snprintf(textAreaAMBuffer, TEXTAREAAM_SIZE, "%03d", am);
    slider_AM.setValue(am);
}

void AMView::tearDownScreen()
{
    AMViewBase::tearDownScreen();
}

void AMView::setAM(int value)
{
    presenter->setAM(value);
    touchgfx_printf("AM value set: %02X\n", value);
    Unicode::snprintf(textAreaAMBuffer, TEXTAREAAM_SIZE, "%03d", value);
    textAreaAM.invalidate();
}
