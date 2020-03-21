#include "drawing_handler.hpp"



void DrawingHandler::draw_block(const block_t & block, const uint8_t& x, const uint8_t& z, int layer){
    

    // Makes sure to not draw air over other blocks.
    // If the block is air and the layer is not -2, then the block won't be drawn.
    if (static_cast<Blocks::ID>(Blocks::get_ID(block)) != Blocks::ID::Air || layer == -2)
    {

        const QPixmap* texture_sheet;
        QPixmap texture {textureSizePx, textureSizePx};

        if (auto iterator = block_textures.find(block); iterator != block_textures.end()){
            texture_sheet = &iterator->second;

        } else {
            texture_sheet = &block_textures[Blocks::make_block(Blocks::ID::Undefined, 0)];
        }

        bool apply_shade = false;

        switch(layer)
        {
        case -2:

            switch(texture_sheet->height())
            {
            case textureSizePx*3:
                texture = texture_sheet->copy(0, textureSizePx*2, textureSizePx, textureSizePx);
                break;

            case textureSizePx*2:
                texture = texture_sheet->copy(0, 0, textureSizePx, textureSizePx);
                apply_shade = true;
                break;


            case textureSizePx:
                texture = *texture_sheet;
                break;
            }


            break;

        case -1:
            texture = texture_sheet->copy(0, 0, textureSizePx, textureSizePx);


            break;

        case 0:
            if (texture_sheet->height() >= textureSizePx*2){
                texture = texture_sheet->copy(0, textureSizePx, textureSizePx, textureSizePx);
            } else {
                texture = *texture_sheet;
            }

            break;

        }

        game_painter->drawPixmap(textureSizePx*x, textureSizePx*z, textureSizePx, textureSizePx, texture);
        if (apply_shade) game_painter->drawPixmap(textureSizePx*x, textureSizePx*z, textureSizePx, textureSizePx, shade_filter);


    }

}
