#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void setLEDState(bool state);
    void btnPressed();

protected:
    ModelListener* modelListener;
private:
};

#endif // MODEL_HPP
