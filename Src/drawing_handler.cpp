#include <iostream>
#include <QColor>

#include "drawing_handler.hpp"


#define define_element(ID, DATA, PATH) {Blocks::make_block(ID, DATA), PATH}

const std::map<block_t, std::string> DrawingHandler::block_texture_paths {

    define_element(Blocks::ID::Dirt, 0, ":Images/Blocks/Dirt.png"),
    define_element(Blocks::ID::Grass, 0, ":Images/Blocks/Grass.png"),
    define_element(Blocks::ID::Wood, 0, ":Images/Blocks/Wood.png"),
    define_element(Blocks::ID::Undefined, 0, ":Images/Blocks/Undefined.png")


};


DrawingHandler::DrawingHandler(QPainter* game_painter, QObject* parent):  QObject(parent), shade_filter(32, 32), game_painter(game_painter),
    player_texture(QPixmap(":Images/Player/player_default.png").scaled(32, 32))
{

    int texture_length = 16;
    int drawn_texture_length = 32;
    for (auto path_iterator = block_texture_paths.begin(); path_iterator != block_texture_paths.end(); ++path_iterator){
        QPixmap image_data = QPixmap { path_iterator->second.c_str() };
        block_textures[path_iterator->first] = image_data.scaled(drawn_texture_length, (image_data.height()/texture_length) * drawn_texture_length); // Double the size of every pixel.

    }

    {
        QPixmap air_texture = QPixmap(drawn_texture_length, drawn_texture_length);
        air_texture.fill(Qt::black);
        block_textures[Blocks::make_block(Blocks::ID::Air, 0)] = air_texture;

    }

    shade_filter.fill(QColor(0, 0, 0, 80));






}
