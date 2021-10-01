#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>

class GameButtons;

// ==========================================

class GameButtons : public QPushButton
{
    Q_OBJECT
private:
    QVector<QPushButton*> *vec_redB;
    QVector<QPushButton*> *vec_greenB;
    QVector<QPushButton*> *vec_blueB;
    QVector<QPushButton*> *vec_blockB;
    QVector<QPushButton*> *vec_freeB;

public:
    GameButtons(QWidget* pwgt = nullptr);

public slots:
    void slotColorButtonClicked();
    void slotFreeButtonClicked();
};

#endif // BUTTONS_H
