#ifndef PIPRESENTER_HPP
#define PIPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PIView;

class PIPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PIPresenter(PIView& v);

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

    void setF_mHz(uint64_t f)
    {
    	model->setF_mHz(f);
    }

    uint64_t getF_mHz()
    {
    	return model->getF_mHz();
    }


    uint32_t getPI()
    {
    	return model->getPI();
    }

    uint8_t getAM()
	{
    	return model->getAM(); }

    virtual ~PIPresenter() {};

private:
    PIPresenter();

    PIView& view;
};

#endif // PIPRESENTER_HPP
