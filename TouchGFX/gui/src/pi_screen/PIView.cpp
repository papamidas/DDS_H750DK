#include <gui/pi_screen/PIView.hpp>
#include <touchgfx/utils.hpp>

PIView::PIView()
{

}

void PIView::setupScreen()
{
    PIViewBase::setupScreen();

    uint64_t f_mHz = presenter->getF_mHz();
    uint32_t decPlaces = f_mHz % 1000;
    uint32_t preDecPlaces = f_mHz / 1000;
    Unicode::snprintf(textAreaFBuffer, TEXTAREAF_SIZE, "%07u.%03u", preDecPlaces, decPlaces );
    Unicode::snprintf(textAreaPIBuffer, TEXTAREAPI_SIZE, "%09u", presenter->getPI());
    Unicode::snprintf(textAreaABuffer, TEXTAREAA_SIZE, "%03d", presenter->getAM());
}

void PIView::tearDownScreen()
{
    PIViewBase::tearDownScreen();
}

void PIView::upClicked(uint64_t step)
{
    uint64_t f_mHz = presenter->getF_mHz();
	if (f_mHz >= (9999999999 - step))
    {
    	f_mHz = 9999999999;
    }
    else
    {
    	f_mHz += step;
    }
	presenter->setF_mHz(f_mHz);
    uint32_t decPlaces = f_mHz % 1000;
    uint32_t preDecPlaces = f_mHz / 1000;
    touchgfx_printf("new F value %u.%u\n", preDecPlaces, decPlaces );
    Unicode::snprintf(textAreaFBuffer, TEXTAREAF_SIZE, "%07u.%03u", preDecPlaces, decPlaces );
    textAreaF.invalidate();
    Unicode::snprintf(textAreaPIBuffer, TEXTAREAPI_SIZE, "%09u", presenter->getPI());
    textAreaPI.invalidate();
}

void PIView::downClicked(uint64_t step)
{
	uint64_t f_mHz = presenter->getF_mHz();
	if (f_mHz < step)
    {
    	f_mHz = 0;
    }
    else
    {
    	f_mHz -= step;
    }
	presenter->setF_mHz(f_mHz);
    uint32_t decPlaces = f_mHz % 1000;
    uint32_t preDecPlaces = f_mHz / 1000;
    touchgfx_printf("new F value %u.%u\n", preDecPlaces, decPlaces );
    Unicode::snprintf(textAreaFBuffer, TEXTAREAF_SIZE, "%07u.%03u", preDecPlaces, decPlaces );
    textAreaF.invalidate();
    Unicode::snprintf(textAreaPIBuffer, TEXTAREAPI_SIZE, "%09u", presenter->getPI());
    textAreaPI.invalidate();
}
