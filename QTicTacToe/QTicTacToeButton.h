#ifndef QTICTACTOEBUTTON_H
#define QTICTACTOEBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QIcon>

//class which is-a QObject and has-a QPushButton*
class QTicTacToeButton : public QObject
{
    Q_OBJECT

public:
    explicit QTicTacToeButton(QPushButton*, bool); //constructor initilizing relevant information

    void enable(); //setter to enable QPushButton pointed to by pB
    void disable(); //setter to diable QPushButton pointed to by pB
    bool enabled() const; //accessor to determine whether button is enabled
    bool is_Nought() const; //accessor to determine if QPushButton is  a Nought or a Cross (only relevant if button disabled)
    void reset();
    int num_Turns() const;

public slots:
    void setButton(); //slot to recieve clicked() signal from *pB, update icon of *pB and disable *pB and then emit signal buttonClicked()
                      //to be recieved by updateStatus() slot of QTicTacToeDialog to check status
signals:
    void buttonClicked(); //signal to be recieved by updateStatus() slot of QTicTacToeDialog to check status

private:
    QPushButton* pB; //pointer to associated QPushButton
    bool isNought; //determines token type of associated QPushButton

    static bool noughtTurn;
    static int numTurns;
};

#endif // QTICTACTOEBUTTON_H
