#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>

class GameButtons;

// ==========================================

class GameButtons : public QPushButton
{
    Q_OBJECT
private:
    QPushButton* m_redB;
    QPushButton* m_greenB;
    QPushButton* m_blueB;
    QPushButton* m_blockB;
    QPushButton* m_freeB;

public:
    GameButtons(QWidget* pwgt = nullptr);

//public slots:
    //void slotButtonClicked();
};

#endif // BUTTONS_H
