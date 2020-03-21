#include <cstdint>
#include "blocks.hpp"

std::vector<blockID_t> Blocks::non_solid_blocks {
    static_cast<blockID_t>(Blocks::ID::Air),
    static_cast<blockID_t>(Blocks::ID::Water),
    static_cast<blockID_t>(Blocks::ID::Lava),
    static_cast<blockID_t>(Blocks::ID::Door)  
};

std::vector<blockID_t> Blocks::liquid_blocks {
    static_cast<blockID_t>(Blocks::ID::Water),
    static_cast<blockID_t>(Blocks::ID::Lava)
};

blockID_t Blocks::get_ID(block_t block){

    return static_cast<blockID_t>(block & 0x000000FFFF);

}

blockData_t Blocks::get_data(block_t block){

    return static_cast<blockData_t>(block >> sizeof(blockID_t));

}
