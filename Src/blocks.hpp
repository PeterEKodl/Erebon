#pragma once
#include <cstdint>
#include <algorithm>
#include <vector>

using block_t = uint32_t;
using blockID_t = uint16_t;
using blockData_t = uint16_t;

//#define contains(vector, element) std::find(vector.begin(), vector.end(), element) != vector.end()

namespace Blocks{

    enum class ID : blockID_t {
        
        // Blocks 0, 1, 2 can be passed through, though lava does deal damage
        Air =         0,
        // Liquids
        Water =       1, 
        Lava =        2,
        
        // Solids
        Unbreak =     3,
        Undefined =   4,
        Dirt =        5, 
        Grass =       6,
        Stone =       7,
        Wood =        8,
        Door =        9, // Door with data value 1 is closed, 0 is open.
        Stairs =      10,
        Tree =        11,
        Sand =        12,
        Coal =        13,
        Iron =        14,
        Gold =        15,
        Titanium =    16,
        Gyrinium =    17
        
    };

    extern std::vector<blockID_t> non_solid_blocks;
    extern std::vector<blockID_t> liquid_blocks;

    

    blockID_t get_ID(block_t block);

    blockData_t get_data(block_t block);

    constexpr block_t make_block(blockID_t id, blockData_t data){

        return (static_cast<block_t>(data) << sizeof(blockID_t)) | static_cast<block_t>(id);

    }

    constexpr block_t make_block(Blocks::ID id, blockData_t data)
    {

        return (static_cast<block_t>(data) << sizeof(blockID_t)) | static_cast<block_t>(id);

    }

}
