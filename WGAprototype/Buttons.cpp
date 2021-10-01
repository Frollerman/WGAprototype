#include <QtWidgets>
#include "Buttons.h"
#include <ctime>

void matrixInit(int& icon, int& red, int& green, int& blue, int arrB[][5]);

//void check(int& red, int& green, int& blue, int arrB[][5]);

bool color_checked;
coord colorButtonPos;

//Array of blocks
int arrB[5][5];

GameButtons::GameButtons(QWidget* pwgt/*= 0*/) : QPushButton(pwgt)
{
    resize(500, 150);

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

//    vec_redB = new QVector<QPushButton*>;
//    vec_greenB = new QVector<QPushButton*>;
//    vec_blueB = new QVector<QPushButton*>;
//    vec_blockB = new QVector<QPushButton*>;
//    vec_freeB = new QVector<QPushButton*>;

//    coordRed = new QVector<coord>;
//    coordGreen = new QVector<coord>;
//    coordBlue = new QVector<coord>;
//    coordBlock = new QVector<coord>;
//    coordFree = new QVector<coord>;

//    map_redB = new QMultiMap<QPushButton*, coord>;
//    map_greenB = new QMultiMap<QPushButton*, coord>;
//    map_blueB = new QMultiMap<QPushButton*, coord>;
//    map_blockB = new QMultiMap<QPushButton*, coord>;
//    map_freeB = new QMultiMap<QPushButton*, coord>;

    //Adding buttons
    for(int i = 1; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            PlayButton *b = new PlayButton();
            b->setIcon(*pix[arrB[i-1][j]]);
            b->setIconSize(pix[arrB[i-1][j]]->size());
            b->setFlat(true);
            b->pos.i = i-1;
            b->pos.j = j;
            switch(arrB[i-1][j])
            {
                case 0:
                {
                    b->setCheckable(true);
                    b->color = "Red";
                    b->colorNum = 0;
                    connect(b, SIGNAL(clicked()), SLOT(slotColorButtonClicked()));
//                    vec_redB->append(b);
//                    coordRed->append(pair);
//                    map_redB->insert(b, pair);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
                case 1:
                {
                    b->setCheckable(true);
                    b->color = "Green";
                    b->colorNum = 1;
                    connect(b, SIGNAL(clicked()), SLOT(slotColorButtonClicked()));
//                    vec_greenB->append(b);
//                    coordGreen->append(pair);
//                    map_greenB->insert(b, pair);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
                case 2:
                {
                    b->setCheckable(true);
                    b->color = "Blue";
                    b->colorNum = 2;
                    connect(b, SIGNAL(clicked()), SLOT(slotColorButtonClicked()));
//                    vec_blueB->append(b);
//                    coordBlue->append(pair);
//                    map_blueB->insert(b, pair);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
                case 3:
                {
                    b->setCheckable(false);
                    b->color = "Black";
                    b->colorNum = 3;
//                    vec_blockB->append(b);
//                    coordBlock->append(pair);
//                    map_blockB->insert(b, pair);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
                case 4:
                {
                    b->setCheckable(false);
                    b->color = "Grey";
                    b->colorNum = 4;
                    connect(b, SIGNAL(clicked()), SLOT(slotFreeButtonClicked()));
//                    vec_freeB->append(b);
//                    coordFree->append(pair);
//                    map_freeB->insert(b, pair);
                    pgrdLayout->addWidget(b, i, j);
                    break;
                }
            }
        }
    }

    QLabel* win = new QLabel("");
    pgrdLayout->addWidget(win, 6, 2, Qt::AlignCenter);

    setLayout(pgrdLayout);
    //pwgt->update();
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

void PlayButton::slotColorButtonClicked()
{
    if(this->colorNum == 0 && color_checked == false)
    {
        this->isChecked();
        color_checked = true;
        colorButtonPos = this->pos;
    }
    else if(this->colorNum == 1 && color_checked == false)
    {
        this->isChecked();
        color_checked = true;
        colorButtonPos = this->pos;
    }
    else if(this->colorNum == 2 && color_checked == false)
    {
        this->isChecked();
        color_checked = true;
        colorButtonPos = this->pos;
    }
    else
    {
        color_checked = false;
    }

}

void PlayButton::slotFreeButtonClicked()
{
    if(color_checked)
    {
        coord temp;
        temp = this->pos;
        this->pos = colorButtonPos;
        colorButtonPos = temp;
    }
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
