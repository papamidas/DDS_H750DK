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

void PIView::upPressed()
{
	if (piValue > (0xffffffff - (1 << binaryDigit)))
	{
		piValue = 0xffffffff;
	}
	else
	{
		piValue += (1 << binaryDigit);
	}
    touchgfx_printf("PI value incremented: %08X\n", piValue);
    Unicode::snprintf(textAreaPIBuffer, TEXTAREAPI_SIZE, "%08X", piValue);
    textAreaPI.invalidate();
    Unicode::snprintfFloat(textAreaFBuffer, TEXTAREAF_SIZE, "%.3f", getFout());
    textAreaF.invalidate();
}

void PIView::downPressed()
{
	if (piValue < ((uint32_t)1 << binaryDigit))
	{
		piValue = 0;
	}
	else
	{
		piValue -= ((uint32_t)1 << binaryDigit);
	}
    touchgfx_printf("PI value decremented: %08X\n", piValue);
    Unicode::snprintf(textAreaPIBuffer, TEXTAREAPI_SIZE, "%08X", piValue);
    textAreaPI.invalidate();
    Unicode::snprintfFloat(textAreaFBuffer, TEXTAREAF_SIZE, "%.3f", getFout());
    textAreaF.invalidate();
}

void PIView::selectDigit()
{
	RadioButton * rb = radioButtonGroup1.getSelectedRadioButton();
	if(rb == &radioButton0)
	{
		binaryDigit=0;
	}
	else if (rb == &radioButton1)
	{
		binaryDigit=4;
	}
	else if (rb == &radioButton2)
	{
		binaryDigit=8;
	}
	else if (rb == &radioButton3)
	{
		binaryDigit=12;
	}
	else if (rb == &radioButton4)
	{
		binaryDigit=16;
	}
	else if (rb == &radioButton5)
	{
		binaryDigit=20;
	}
	else if (rb == &radioButton6)
	{
		binaryDigit=24;
	}
	else if (rb == &radioButton7)
	{
		binaryDigit=28;
	}
}

// calculation of the output frequency of the DDS, given the phase increment value:
double PIView::getFout()
{
	return (dacClock * piValue / ((uint64_t)1 << 32));
}
