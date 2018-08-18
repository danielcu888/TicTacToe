#include "QTicTacToeButton.h"
#include <QPushButton>
#include <QIcon>

//Constructor, initialises fields
QTicTacToeButton::QTicTacToeButton(QPushButton *ptr, bool b = false)
    : pB(ptr), isNought(b)
{}

bool QTicTacToeButton::noughtTurn = false;
int QTicTacToeButton::numTurns = 0;

//slot recieving GUI button clicked() signal
void QTicTacToeButton::setButton()
{
    isNought = noughtTurn; //determines token type of associated QPushButton

    //set QIcon of associated QPushButton accordingly
    if(isNought)
    {
        pB->setIcon(QIcon("/Users/danielcumberbatch/Documents/PROJECTS/PortFolio/TicTacToe/QTicTacToe/Nought.jpg"));
        pB->setIconSize(QSize(100,100));
    }
    else
    {
        pB->setIcon(QIcon("/Users/danielcumberbatch/Documents/PROJECTS/PortFolio/TicTacToe/QTicTacToe/Cross.jpg"));
        pB->setIconSize(QSize(100,100));
    }
    pB->setEnabled(false); //disable the GUI QPushbutton (since it has now been pressed)

    noughtTurn = (!noughtTurn); //switch static variable noughtTurn to indicate that it is next players go
    ++numTurns;

    emit buttonClicked(); //emit signal buttonClicked() to QTicTacToeDialog to call updateStatus() to check current status of game
}

int QTicTacToeButton::num_Turns() const
{
    return numTurns;
}

//determines if associated QPushButton has been pressed (i.e., is enabled)
bool QTicTacToeButton::enabled() const
{
    return pB->isEnabled();
}

void QTicTacToeButton::enable() //setter to enable associated QPushButton
{
    if(!enabled())
        pB->setEnabled(true);
}

void QTicTacToeButton::disable() //setter to disable associated QPushButton
{
    if(enabled())
        pB->setEnabled(false);
}

//returns token type (only relevant if associated QPushButton is disabled)
bool QTicTacToeButton::is_Nought() const
{
    return isNought;
}

void QTicTacToeButton::reset()
{
    enable();
    pB->setIcon(QIcon());
    isNought = false;
    if(noughtTurn) noughtTurn = false;
    if(numTurns != 0) numTurns = 0;
}
