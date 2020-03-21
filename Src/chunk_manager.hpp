#pragma once

#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cstdint>

#include "position.hpp"
#include "chunk.hpp"

namespace transform{
    chunk_relative_pos_t chunk_position(pos3d_t<uint64_t> absolute_position);

    pos2d_t<uint64_t> region_position(pos3d_t<uint64_t> absolute_position);

    pos3d_t<uint8_t> in_chunk_position(pos3d_t<uint64_t> absolute_position);
}


struct chunk_key_t {

    chunk_key_t (chunk_relative_pos_t chunk, pos2d_t<uint64_t> region);
    chunk_key_t ();
    
    chunk_relative_pos_t chunk;

    pos2d_t<uint64_t> region;

    // If chunk_x or chunk_z are greater than the amount of chunks in a region or lesser than 0, this function
    // will correct them and increment or decrement the region_x or region_z values respectively.
    void correct_values();

    friend bool operator==(const chunk_key_t& a, const chunk_key_t& b);

    friend bool operator!=(const chunk_key_t& a, const chunk_key_t& b);



};



namespace std
{

    // Injecting specialization of the hash for chunk_key_t into the namespace std 
    // for compatibility with std::unordered_map
    template <> 
    struct hash<chunk_key_t>
    {

        std::size_t operator()(const chunk_key_t& key) const noexcept{

            return static_cast<std::size_t>(key.chunk.x ^ key.chunk.z ^ key.region.x ^ key.region.z);

        }
    

    };


}


class ChunkManager{

    public:

    enum class Shift_Direction: uint8_t{

        UP = 0,
        DOWN,
        LEFT,
        RIGHT

    };

    std::unordered_map<chunk_key_t, Chunk> loaded_chunks;
    // The order of saving chunks doesn't matter that much.
    std::queue<Chunk> chunk_save;
    // Load the chunk that was most recently requested.
    std::stack<chunk_key_t> chunk_load_id;
    

    // The length of the box of chunks that is actively loaded into the game.
    static constexpr uint8_t load_range {3};
    // Chunks are unloaded by region.
    static constexpr uint8_t region_unload_range {1};
    static constexpr int8_t region_length {8};

    // The chunk that the player is currently located in.
    chunk_key_t current_chunkpos;

    ChunkManager();
    
    ~ChunkManager();

    // void shift_active_chunks(Shift_Direction direction);

    void load_in_range(const chunk_key_t& center_position);

    block_t get_block_absolute(const abs_pos& position);
    void set_block_absolute(const abs_pos& position, block_t data);

};
