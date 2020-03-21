#include <iostream>
#include <cstdlib>

#include "player.hpp"
#include "chunk_manager.hpp"
#include "drawing_handler.hpp"
#include "game_data.hpp"

void DrawingHandler::draw_game_grid(){

    // The position of the chunk out of which block data will be fetched.
    chunk_key_t rendering_chunk_pos {};
    // The offset of the players position used to get the blocks around him.
    abs_pos offset_position;
    // The coordinates of the blocks in the chunk getting rendered.
    pos3d_t<uint8_t> chunk_block_pos;

    for (int y_offset = -2; y_offset <= 0; ++y_offset)
    {
        offset_position.y = gameData.player->position.y + y_offset;
        // If player.position.y + y_offset is negative, the result will underflow.
        if(offset_position.y >= Chunk::height || offset_position.y < 0)
        {
            // Skip the loop so that it doesn't draw blocks that don't exist, possibly causing  a memory access error.
            continue;
        }

        for (int x_offset = -drawing_distance; x_offset <= drawing_distance; ++x_offset)
        {
            offset_position.x = gameData.player->position.x + x_offset;

            for (int z_offset = -drawing_distance; z_offset <= drawing_distance; ++z_offset)
            {
                offset_position.z = gameData.player->position.z + z_offset;

                draw_block(gameData.chunkManager.get_block_absolute(offset_position), drawing_distance+x_offset, drawing_distance+z_offset, y_offset);

            }
        }
    }

    game_painter->drawPixmap(drawing_distance*textureSizePx, drawing_distance*textureSizePx, player_texture);

}
