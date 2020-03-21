#include "game_window.hpp"
#include "ui_game_window.h"
#include "game_data.hpp"
#include "player.hpp"
//#include "Entity/entity.hpp"

#include <QString>
#include <QPainter>




GameWindow::GameWindow(QWidget *parent):
    QMainWindow(parent), ui(new Ui::MainWindow), pixmap(new QPixmap(672, 672)), game_painter(new QPainter(pixmap)), drawingHandler(game_painter)
{
    ui->setupUi(this);


    ui->GameView->setFixedSize((DrawingHandler::drawing_distance*2+1)*DrawingHandler::textureSizePx, (DrawingHandler::drawing_distance*2+1)*DrawingHandler::textureSizePx);
    //pixmap->fill(Qt::black);

    gameData.player = new Player(abs_pos{UINT64_MAX/2, 1, UINT64_MAX/2});

    gameData.chunkManager.load_in_range(chunk_key_t {transform::chunk_position(gameData.player->position), transform::region_position(gameData.player->position)});

    drawingHandler.draw_game_grid();
    ui->GameView->setPixmap(*pixmap);


}

GameWindow::~GameWindow()
{
    game_painter->end();
    delete game_painter;
    delete ui;
    delete pixmap;
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{

    bool do_screen_update {true};

    switch (event->key())
    {

    case Qt::Key_Up:
        gameData.player->move(Player::Direction::Up);
        break;

    case Qt::Key_Down:
        gameData.player->move(Player::Direction::Down);
        break;

    case Qt::Key_Left:
        gameData.player->move(Player::Direction::Left);
        break;

    case Qt::Key_Right:
        gameData.player->move(Player::Direction::Right);
        break;

    case Qt::Key_W:
        gameData.player->place_block(Player::Direction::Up);
        break;

    case Qt::Key_S:
        gameData.player->place_block(Player::Direction::Down);
        break;

    case Qt::Key_A:
        gameData.player->place_block(Player::Direction::Left);
        break;

    case Qt::Key_D:
        gameData.player->place_block(Player::Direction::Right);
        break;


    default:
        do_screen_update = false;
        break;


    }

    if (do_screen_update){
        drawingHandler.draw_game_grid();
        ui->GameView->setPixmap(*pixmap);
    }


}


