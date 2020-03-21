#include <utility>
#include "chunk.hpp"

Chunk::Chunk():Chunk(chunk_relative_pos_t{0, 0}, pos2d_t<uint64_t>{0, 0}){}

Chunk::Chunk(chunk_relative_pos_t position, pos2d_t<uint64_t> region_position):  
region_postion(region_position), position(position), change_made(false), chunk_memory(new block_t[length*length*height]()){}

// Copy constructor
Chunk::Chunk(const Chunk& source){

    *this = source;

}

// Move constructor
Chunk::Chunk(Chunk&& source){

    *this = std::move(source);

}

// Copy assignment
Chunk& Chunk::operator=(const Chunk& source){

    if (!chunk_memory) chunk_memory = new block_t[Chunk::size];

    for (size_t index = 0; index < Chunk::size; ++index){

        chunk_memory[index] = source.chunk_memory[index];

    }

    position = source.position;
    region_postion = source.region_postion;
    change_made = source.change_made;

    return *this;

}

// Move assignment
Chunk& Chunk::operator=(Chunk&& source){

    if (chunk_memory) delete[] chunk_memory;

    chunk_memory = source.chunk_memory;
    source.chunk_memory = nullptr;

    position = source.position;
    region_postion = source.region_postion;
    change_made = source.change_made;

    return *this;
    
}

void Chunk::move_memory(block_t*& source){

    if (chunk_memory) delete[] chunk_memory;

    chunk_memory = source;
    source = nullptr;

}

void Chunk::copy_memory(block_t* const& source){

    if (!chunk_memory) chunk_memory = new block_t[Chunk::size];

    for (size_t index = 0; index < Chunk::size; ++index){

        chunk_memory[index] = source[index];

    }

}

Chunk::~Chunk(){

    if (chunk_memory) delete[] chunk_memory;
    
}

block_t Chunk::get_block(pos3d_t<uint8_t> position){
    
    return *(chunk_memory + position.x + position.z * length + position.y * length * length);
    
}

void Chunk::set_block(pos3d_t<uint8_t> position, block_t data){
    change_made = true;
    *(chunk_memory + position.x + position.z * length + position.y * length * length) = data;
}
