#include <QtWidgets>
#include "Buttons.h"
#include <ctime>

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

    srand(time(NULL));
    int icon = 0;

//    QVector<QString> color;
//    color << "Red" << "Green" << "Blue" << "Black" << "Grey";

    QVector<QString> imgstr;
    imgstr << ":/Red.jpg" << ":/Green.jpg" << ":/Blue.jpg" << ":/Black" << ":/Grey";

    QVector<QPixmap *> pix;

    for(int i = 0; i < 5; i++)
    {
        QPixmap *p = new QPixmap(imgstr[i]);
        pix << p;
        //ix[i]->load(imgstr[i]);
    }

//    for(int i = 0; i < 5; i++)
//    {
//        qDebug() << *pix[i];
//    }


    QVector<QPushButton *> *vecB = new QVector<QPushButton *>;

    int arrB[5][5];

    for(int i = 1; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            QPushButton *b = new QPushButton();
            icon = rand() % 3;
            arrB[i-1][j] = icon;
            b->setIcon(*pix[icon]);
            b->setIconSize(pix[icon]->size());
            b->setFlat(true);
            b->setCheckable(true);
            pgrdLayout->addWidget(b, i, j);
            vecB->append(b);
        }
    }

    //Black blocks in matrix
    for (int i = 0; i < 5; i+=2)
    {
        arrB[i][1] = arrB[i][3] = 3;
    }

    //Grey free blocks in matrix
    for (int i = 1; i < 5; i+=2)
    {
        arrB[i][1] = arrB[i][3] = 4;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            qDebug() << arrB[i][j];
        }
        qDebug() << Qt::endl;
    }

    //Creating black blocks
    for (int i = 1; i < 24; i+=10)
    {
        vecB->at(i)->setIcon(*pix[3]);
        vecB->at(i)->setFlat(true);
        vecB->at(i)->setCheckable(false);

        vecB->at(i+2)->setIcon(*pix[3]);
        vecB->at(i+2)->setFlat(true);
        vecB->at(i+2)->setCheckable(false);
    }

    //Creating grey free blocks
    for (int i = 6; i < 24; i+=10)
    {
        vecB->at(i)->setIcon(*pix[4]);
        vecB->at(i)->setFlat(true);

        vecB->at(i+2)->setIcon(*pix[4]);
        vecB->at(i+2)->setFlat(true);
    }

//    vecB->at(1)->setIcon(QPixmap(":/Black.jpg"));
//    vecB->at(3)->setIcon(QPixmap(":/Black.jpg"));
//    vecB->at(11)->setIcon(QPixmap(":/Black.jpg"));
//    vecB->at(13)->setIcon(QPixmap(":/Black.jpg"));
//    vecB->at(21)->setIcon(QPixmap(":/Black.jpg"));
//    vecB->at(23)->setIcon(QPixmap(":/Black.jpg"));
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
