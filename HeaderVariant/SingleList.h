#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <ostream>

template <class T>
class Node
{
public:
    T key;
    Node<T> *next;
    Node();
    Node(T key);
    Node(T key, Node<T> *next);
    friend std::ostream &operator<<(std::ostream &out, const Node<T> &n);
};

template <class T>
class SLL
{
private:
    bool getToPos(int pos, Node<T> *&curr);

public:
    Node<T> *head;
    Node<T> *tail;
    void pushFront(T key);
    void popFront();
    SLL<T> *topFrontNode();
    void pushBack(T key);
    void popBack();
    SLL<T> *topBackNode();
    bool isEmpty();
    int size();
    void resize(int count);
    void resize(int count, T key);
    bool inList(T key);
    int find(T key);
    void emplace(int pos, T key);
    void insert(int pos, int count, T key);
    void insertM(int pos);
    void erase(int pos);
    void erase(int first, int last);
    void empty();
    void swap(int first, int second);
    void swap(SLL<T> *other);
    void sort();      
    void sort(int x);
    SLL<T> &operator=(const SLL<T> &other);
    SLL();
    SLL(T key);
    SLL(int count, T key);
    SLL(const SLL<T> &other);
    ~SLL();
};

#endif