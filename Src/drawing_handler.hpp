#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <QObject>
#include <QPixmap>
#include <QPainter>

#include "blocks.hpp"

class Player;
class ChunkManager;



class DrawingHandler: public QObject{

    Q_OBJECT

    public:
    DrawingHandler(QPainter* game_painter, QObject* parent=nullptr);

    void draw_game_grid();
    void draw_block(const block_t & block, const uint8_t& x, const uint8_t& z, int layer);

    static constexpr int16_t drawing_distance {10};
    static constexpr int textureSizePx {32};

    std::map<block_t, QPixmap> block_textures;



    QPixmap shade_filter;
    // The default texture for blocks that are two blocks below the player. Used so that the player can see what blocks are safe to descend to.

    private:
    static const std::map<block_t, std::string> block_texture_paths;


    QPainter* game_painter;

    QPixmap player_texture;

};


