#include <QtWidgets>
#include "Buttons.h"

GameButtons::GameButtons(QWidget* pwgt/*= 0*/) : QPushButton(pwgt)
{
    resize(500, 150);
    //setCheckable(true);
    //setChecked(true);

//    m_redB = new QPushButton("&Red");
//    m_greenB = new QPushButton("&Green");
//    m_blueB = new QPushButton("&Blue");
//    connect(m_redB, SIGNAL(clicked()), SLOT(slotButtonClicked()));
//    connect(m_greenB, SIGNAL(clicked()), SLOT(slotButtonClicked()));
//    connect(m_blueB, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    //QPushButton* pcmd = new QPushButton("&Exit");
    //connect(pcmd, SIGNAL(clicked()), qApp, SLOT(quit()));

    //Layout setup

    QGridLayout* pgrdLayout = new QGridLayout;
    pgrdLayout->setContentsMargins(5, 5, 5, 5);
    pgrdLayout->setSpacing(5);

    QLabel* lbl1 = new QLabel("Red");
    QLabel* lbl2 = new QLabel("Green");
    QLabel* lbl3 = new QLabel("Blue");

    pgrdLayout->addWidget(lbl1, 0, 0, Qt::AlignCenter);
    pgrdLayout->addWidget(lbl2, 0, 2, Qt::AlignCenter);
    pgrdLayout->addWidget(lbl3, 0, 4, Qt::AlignCenter);

    QList<QPushButton *> *listB = new QList<QPushButton *>;
    for(int i = 1; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            QPushButton *b = new QPushButton("test");
            pgrdLayout->addWidget(b, i, j);
            listB->append(b);
        }
    }
    //int bCount = 0;

//    for(int i = 0; i < 5; i++)
//    {
//        for(int j = 0; j < 5; j++)
//        {
//            listB[bCount] = new QPushButton;
//            pgrdLayout->addWidget(listB[bCount], i, j);
//            bCount++;
//        }
//    }

//    QPushButton* bArr[15];
//    int bCount = 0;

//    for(int i = 0; i < 5; i++)
//    {
//        for(int j = 0; j < 5; j++)
//        {
//            bArr[bCount] = new QPushButton();
//            pgrdLayout->addWidget(bArr[bCount], i, j);
//            bCount++;
//        }
//    }

//    pgrdLayout->addWidget(m_redB, 0, 0);
//    pgrdLayout->addWidget(m_greenB, 0, 1);
//    pgrdLayout->addWidget(m_blueB, 1, 0);
//    pgrdLayout->addWidget(pcmd, 1, 1);
    setLayout(pgrdLayout);

//    slotButtonClicked();
}

//void GameButtons::slotButtonClicked()
//{
//    QPalette pal = palette();
//    int nLight = 150;
//    if(m_redB->isChecked())
//    {
//        pal.setColor(backgroundRole(), QColor(Qt::red).lighter(nLight));
//    }
//    else if(m_greenB->isChecked())
//    {
//        pal.setColor(backgroundRole(), QColor(Qt::green).lighter(nLight));
//    }
//    else
//    {
//        pal.setColor(backgroundRole(), QColor(Qt::blue).lighter(nLight));
//    }
//    setPalette(pal);
//}
