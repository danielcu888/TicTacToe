#include "QTicTacToeDialog.h"
#include "QTicTacToeButton.h"
#include <QVector>
#include <QObject>
#include <QDebug>

QTicTacToeDialog::QTicTacToeDialog()
    : pButtons(QVector<QVector<QTicTacToeButton*> >(3, QVector<QTicTacToeButton*>(3, NULL)))
{
    //initialize form
    ui.setupUi(this);

    //Establish connections
    QTicTacToeButton* QtttbTopLeft = new QTicTacToeButton(ui.TopLeftButton, false);
    QObject::connect(ui.TopLeftButton, SIGNAL(clicked()), QtttbTopLeft, SLOT(setButton()));
    QObject::connect(QtttbTopLeft, SIGNAL(buttonClicked()),
                     this, SLOT(updateStatus()));
    QTicTacToeButton* QtttbTopCenter = new QTicTacToeButton(ui.TopCenterButton, false);
    QObject::connect(ui.TopCenterButton, SIGNAL(clicked()), QtttbTopCenter, SLOT(setButton()));
    QObject::connect(QtttbTopCenter, SIGNAL(buttonClicked()),
                     this, SLOT(updateStatus()));
    QTicTacToeButton* QtttbTopRight = new QTicTacToeButton(ui.TopRightButton, false);
    QObject::connect(ui.TopRightButton, SIGNAL(clicked()), QtttbTopRight, SLOT(setButton()));
    QObject::connect(QtttbTopRight, SIGNAL(buttonClicked()),
                     this, SLOT(updateStatus()));
    QTicTacToeButton* QtttbMiddleLeft = new QTicTacToeButton(ui.MiddleLeftButton, false);
    QObject::connect(ui.MiddleLeftButton, SIGNAL(clicked()), QtttbMiddleLeft, SLOT(setButton()));
    QObject::connect(QtttbMiddleLeft, SIGNAL(buttonClicked()),
                     this, SLOT(updateStatus()));
    QTicTacToeButton* QtttbMiddleCenter = new QTicTacToeButton(ui.MiddleCenterButton, false);
    QObject::connect(ui.MiddleCenterButton, SIGNAL(clicked()), QtttbMiddleCenter, SLOT(setButton()));
    QObject::connect(QtttbMiddleCenter, SIGNAL(buttonClicked()),
                     this, SLOT(updateStatus()));
    QTicTacToeButton* QtttbMiddleRight = new QTicTacToeButton(ui.MiddleRightButton, false);
    QObject::connect(ui.MiddleRightButton, SIGNAL(clicked()), QtttbMiddleRight, SLOT(setButton()));
    QObject::connect(QtttbMiddleRight, SIGNAL(buttonClicked()),
                     this, SLOT(updateStatus()));
    QTicTacToeButton* QtttbBottomLeft = new QTicTacToeButton(ui.BottomLeftButton, false);
    QObject::connect(ui.BottomLeftButton, SIGNAL(clicked()), QtttbBottomLeft, SLOT(setButton()));
    QObject::connect(QtttbBottomLeft, SIGNAL(buttonClicked()),
                     this, SLOT(updateStatus()));
    QTicTacToeButton* QtttbBottomCenter = new QTicTacToeButton(ui.BottomCenterButton, false);
    QObject::connect(ui.BottomCenterButton, SIGNAL(clicked()), QtttbBottomCenter, SLOT(setButton()));
    QObject::connect(QtttbBottomCenter, SIGNAL(buttonClicked()),
                     this, SLOT(updateStatus()));
    QTicTacToeButton* QtttbBottomRight = new QTicTacToeButton(ui.BottomRightButton, false);
    QObject::connect(ui.BottomRightButton, SIGNAL(clicked()), QtttbBottomRight, SLOT(setButton()));
    QObject::connect(QtttbBottomRight, SIGNAL(buttonClicked()),
                     this, SLOT(updateStatus()));

    QObject::connect(ui.NewGameButton, SIGNAL(clicked()), this, SLOT(newGame()));

    //initilaize QTicTacToeButton* matrix
    pButtons[0][0] = QtttbTopLeft;
    pButtons[0][1] = QtttbTopCenter;
    pButtons[0][2] = QtttbTopRight;
    pButtons[1][0] = QtttbMiddleLeft;
    pButtons[1][1] = QtttbMiddleCenter;
    pButtons[1][2] = QtttbMiddleRight;
    pButtons[2][0] = QtttbBottomLeft;
    pButtons[2][1] = QtttbBottomCenter;
    pButtons[2][2] = QtttbBottomRight;
}

int QTicTacToeDialog::getId(QTicTacToeButton* pButton) const
{
    if(pButton->enabled()) return -1;
    return pButton->is_Nought() ? 0 : 1;
}

bool QTicTacToeDialog::is_draw() const
{
    return pButtons[0][0]->num_Turns() == 9;
}

//-1 = game incomplete, 0 = Noughts won, 1 = Crosses won, 2 = tie game
int QTicTacToeDialog::checkStatus() const
{
  for(int i = 0; i != 3; ++i)
    {
      for(int j = 0; j != 3; ++j)
        {
          int row = i, col = j;
          int val = getId(pButtons[row][col]);
          if(val == -1) continue;

          int count = 1;

          //check left
          while(count < 3)
            {
              --row;
              if(row >= 0 && getId(pButtons[row][col]) == val)
                ++count;
              else
                {
                  row = i;
                  count = 1;
                  break;
                }
            }
          if(count == 3) return val;

          //check right
          while(count < 3)
            {
              ++row;
              if(row < 3 && getId(pButtons[row][col]) == val)
                ++count;
              else
                {
                  row = i;
                  count = 1;
                  break;
                }
            }
          if(count == 3) return val;

          //check down
          while(count < 3)
            {
              ++col;
              if(col < 3 && getId(pButtons[row][col]) == val)
                ++count;
              else
                {
                  col = j;
                  count = 1;
                  break;
                }
            }
          if(count == 3) return val;

          //check up
          while(count < 3)
            {
              --col;
              if(col >= 0 && getId(pButtons[row][col]) == val)
                ++count;
              else
                {
                  col = j;
                  count = 1;
                  break;
                }
            }
          if(count == 3) return val;

          //check left down
          while(count < 3)
            {
              --row;
              ++col;
              if(row >= 0 && col < 3 && getId(pButtons[row][col]) == val)
                ++count;
              else
                {
                  row = i;
                  col = j;
                  count = 1;
                  break;
                }
            }
          if(count == 3) return val;

          //check right down
          while(count < 3)
            {
              ++row;
              ++col;
              if(row < 3 && col < 3 && getId(pButtons[row][col]) == val)
                ++count;
              else
                {
                  row = i;
                  col = j;
                  count = 1;
                  break;
                }
            }
          if(count == 3) return val;

          //check left up
          while(count < 3)
            {
              --row;
              --col;
              if(row >= 0 && col >= 0 && getId(pButtons[row][col]) == val)
                ++count;
              else
                {
                  row = i;
                  col = j;
                  count = 1;
                  break;
                }
            }
          if(count == 3) return val;

          //check right up
          while(count < 3)
            {
              ++row;
              --col;
              if(row < 3 && col >= 0 && getId(pButtons[row][col]) == val)
                ++count;
              else
                {
                  row = i;
                  col = j;
                  count = 1;
                  break;
                }
            }
          if(count == 3) return val;
        }
    }
  return is_draw() ? 2 : -1;
}

//should change this to updateStatus since none of these arguments are needed
void QTicTacToeDialog::updateStatus()
{
    int result = checkStatus();
    switch(result)
    {
    case -1:
        return;
    case 0:
        ui.MessageLabel->setText("Noughts Win!!!");
        break;
    case 1:
        ui.MessageLabel->setText("Crosses Win!!!");
        break;
    case 2:
        ui.MessageLabel->setText("Tie Game!");
        break;
    }

    disableAll();
    return;
}

void QTicTacToeDialog::disableAll()
{
    for(int i = 0; i != 3; ++i)
        for(int j = 0; j != 3; ++j)
            pButtons[i][j]->disable();
}

void QTicTacToeDialog::newGame()
{
    for(int i = 0; i != 3; ++i)
        for(int j = 0; j != 3; ++j)
            pButtons[i][j]->reset();
}
