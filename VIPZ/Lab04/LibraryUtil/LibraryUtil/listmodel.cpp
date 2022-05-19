#include "listmodel.h"
#include <QHeaderView>
#include <QString>

ListModel::ListModel(List *list) : list(list)
{}

ConstListIterator ListModel::begin() const
{
    return ConstListIterator(list->head);
}

ConstListIterator ListModel::end() const
{
    return ConstListIterator(nullptr);
}

size_t ListModel::size() const
{
    size_t res = 0;
    for(auto _ : *this)
        res++;
    return res;
}

QString ListModel::listName() const
{
    return list->name;
}

QTableWidget* ListModel::toTableView() const
{
    QTableWidget* result = new QTableWidget(this->size(), 5);

    result->setHorizontalHeaderLabels({"Автор", "Назва", "Рік видання", "К-ть сторінок", "Ціна($)"});
    result->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

    size_t row = 0;
    for(const Book& book : *this)
    {
        QTableWidgetItem *authorItem = new QTableWidgetItem(QString(book.author.name) + " " + QString(book.author.surname));
        authorItem->setFlags(authorItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *titleItem = new QTableWidgetItem(book.title);
        titleItem->setFlags(titleItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(book.pubYear));
        yearItem->setFlags(yearItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *pageItem = new QTableWidgetItem(QString::number(book.pageCount));
        yearItem->setFlags(yearItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(book.price, 'f', 2));
        priceItem->setFlags(priceItem->flags() ^ Qt::ItemIsEditable);

        result->setItem(row, 0, authorItem);
        result->setItem(row, 1, titleItem);
        result->setItem(row, 2, yearItem);
        result->setItem(row, 3, pageItem);
        result->setItem(row, 4, priceItem);

        row++;
    }

    return result;
}

