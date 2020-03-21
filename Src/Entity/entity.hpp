#pragma once

#include <vector>
#include <Qt>

#include "../position.hpp"
#include "../game_data.hpp"


/* This file contains the base class for all entities in the game, including the player.
 *
 *
 */



enum class EntityID: quint16
{

    player = 0,





};


class IHandlesInput{

public:
    IHandlesInput();
    static void passInput(Qt::Key input);

protected:
    virtual void handleInput(Qt::Key input) = 0;

private:
    static std::vector<IHandlesInput*> inputHandlingEntities;

};




class Entity
{
public:
    Entity(abs_pos position, quint16 ID);


    abs_pos position;
    quint16 ID;

protected:
    bool despawns;
    bool destroyed;

private:


};

//class Player: public Entity, public IHandlesInput
//{

//    void handleInput(Qt::Key input) override;

//};
