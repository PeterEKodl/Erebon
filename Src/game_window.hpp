#pragma once

#include <QMainWindow>
#include <QKeyEvent>

#include "drawing_handler.hpp"
#include "chunk_manager.hpp"

class QPixmap;
class QPainter;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void keyPressEvent(QKeyEvent* event);


private:
    Ui::MainWindow *ui;
    QPixmap* pixmap;
    QPainter* game_painter;
    DrawingHandler drawingHandler;
    ChunkManager chunkManager;

};
