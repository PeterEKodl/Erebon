#include "entity.hpp"


std::vector<IHandlesInput*> IHandlesInput::inputHandlingEntities {};

IHandlesInput::IHandlesInput(){
    inputHandlingEntities.push_back(this);
}

Entity::Entity(abs_pos position, quint16 ID): position{position}, ID{ID}
{

}
