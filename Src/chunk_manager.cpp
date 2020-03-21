#include <cassert>
#include <cmath>

#include "chunk_manager.hpp"
#include "generators.hpp"

namespace transform
{
chunk_relative_pos_t chunk_position(pos3d_t<uint64_t> absolute_position){
    
    // Modulus operator makes the result between 0 and the block length of a region. Dividing by the chunk length gives the chunk position relative
    // to it's region
    return chunk_relative_pos_t {static_cast<int8_t>( (absolute_position.x%(ChunkManager::region_length*Chunk::length))/Chunk::length ),
    static_cast<int8_t>( (absolute_position.z%(ChunkManager::region_length*Chunk::length))/Chunk::length )};
}

pos2d_t<uint64_t> region_position(pos3d_t<uint64_t> absolute_position){
    return pos2d_t<uint64_t> {absolute_position.x/(ChunkManager::region_length*Chunk::length), absolute_position.z/(ChunkManager::region_length*Chunk::length)};
}

pos3d_t<uint8_t> in_chunk_position(pos3d_t<uint64_t> absolute_position){
    return pos3d_t<uint8_t> {static_cast<uint8_t>(absolute_position.x%Chunk::length), static_cast<uint8_t>(absolute_position.y), static_cast<uint8_t>(absolute_position.z%Chunk::length)};
}
}

bool operator==(const chunk_key_t& a, const chunk_key_t& b){
    return a.chunk.x == b.chunk.x && a.chunk.z == b.chunk.z &&  a.region.x == b.region.x && a.region.z == b.region.z;
}

bool operator!=(const chunk_key_t& a, const chunk_key_t& b){
    return !(a == b);
}

ChunkManager::ChunkManager(){


}

ChunkManager::~ChunkManager(){


}

chunk_key_t::chunk_key_t(chunk_relative_pos_t chunk, pos2d_t<uint64_t> region): chunk{chunk}, region{region}{}

chunk_key_t::chunk_key_t(): chunk_key_t(chunk_relative_pos_t{}, pos2d_t<uint64_t>{}){}


void chunk_key_t::correct_values(){

    /*
    If the chunk coordinates exceed the bounds of a region, this function is used to correct the values.
    If for example the z coordinates are less than 0, it will decrement the region z coordinates.

    */

    if (chunk.z < 0){

        chunk.z = ChunkManager::region_length+chunk.z;
        --region.z;

    }

    if (chunk.z >= ChunkManager::region_length){

        chunk.z = chunk.z - ChunkManager::region_length;
        ++region.z;

    }

    if (chunk.x >= ChunkManager::region_length){

        chunk.x = chunk.x - ChunkManager::region_length;
        ++region.x;

    }

    if (chunk.x < 0){

        chunk.x = ChunkManager::region_length+chunk.x;
        --region.x;

    }

}


void ChunkManager::load_in_range(const chunk_key_t& center_position){
    
    // Unload chunks by region
    for (auto& element : loaded_chunks){
        if (abs(static_cast<int16_t>(center_position.region.x - element.first.region.x)) > region_unload_range
        || abs(static_cast<int16_t>(center_position.region.z - element.first.region.z)) > region_unload_range)
        {
            loaded_chunks.erase(element.first);

        }
    }

    
    current_chunkpos = center_position;
    chunk_key_t offset_position;
    for (int16_t offset_x = -load_range; offset_x <= load_range; ++offset_x)
    for (int16_t offset_z = -load_range; offset_z <= load_range; ++offset_z){

        offset_position.region.x = center_position.region.x;
        offset_position.region.z = center_position.region.z;
        offset_position.chunk.x = center_position.chunk.x+offset_x;
        offset_position.chunk.z = center_position.chunk.z+offset_z;
        offset_position.correct_values();

        // Checks if the chunk's position is stored in the map loaded_chunks.
        // If it isn't in the vector, then it will either be loaded or generated.
        if (loaded_chunks.find(offset_position) == loaded_chunks.end()){
            loaded_chunks[offset_position] = std::move(generate_flat(offset_position.chunk, offset_position.region));
        }

    }
    
}

block_t ChunkManager::get_block_absolute(const abs_pos& position){

    return loaded_chunks.at(chunk_key_t{transform::chunk_position(position), transform::region_position(position)}).get_block(transform::in_chunk_position(position));

}

void ChunkManager::set_block_absolute(const abs_pos& position, block_t data){
    
    loaded_chunks.at(chunk_key_t{transform::chunk_position(position), transform::region_position(position)}).set_block(transform::in_chunk_position(position), data);

}

