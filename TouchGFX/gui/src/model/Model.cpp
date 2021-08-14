#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0),
                 f_mHz(0),
				 piValue(0),
				 amValue(0),
                 arrValue(0),
				 dacClock(400e6/22.0)
{

}

void Model::tick()
{

}

