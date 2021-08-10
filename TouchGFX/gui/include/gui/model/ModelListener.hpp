#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    virtual void btnPressed() {}

    // Call this function to notify that gain has changed.
    // Per default, use an empty implementation so that only those
    // Presenters interested in this specific event need to
    // override this function.
    //virtual void notifyGainChanged(int newGain) {}

    void bind(Model* m)
    {
        model = m;
    }

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
