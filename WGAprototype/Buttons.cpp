#include <QtWidgets>
#include "Buttons.h"
#include <ctime>

//int roll()
//{
//    int icon = rand() % 3;
//    return icon;
//}

//void check(int& red, int& green, int& blue, int arrB[][5]);

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

    QVector<QString> imgstr;
    imgstr << ":/Red.jpg" << ":/Green.jpg" << ":/Blue.jpg" << ":/Black" << ":/Grey";

    QVector<QPixmap *> pix;

    for(int i = 0; i < 5; i++)
    {
        QPixmap *p = new QPixmap(imgstr[i]);
        pix << p;
    }

    //For randomizing
    srand(time(NULL));
    int icon = 0;

    //Array of colors
    int arrB[5][5];

    //Color count
    int red = 0;
    int green = 0;
    int blue = 0;

    //Filling matrix with color blocks

    for(int j = 0; j < 5; j+=2)
    {
        for(int i = 0; i < 5; i++)
        {
            icon = rand() % 3;
            if(red < 5 && icon == 0)
            {
                arrB[i][j] = icon;
                red++;
            }
            else if(green < 5 && icon == 1)
            {
                arrB[i][j] = icon;
                green++;
            }
            else if(blue < 5 && icon == 2)
            {
                arrB[i][j] = icon;
                blue++;
            }
            else
            {
                i--;
                continue;
            }
        }
    }

    //check(red, green, blue, arrB);

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

    // Debug output
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            qDebug() << arrB[i][j];
        }
        qDebug() << Qt::endl;
    }


//    //Filling matrix with color blocks
//    for(int i = 0; i < 5; i++)
//    {
//        for(int j = 0; j < 5; j++)
//        {
//            icon = roll();
//            arrB[i][j] = icon;
//        }
//    }

//    for(int i = 0; i < 5; i++)
//    {
//        qDebug() << *pix[i];
//    }

    QVector<QPushButton *> *vecB = new QVector<QPushButton *>;

    for(int i = 1; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            QPushButton *b = new QPushButton();
            b->setIcon(*pix[arrB[i-1][j]]);
            b->setIconSize(pix[arrB[i-1][j]]->size());
            b->setFlat(true);
            b->setCheckable(true);
            pgrdLayout->addWidget(b, i, j);
            vecB->append(b);
        }
    }

//    QVector<QPushButton *> *vecB = new QVector<QPushButton *>;

//    for(int j = 0; j < 5; j+=2)
//    {
//        for(int i = 1; i < 6; i++)
//        {
//            QPushButton *b = new QPushButton();
//            icon = roll();
//            arrB[i-1][j] = icon;
//            b->setIcon(*pix[icon]);
//            b->setIconSize(pix[icon]->size());
//            b->setFlat(true);
//            b->setCheckable(true);
//            pgrdLayout->addWidget(b, i, j);
//            vecB->append(b);
//        }
//    }

//    for(int i = 1; i < 6; i++)
//    {
//        for(int j = 0; j < 5; j++)
//        {
//            QPushButton *b = new QPushButton();
//            icon = roll();
//            arrB[i-1][j] = icon;
//            b->setIcon(*pix[icon]);
//            b->setIconSize(pix[icon]->size());
//            b->setFlat(true);
//            b->setCheckable(true);
//            pgrdLayout->addWidget(b, i, j);
//            vecB->append(b);
//        }
//    }

//    //Creating black blocks
//    for (int i = 1; i < 24; i+=10)
//    {
//        vecB->at(i)->setIcon(*pix[3]);
//        vecB->at(i)->setFlat(true);
//        vecB->at(i)->setCheckable(false);

//        vecB->at(i+2)->setIcon(*pix[3]);
//        vecB->at(i+2)->setFlat(true);
//        vecB->at(i+2)->setCheckable(false);
//    }

//    //Creating grey free blocks
//    for (int i = 6; i < 24; i+=10)
//    {
//        vecB->at(i)->setIcon(*pix[4]);
//        vecB->at(i)->setFlat(true);
//        vecB->at(i)->setCheckable(false);

//        vecB->at(i+2)->setIcon(*pix[4]);
//        vecB->at(i+2)->setFlat(true);
//        vecB->at(i+2)->setCheckable(false);
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

//void check(int& red, int& green, int& blue, int arrB[][5])
//{
//    while(red > 5 || green > 5 || blue > 5)
//    {
//        //Checking if there are more than 5 blocks of each color
//        if(red > 5)
//        {
//            for(int j = 0; j < 5; j+=2)
//            {
//                for(int i = 0; i < 5; i++)
//                {
//                    // if red
//                    if(arrB[i][j] == 0 && green < 5)
//                    {
//                        arrB[i][j] = 1;
//                        --red;
//                        ++green;
//                        break;
//                    }
//                    if(arrB[i][j] == 0 && blue < 5)
//                    {
//                        arrB[i][j] = 2;
//                        --red;
//                        ++blue;
//                        break;
//                    }
//                }
//            }
//        }

//        if(green > 5)
//        {
//            for(int j = 0; j < 5; j+=2)
//            {
//                for(int i = 0; i < 5; i++)
//                {
//                    // if green
//                    if(arrB[i][j] == 1 && red < 5)
//                    {
//                        arrB[i][j] = 0;
//                        --green;
//                        ++red;
//                        break;
//                    }
//                    if(arrB[i][j] == 1 && blue < 5)
//                    {
//                        arrB[i][j] = 2;
//                        --green;
//                        ++blue;
//                        break;
//                    }
//                }
//            }
//        }

//        if(blue > 5)
//        {
//            for(int j = 0; j < 5; j+=2)
//            {
//                for(int i = 0; i < 5; i++)
//                {
//                    // if blue
//                    if(arrB[i][j] == 2 && red < 5)
//                    {
//                        arrB[i][j] = 0;
//                        --blue;
//                        ++red;
//                        break;
//                    }
//                    if(arrB[i][j] == 2 && green < 5)
//                    {
//                        arrB[i][j] = 1;
//                        --blue;
//                        ++green;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//}
