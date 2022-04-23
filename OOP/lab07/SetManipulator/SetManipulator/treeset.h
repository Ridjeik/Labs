#ifndef TREESET_H
#define TREESET_H

#include <stddef.h>
#include <initializer_list>
#include <QTextEdit>
#include <QTableWidget>

class TreeSet
{
private:
    struct Node
    {
        Node* leftChild;
        Node* rightChild;
        Node* parentNode;
        int data;

        Node(int data, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr);
        Node(const Node& other);
    };

    Node* head;
    size_t size;

    Node* minNode(Node* start) const;
    Node* maxNode(Node* start) const;
    void deleteRecursivelyFrom(Node* start);
    bool add(Node* start, int value);

public:
    class Iterator
    {
        Node* current;

    public:

        friend class TreeSet;

        Iterator(Node* startNode);

        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);

        int& operator*() const;

        friend bool operator== (const Iterator& a, const Iterator& b);
        friend bool operator!= (const Iterator& a, const Iterator& b);

        operator bool() const;
    };
    class ConstIterator
    {
        Node* current;

    public:

        friend class TreeSet;

        ConstIterator(Node* startNode);

        ConstIterator& operator++();
        ConstIterator operator++(int);
        ConstIterator& operator--();
        ConstIterator operator--(int);

        const int& operator*() const;

        friend bool operator== (const ConstIterator& a, const ConstIterator& b);
        friend bool operator!= (const ConstIterator& a, const ConstIterator& b);

        operator bool() const;
    };

    TreeSet();
    TreeSet(const int size, const int* arr);
    TreeSet(const std::initializer_list<int>& list);
    TreeSet(const TreeSet& other);
    TreeSet(TreeSet&& other);

    TreeSet& operator=(const TreeSet& other);
    TreeSet& operator=(TreeSet&& other);

    Iterator find(int value);
    ConstIterator find(int value) const;
    void add(int value);
    void remove(int value);
    bool contains(int value) const;
    size_t power() const;
    int max() const;
    int min() const;


    TreeSet unionWith(const TreeSet& other) const;
    TreeSet intersectionWith(const TreeSet& other) const;
    TreeSet differenceWith(const TreeSet& other) const;

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

    ~TreeSet();

    friend QTextEdit& operator<<(QTextEdit& edit, const TreeSet& set);
    friend QTableWidget& operator<<(QTableWidget& table, const TreeSet& set);
    friend const QTableWidget& operator>>(const QTableWidget& table, TreeSet& set);

private:
    ConstIterator find(Node* start, int value) const;
};

TreeSet operator+(const TreeSet& a, const TreeSet& b);
TreeSet operator-(const TreeSet& a, const TreeSet& b);
TreeSet operator/(const TreeSet& a, const TreeSet& b);


#endif // TREESET_H
