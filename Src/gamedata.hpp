#pragma once

#include "chunk_manager.hpp"

class Player;

struct GameData
{
    GameData();
    ~GameData();
    ChunkManager chunkManager;
    Player* player;

};

