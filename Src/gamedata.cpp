#include "gamedata.hpp"
#include "player.hpp"

GameData::GameData(): chunkManager(ChunkManager()), player(new Player(abs_pos{UINT64_MAX/2, 1, UINT64_MAX/2}))
{

}

GameData::~GameData()
{

    delete player;


}

GameData gameData {};
