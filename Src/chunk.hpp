#pragma once

#include "blocks.hpp"
#include "position.hpp"

using chunk_relative_pos_t = pos2d_t<int8_t>;


class Chunk{

    public:
    Chunk();
    Chunk(chunk_relative_pos_t position, pos2d_t<uint64_t> region_position);

    Chunk (const Chunk& source); // Copy constructor
    Chunk(Chunk&& source); // Move constructor

    Chunk& operator=(const Chunk& source); // Copy assignment
    Chunk& operator=(Chunk&& source); // Move assignment

    void move_memory(block_t*& source);
    void copy_memory(block_t* const& source);

    ~Chunk();

    static constexpr uint16_t length = 16;
    static constexpr uint16_t height = 256;
    static constexpr uint32_t size = length * length * height;
    

    pos2d_t<uint64_t> region_postion;

    // The chunk's position in it's respective region.
    chunk_relative_pos_t position;

    bool change_made;

    block_t get_block(pos3d_t<uint8_t> position);
    void set_block(pos3d_t<uint8_t> position, block_t data);

    private:
    block_t * chunk_memory;

};
