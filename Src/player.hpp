#pragma once

#include <cstdint>

#include "position.hpp"
#include "drawing_handler.hpp"
#include "game_data.hpp"

class ChunkManager;
struct char_repr;


class Player{

    public:
    
    // The player's absoulute coordinates.
    pos3d_t<uint64_t> position;     

    int32_t health;
    int32_t max_health;

    int32_t stamina;
    int32_t max_stamina;

    int32_t saturation;
    int32_t max_saturation;

    int32_t aether;
    int32_t max_aether;

    int8_t placement_level;

    Player(abs_pos position,
    int32_t health, int32_t stamina, int32_t saturation, int32_t max_health, int32_t max_stamina, int32_t max_saturation);

    Player (abs_pos position);

    enum class Direction{Up, Down, Left, Right};

    void move(Direction direction);

    void place_block(Direction direction);

    void change_placement_level();

    void place_top_bottom();

    void remove_block(Direction direction);

    void remove_top_bottom();



};
