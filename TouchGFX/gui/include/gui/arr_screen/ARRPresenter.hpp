#ifndef ARRPRESENTER_HPP
#define ARRPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ARRView;

class ARRPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ARRPresenter(ARRView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    void setARR(uint8_t arr)
    {
    	model->setARR(arr);
    }

    uint8_t getARR()
    {
    	return model->getARR();
    }


    virtual ~ARRPresenter() {};

private:
    ARRPresenter();

    ARRView& view;
};

#endif // ARRPRESENTER_HPP
