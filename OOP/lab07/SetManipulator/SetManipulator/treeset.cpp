#include "treeset.h"

using Iterator = TreeSet::Iterator;
using ConstIterator = TreeSet::ConstIterator;

TreeSet::Node::Node(int data, Node* parent, Node* left, Node* right)
    : leftChild(left), rightChild(right), parentNode(parent), data(data)
{}
TreeSet::Node::Node(const Node & other) : parentNode(nullptr), data(other.data)
{
    if (other.leftChild)
    {
        this->leftChild = new Node(*other.leftChild);
        leftChild->parentNode = this;
    }
    else this->leftChild = nullptr;

    if (other.rightChild)
    {
        this->rightChild = new Node(*other.rightChild);
        rightChild->parentNode = this;
    }
    else this->rightChild = nullptr;
}

Iterator::Iterator(TreeSet::Node* startNode) : current(startNode)
{}
ConstIterator::ConstIterator(Node* startNode) : current(startNode)
{}

Iterator& Iterator::operator++()
{
    if (current == nullptr)
        return *this;

    if (current->rightChild)
    {
        current = current->rightChild;
        while (current->leftChild)
            current = current->leftChild;
    }
    else
    {
        while (current->parentNode && current->parentNode->rightChild == current)
            current = current->parentNode;
        current = current->parentNode;
    }

    return *this;
}
Iterator Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}
Iterator& Iterator::operator--()
{
    if (current == nullptr)
        return *this;

    if (current->leftChild)
    {
        current = current->leftChild;
        while (current->rightChild)
            current = current->rightChild;
    }
    else
    {
        while (current->parentNode && current->parentNode->leftChild == current)
            current = current->parentNode;
        current = current->parentNode;
    }

    return *this;
}
Iterator Iterator::operator--(int)
{
    Iterator temp = *this;
    --(*this);
    return temp;
}

ConstIterator& ConstIterator::operator++()
{
    if (current == nullptr)
        return *this;

    if (current->rightChild)
    {
        current = current->rightChild;
        while (current->leftChild)
            current = current->leftChild;
    }
    else
    {
        while (current->parentNode && current->parentNode->rightChild == current)
            current = current->parentNode;
        current = current->parentNode;
    }

    return *this;
}
ConstIterator ConstIterator::operator++(int)
{
    ConstIterator temp = *this;
    ++(*this);
    return temp;
}
ConstIterator& ConstIterator::operator--()
{
    if (current == nullptr)
        return *this;

    if (current->leftChild)
    {
        current = current->leftChild;
        while (current->rightChild)
            current = current->rightChild;
    }
    else
    {
        while (current->parentNode && current->parentNode->leftChild == current)
            current = current->parentNode;
        current = current->parentNode;
    }

    return *this;
}
ConstIterator ConstIterator::operator--(int)
{
    ConstIterator temp = *this;
    --(*this);
    return temp;
}

int& Iterator::operator*() const { return current->data; }
const int& ConstIterator::operator*() const{ return current->data; }

Iterator::operator bool() const
{
    return static_cast<bool>(this->current);
}
ConstIterator::operator bool() const
{
    return static_cast<bool>(this->current);
}

bool operator== (const Iterator& a, const Iterator& b) { return a.current == b.current; };
bool operator!= (const Iterator& a, const Iterator& b) { return a.current != b.current; };
bool operator== (const ConstIterator& a, const ConstIterator& b) { return a.current == b.current; };
bool operator!= (const ConstIterator& a, const ConstIterator& b) { return a.current != b.current; }

TreeSet::Node* TreeSet::minNode(TreeSet::Node* start) const
{
    if (!start || !start->leftChild) return start;
    return minNode(start->leftChild);
}

TreeSet::Node* TreeSet::maxNode(Node *start) const
{
    if(!start || !start->rightChild) return start;
    return maxNode(start->rightChild);
}

void TreeSet::deleteRecursivelyFrom(Node* start)
{
    if (!start) return;

    Node* current = start;
    deleteRecursivelyFrom(start->leftChild);
    deleteRecursivelyFrom(start->rightChild);
    delete current;
}

ConstIterator TreeSet::find(Node* start, int value) const
{
    if (!start || start->data == value) return ConstIterator(start);

    if (value < start->data)
        return find(start->leftChild, value);
    else return find(start->rightChild, value);
}

bool TreeSet::add(Node* start, int value)
{
    if (start->data == value) return false;
    if (value < start->data)
    {
        if (start->leftChild) return add(start->leftChild, value);
        else start->leftChild = new Node(value, start);
        return true;
    }
    else
    {
        if (start->rightChild) return add(start->rightChild, value);
        else start->rightChild = new Node(value, start);
        return true;
    }
}

TreeSet::TreeSet() : head(nullptr), size(0)
{
}

TreeSet::TreeSet(const int size, const int* arr) : TreeSet()
{
    for (int i = 0; i < size; i++)
        this->add(arr[i]);
}

TreeSet::TreeSet(const std::initializer_list<int>& list) : TreeSet()
{
    for (int elem : list)
        this->add(elem);
}

TreeSet::TreeSet(const TreeSet& other) : size(other.size)
{
    head = other.head ? new Node(*other.head) : nullptr;
}

TreeSet::TreeSet(TreeSet && other) : head(other.head), size(other.size)
{
    other.head = nullptr;
    other.size = 0;
}

TreeSet& TreeSet::operator=(const TreeSet& other)
{
    if (&other == this)
        return *this;

    deleteRecursivelyFrom(head);

    size = other.size;
    head = other.head ? new Node(*other.head) : nullptr;

    return *this;
}

TreeSet& TreeSet::operator=(TreeSet&& other)
{
    if(&other == this)
        return *this;

    deleteRecursivelyFrom(head);

    head = other.head;
    size = other.size;

    other.head = nullptr;
    other.size = 0;

    return *this;
}

Iterator TreeSet::find(int value)
{
    if (!head) return Iterator(nullptr);
    return Iterator(find(head, value).current);
}

ConstIterator TreeSet::find(int value) const
{
    if (!head) return ConstIterator(nullptr);
    return find(head, value);
}

void TreeSet::add(int value)
{
    if (!head)
    {
        head = new Node(value);
        size++;
        return;
    }
    if(add(head, value))
        size++;
}

void TreeSet::remove(int value)
{
    Iterator iter = this->find(value);
    if (!iter) return;
    Node* nodeToDelete = iter.current;

    if (!nodeToDelete->leftChild && !nodeToDelete->rightChild)
    {
        Node* parent = nodeToDelete->parentNode;
        if (parent && parent->leftChild == nodeToDelete)
            parent->leftChild = nullptr;
        else if(parent) parent->rightChild = nullptr;

        if (nodeToDelete == head)
            head = nullptr;

        delete nodeToDelete;
    }
    else if (nodeToDelete->leftChild && nodeToDelete->rightChild)
    {
        Node* predecessor = (--iter).current;

        Node* parent = predecessor->parentNode;
        if (parent && parent->leftChild == predecessor)
            parent->leftChild = predecessor->leftChild;
        else parent->rightChild = predecessor->leftChild;

        nodeToDelete->data = predecessor->data;
        delete predecessor;
    }
    else
    {
        Node* child = nodeToDelete->leftChild ? nodeToDelete->leftChild : nodeToDelete->rightChild;

        if (nodeToDelete == head)
        {
            head = child;
            child->parentNode = nullptr;
        }
        else
        {
            Node* parent = nodeToDelete->parentNode;
            if (parent->leftChild == nodeToDelete)
                parent->leftChild = child;
            else
                parent->rightChild = child;
            child->parentNode = parent;
        }
        delete nodeToDelete;
    }
    size--;
}

bool TreeSet::contains(int value) const
{
    return static_cast<bool>(find(value));
}

size_t TreeSet::power() const
{
    return size;
}

int TreeSet::max() const
{
    return maxNode(head)->data;
}

int TreeSet::min() const
{
    return minNode(head)->data;
}

TreeSet TreeSet::unionWith(const TreeSet& other) const
{
    TreeSet result = this->power() > other.power() ? *this : other;

    for (int elem : (this->power() > other.power() ? other : *this))
        result.add(elem);

    return result;
}

TreeSet TreeSet::intersectionWith(const TreeSet& other) const
{
    TreeSet result = this->power() < other.power() ? *this : other;
    const TreeSet& second = this->power() < other.power() ? other : *this;


    for (Iterator iter = result.begin(), copyIter = iter; iter != result.end(); iter = copyIter)
    {
        copyIter++;
        if (!second.contains(*iter))
            result.remove(*iter);
    }

    return result;
}

TreeSet TreeSet::differenceWith(const TreeSet& other) const
{
    TreeSet result = *this;

    for (int elem : other)
        result.remove(elem);

    return result;
}

Iterator TreeSet::begin()
{
    return Iterator(this->minNode(this->head));
}
Iterator TreeSet::end()
{
    return Iterator(nullptr);
}
ConstIterator TreeSet::begin() const
{
    return ConstIterator(this->minNode(this->head));
}
ConstIterator TreeSet::end() const
{
    return ConstIterator(nullptr);
}

TreeSet::~TreeSet()
{
    deleteRecursivelyFrom(head);
}

TreeSet operator+(const TreeSet& a, const TreeSet& b)
{
    return a.unionWith(b);
}
TreeSet operator-(const TreeSet& a, const TreeSet& b)
{
    return a.intersectionWith(b);
}
TreeSet operator/(const TreeSet& a, const TreeSet& b)
{
    return a.differenceWith(b);
}

QTextEdit& operator<<(QTextEdit& edit, const TreeSet& set)
{
    QString string = "{ ";
    for(int elem : set)
        string.append(QString::number(elem) + " ");
    string.append("}");
    edit.setText(edit.toPlainText() + string);

    return edit;
}
QTableWidget& operator<<(QTableWidget& table, const TreeSet& set)
{
    table.setColumnCount(set.power());
    int i = 0;
    for(int elem : set)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(elem));
        table.setItem(0, i++, newItem);
    }

    return table;
}
const QTableWidget& operator>>(const QTableWidget& table, TreeSet& set)
{
    for(int i = 0; i < table.columnCount(); i++)
    {
        set.add(table.item(0, i)->text().toInt());
    }
    return table;
}
