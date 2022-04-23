#include "minesweeper.h"
#include "ui_minesweeper.h"
#include <cstdlib>
#include <ctime>
#include <QSizePolicy>


int horizontalSize = 10;
int verticalSize = 10;
int gameOver;
int firstClick;
int bombsCount;
int cellsOpened = 0;
int leftMouseBtnClicked = 0;

QPushButton ***buttons;
int **adjacent;

MineSweeper::MineSweeper(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MineSweeper)
{
    ui->setupUi(this);

    ui->bombCounter->setValue(10);
    ui->widthCounter->setValue(10);
    ui->heightCounter->setValue(10);
    gameOver = 1;
    srand(time(0));

    buttons = new QPushButton**[verticalSize];
    adjacent = new int*[verticalSize];

    for(int i = 0; i < horizontalSize; i++)
    {
        buttons[i] = new QPushButton*[horizontalSize];
        adjacent[i] = new int[horizontalSize];
    }

    for(int i = 0; i < verticalSize; i++)
    {
        for (int j = 0; j < horizontalSize; j++ ) {
            QPushButton *btn = new QPushButton(this);
            btn->setMinimumSize(32, 32);
            btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->gameField->addWidget(btn, i, j);
            buttons[i][j] = btn;
            btn->setDisabled(true);
            adjacent[i][j] = 0;
            connect(btn, SIGNAL(clicked()), this, SLOT(buttonClicked()));
        }
    }

}

MineSweeper::~MineSweeper()
{
    delete ui;
}

void MineSweeper::buttonClicked()
{
    if(gameOver) return;

    int BtnX = -1, BtnY = -1;

    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if(!clickedButton->isEnabled()) return;
    for(int i = 0; i < verticalSize; i++)
    {
        for (int j = 0; j < horizontalSize; j++ ) {
            if(buttons[i][j] == clickedButton)
            {
                BtnY = i;
                BtnX = j;
            }
        }
    }

    qDebug() << "Clicked" << BtnY << BtnX;

    if(firstClick)
    {
        firstClick = 0;
        for(int i = 0; i < bombsCount; i++)
        {
            int x,y;
            do
            {
                x = rand() % horizontalSize;
                y = rand() % verticalSize;
            } while(adjacent[y][x] == -1 || (x == BtnX && y == BtnY));

            adjacent[y][x] = -1;
        }
        for(int i = 0; i < verticalSize; i++)
        {
            for(int j = 0; j < horizontalSize; j++)
            {
                if(adjacent[i][j] == -1) continue;
                int surroundingBombs = 0;
                for(int adjY = std::max(0, i-1); adjY < std::min(verticalSize, i+2); adjY++)
                {
                    for(int adjX = std::max(0, j-1); adjX < std::min(horizontalSize, j+2); adjX++)
                    {
                        if(adjacent[adjY][adjX] == -1) surroundingBombs++;
                    }
                }
                adjacent[i][j] = surroundingBombs;
            }
        }
    }

    if(adjacent[BtnY][BtnX] == -1)
    {
        gameOver = 1;
        ui->statusLabel->setText("Game over!");
        for(int i = 0; i < verticalSize; i++)
        {
            for(int j = 0; j < horizontalSize; j++)
            {
                if(adjacent[i][j] == -1)
                {
                    buttons[i][j]->setText("X");
                }
            }
        }
        return;
    }

    buttons[BtnY][BtnX]->setDisabled(true);
    cellsOpened++;
    if(adjacent[BtnY][BtnX] == 0)
    {
        if(BtnX > 0) buttons[BtnY][BtnX - 1]->click();
        if(BtnX < horizontalSize - 1) buttons[BtnY][BtnX + 1]->click();
        if(BtnY > 0) buttons[BtnY - 1][BtnX]->click();
        if(BtnY < verticalSize - 1) buttons[BtnY + 1][BtnX]->click();
    }
    else
    {
        buttons[BtnY][BtnX]->setText(QString::number(adjacent[BtnY][BtnX]));

        QFont font = buttons[BtnY][BtnX]->font();
        font.setPointSize(adjacent[BtnY][BtnX] * 2 + 6);
        buttons[BtnY][BtnX]->setFont(font);
    }
    if(cellsOpened == verticalSize * horizontalSize - bombsCount)
    {
        gameOver = 1;
        ui->statusLabel->setText("You win!");
        for(int i = 0; i < verticalSize; i++)
        {
            for(int j = 0; j < horizontalSize; j++)
            {
                if(adjacent[i][j] == -1)
                {
                    buttons[i][j]->setText("X");
                }
            }
        }
        return;
    }

}

void MineSweeper::on_newGameButton_clicked()
{
    cellsOpened = 0;
    firstClick = 1;
    gameOver = 0;
    bombsCount = ui->bombCounter->value();
    ui->statusLabel->setText("");

    while (auto item = ui->gameField->takeAt(0))
    {
        ui->gameField->removeItem(item);
        delete item->widget();
    }

    for(int i = 0; i < verticalSize; i++)
    {
        ui->gameField->setRowStretch(i, 0);
    }
    for(int i = 0; i < horizontalSize; i++)
    {
        ui->gameField->setColumnStretch(i, 0);
    }


    for(int i = 0; i < verticalSize; i++)
    {
        delete[] buttons[i];
        delete[] adjacent[i];
    }
    delete[] buttons;
    delete[] adjacent;

    verticalSize = ui->heightCounter->value();
    horizontalSize = ui->widthCounter->value();

    buttons = new QPushButton**[verticalSize];
    adjacent = new int*[verticalSize];

    for(int i = 0; i < verticalSize; i++)
    {
        buttons[i] = new QPushButton*[horizontalSize];
        adjacent[i] = new int[horizontalSize];
    }

    qDebug() << ui->gameField->count();


    for(int i = 0; i < verticalSize; i++)
    {
        ui->gameField->setRowStretch( i, 1);
        for (int j = 0; j < horizontalSize; j++ ) {
            if(i == 0)
                ui->gameField->setColumnStretch(j, 1);
            QPushButton *btn = new QPushButton(this);
            btn->setMinimumSize(32, 32);
            btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

            ui->gameField->addWidget(btn, i, j);
            buttons[i][j] = btn;
            adjacent[i][j] = 0;

            connect(btn, SIGNAL(clicked()), this, SLOT(buttonClicked()));
        }
    }



    for(int i = 0; i < verticalSize; i++)
    {
        for(int j = 0; j < horizontalSize; j++)
        {
            buttons[i][j]->setDisabled(false);
            buttons[i][j]->setText("");
            adjacent[i][j] = 0;
        }
    }
}

