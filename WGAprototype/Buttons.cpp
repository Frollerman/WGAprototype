#include <QtWidgets>
#include "Buttons.h"
#include <ctime>

void matrixInit(int& icon, int& red, int& green, int& blue, int arrB[][5]);

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

    QLabel* lbl1 = new QLabel("");
    QLabel* lbl2 = new QLabel("");
    QLabel* lbl3 = new QLabel("");

    QPixmap *redPix = new QPixmap(":/Red.jpg");
    lbl1->setPixmap(*redPix);
    QPixmap *greenPix = new QPixmap(":/Green.jpg");
    lbl2->setPixmap(*greenPix);
    QPixmap *bluePix = new QPixmap(":/Blue.jpg");
    lbl3->setPixmap(*bluePix);

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

    //Array of blocks
    int arrB[5][5];

    //Color count
    int red = 0;
    int green = 0;
    int blue = 0;

    matrixInit(icon, red, green, blue, arrB);

    // Debug output
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            qDebug() << arrB[i][j];
        }
        qDebug() << Qt::endl;
    }

    //QVector<QPushButton *> *vecB = new QVector<QPushButton *>;

    QVector<QPushButton*> *vec_redB = new QVector<QPushButton*>;
    QVector<QPushButton*> *vec_greenB = new QVector<QPushButton*>;
    QVector<QPushButton*> *vec_blueB = new QVector<QPushButton*>;
    QVector<QPushButton*> *vec_blockB = new QVector<QPushButton*>;
    QVector<QPushButton*> *vec_freeB = new QVector<QPushButton*>;

    //Adding buttons
    for(int i = 1; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            QPushButton *b = new QPushButton();
            b->setIcon(*pix[arrB[i-1][j]]);
            b->setIconSize(pix[arrB[i-1][j]]->size());
            switch(arrB[i-1][j])
            {
                case 0:
                {
                    b->setFlat(true);
                    b->setCheckable(true);
                    connect(b, SIGNAL(clicked()), SLOT(slotColorButtonClicked()));
                    vec_redB->append(b);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
                case 1:
                {
                    b->setFlat(true);
                    b->setCheckable(true);
                    connect(b, SIGNAL(clicked()), SLOT(slotColorButtonClicked()));
                    vec_greenB->append(b);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
                case 2:
                {
                    b->setFlat(true);
                    b->setCheckable(true);
                    connect(b, SIGNAL(clicked()), SLOT(slotColorButtonClicked()));
                    vec_blueB->append(b);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
                case 3:
                {
                    b->setFlat(true);
                    b->setCheckable(false);
                    vec_blockB->append(b);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
                case 4:
                {
                    b->setFlat(true);
                    b->setCheckable(false);
                    connect(b, SIGNAL(clicked()), SLOT(slotFreeButtonClicked()));
                    vec_freeB->append(b);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
            }

//            QPushButton *b = new QPushButton();
//            b->setIcon(*pix[arrB[i-1][j]]);
//            b->setIconSize(pix[arrB[i-1][j]]->size());
//            b->setFlat(true);
//            b->setCheckable(true);
//            if(arrB[i-1][j] == 3 || arrB[i-1][j] == 4)
//            {
//                b->setCheckable(false);
//            }
//            if(arrB[i-1][j] == 4)
//            {
//                connect(b, SIGNAL(clicked()), SLOT(slotFreeButtonClicked()));
//            }
//            if(arrB[i-1][j] == 0 || arrB[i-1][j] == 1 || arrB[i-1][j] == 2)
//            {
//                connect(b, SIGNAL(clicked()), SLOT(slotColorButtonClicked()));
//            }
//            pgrdLayout->addWidget(b, i, j);
//            //vecB->append(b);
        }
    }

    QLabel* win = new QLabel("");
    pgrdLayout->addWidget(win, 6, 2, Qt::AlignCenter);

    setLayout(pgrdLayout);
}

void matrixInit(int &icon, int &red, int &green, int &blue, int arrB[][5])
{
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
}

void GameButtons::slotColorButtonClicked()
{

//    QPalette pal = palette();
//    int nLight = 150;
//    if(vec_redB[0]->isChecked())
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
}

void GameButtons::slotFreeButtonClicked()
{

}

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
