#include <gui/pi_screen/PIView.hpp>
#include <touchgfx/utils.hpp>

PIView::PIView()
{

}

void PIView::setupScreen()
{
    PIViewBase::setupScreen();
}

void PIView::tearDownScreen()
{
    PIViewBase::tearDownScreen();
}

void PIView::upClicked(uint64_t step)
{
    if (f_mHz >= (9999999999 - step))
    {
    	f_mHz = 9999999999;
    }
    else
    {
    	f_mHz += step;
    }
    uint32_t decPlaces = f_mHz % 1000;
    uint32_t preDecPlaces = f_mHz / 1000;
    touchgfx_printf("new F value %u.%u\n", preDecPlaces, decPlaces );
    Unicode::snprintf(textAreaFBuffer, TEXTAREAF_SIZE, "%07u.%03u", preDecPlaces, decPlaces );
    textAreaF.invalidate();
    Unicode::snprintf(textAreaPIBuffer, TEXTAREAPI_SIZE, "%09u", getPI());
    textAreaPI.invalidate();
}

void PIView::downClicked(uint64_t step)
{
    if (f_mHz < step)
    {
    	f_mHz = 0;
    }
    else
    {
    	f_mHz -= step;
    }
    uint32_t decPlaces = f_mHz % 1000;
    uint32_t preDecPlaces = f_mHz / 1000;
    touchgfx_printf("new F value %u.%u\n", preDecPlaces, decPlaces );
    Unicode::snprintf(textAreaFBuffer, TEXTAREAF_SIZE, "%07u.%03u", preDecPlaces, decPlaces );
    textAreaF.invalidate();
    Unicode::snprintf(textAreaPIBuffer, TEXTAREAPI_SIZE, "%09u", getPI());
    textAreaPI.invalidate();
}

// calculation of the phase increment value of the DDS, given the output frequency:
uint32_t PIView::getPI()
{
	return (f_mHz * 0.001 * dacperiod_s * ((uint64_t)1 << PHASEBITS) + 0.5);
}
