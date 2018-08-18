#include <QtGui>
#include <QApplication>
#include "QTicTacToeDialog.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QTicTacToeDialog game;

    game.show();

    return app.exec();
}
