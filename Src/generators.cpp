#include "chunk.hpp"
#include <functional>
#include <random>

Chunk generate_flat(chunk_relative_pos_t position, pos2d_t<uint64_t> region_position){

    Chunk new_chunk {position, region_position};

    std::random_device seed {};
    

    auto rng = std::bind(std::uniform_int_distribution<uint8_t>{0, 1}, std::default_random_engine{seed()});

    pos3d_t<uint8_t> block_position {0, 0, 0};
    for (block_position.z = 0; block_position.z < Chunk::length; ++block_position.z)
    for (block_position.x = 0; block_position.x < Chunk::length; ++block_position.x){

        new_chunk.set_block(block_position, Blocks::make_block(rng() ? Blocks::ID::Dirt : Blocks::ID::Grass, 0));

    }

    new_chunk.change_made = false;

    return new_chunk;

}
