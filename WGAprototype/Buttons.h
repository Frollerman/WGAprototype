#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>

class GameButtons;
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
    QMultiMap<QPushButton*, coord> *map_redB;
    QMultiMap<QPushButton*, coord> *map_greenB;
    QMultiMap<QPushButton*, coord> *map_blueB;
    QMultiMap<QPushButton*, coord> *map_blockB;
    QMultiMap<QPushButton*, coord> *map_freeB;

//    QVector<QPushButton*> *vec_redB;
//    QVector<QPushButton*> *vec_greenB;
//    QVector<QPushButton*> *vec_blueB;
//    QVector<QPushButton*> *vec_blockB;
//    QVector<QPushButton*> *vec_freeB;

public:
    GameButtons(QWidget* pwgt = nullptr);

public slots:
    void slotColorButtonClicked();
    void slotFreeButtonClicked();
};

#endif // BUTTONS_H
