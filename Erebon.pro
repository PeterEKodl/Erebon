QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17



# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Src/Entity/entity.cpp \
    Src/blocks.cpp \
    Src/chunk.cpp \
    Src/chunk_manager.cpp \
    Src/draw_block.cpp \
    Src/drawing_handler.cpp \
    Src/game_flow.cpp \
    Src/game_window.cpp \
    Src/gamedata.cpp \
    Src/generators.cpp \
    Src/grid.cpp \
    Src/main.cpp \
    Src/main_menu.cpp \
    Src/player.cpp \


HEADERS += \
    Src/Entity/entity.hpp \
    Src/blocks.hpp \
    Src/chunk.hpp \
    Src/chunk_manager.hpp \
    Src/drawing_handler.hpp \
    Src/game_data.hpp \
    Src/game_flow.hpp \
    Src/game_state.hpp \
    Src/game_window.hpp \
    Src/gamedata.hpp \
    Src/generators.hpp \
    Src/main_menu.hpp \
    Src/player.hpp \
    Src/position.hpp \


FORMS += \
    game_window.ui \
    main_menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Resources/Images/Player.png

RESOURCES += \
    data_resources.qrc \
    img_resources.qrc
