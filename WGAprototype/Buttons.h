#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>

class GameButtons;
class PlayButton;

struct coord
{
    int i;
    int j;
};

// ==========================================

class GameButtons : public QPushButton
{
    Q_OBJECT
private:

//    QMultiMap<QPushButton*, coord> *map_redB;
//    QMultiMap<QPushButton*, coord> *map_greenB;
//    QMultiMap<QPushButton*, coord> *map_blueB;
//    QMultiMap<QPushButton*, coord> *map_blockB;
//    QMultiMap<QPushButton*, coord> *map_freeB;

//    QVector<QPushButton*> *vec_redB;
//    QVector<QPushButton*> *vec_greenB;
//    QVector<QPushButton*> *vec_blueB;
//    QVector<QPushButton*> *vec_blockB;
//    QVector<QPushButton*> *vec_freeB;

//    QVector<coord> * coordRed;
//    QVector<coord> * coordGreen;
//    QVector<coord> * coordBlue;
//    QVector<coord> * coordBlock;
//    QVector<coord> * coordFree;


public:
    //GameButtons();
    GameButtons(QWidget* pwgt = nullptr);

//    coord pos;
//    coord* posptr = &pos;
//    QString color;
//    int colorNum;

public slots:
//    void slotColorButtonClicked();
//    void slotFreeButtonClicked();
};

class PlayButton : public QPushButton
{
    Q_OBJECT
public:
    //PlayButton(QWidget* pwgt = nullptr);
    coord pos;
    coord* posptr = &pos;
    QString color;
    int colorNum;

public slots:
    void slotColorButtonClicked();
    void slotFreeButtonClicked();
};

#endif //BUTTONS_H
