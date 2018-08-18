#ifndef QTICTACTOEDIALOG_H
#define QTICTACTOEDIALOG_H

#include <QObject>
#include <QDialog>
#include "ui_QTicTacToeDialog.h"
#include "QTicTacToeButton.h"
#include <QVector>

class QTicTacToeDialog : public QDialog
{
    Q_OBJECT

public:
    QTicTacToeDialog();

private slots:
    void updateStatus();
    void newGame();

private:
    Ui::QTicTacToeDialog ui;

    int checkStatus() const;
    bool is_draw() const;
    void disableAll();
    int getId(QTicTacToeButton*) const;

    QVector<QVector<QTicTacToeButton*> > pButtons;
};

#endif // QTICTACTOEDIALOG_H
