#include "SingleList.h"
#include <iostream>

using namespace std;

template <class T>
Node<T>::Node()
{
    key = 0;
    next = nullptr;
}

template <class T>
Node<T>::Node(T key)
{
    this->key = key;
    next = nullptr;
}

template <class T>
Node<T>::Node(T key, Node<T> *next)
{
    this->key = key;
    this->next = next;
}

template <class T>
ostream &operator<<(ostream &out, const Node<T> &n)
{
    if (n.next)
        out << "This node is: " << n.key << ", the next is: " << n.next->key << ", with the address: " << n.next;
    else
        out << "This node is: " << n.key << ", and there isn't a next one";
    return out;
}

template <class T>
bool SLL<T>::getToPos(int pos, Node<T> *&curr)
{
    if (pos == 0)
        return true;
    int currp = 0;
    while (currp != pos - 1)
    {
        if (!curr)
            return false;
        currp++;
        curr = curr->next;
    }
    return true;
}

template <class T>
void SLL<T>::pushFront(T key)
{
    Node<T> *aux = new Node<T>(key, head);
    if (this->isEmpty())
        tail = aux;
    head = aux;
}

template <class T>
void SLL<T>::popFront()
{
    if (!head)
    {
        cerr << "The list is empty!\n";
        return;
    }
    if (tail == head)
    {
        delete head;
        tail = nullptr;
        head = nullptr;
        return;
    }
    Node<T> *toDel = head;
    head = head->next;
    delete toDel;
    toDel = nullptr;
}

template <class T>
SLL<T>* SLL<T>::topFrontNode()
    {
        if (head)
            if (head->next != nullptr)
            {
                cout << "This node is: " << head->key << ", the next is: " << head->next->key << ", with the address: " << head->next << '\n';
                return this;
            }
            else
            {
                cout << "This node is: " << head->key << " and is the single node in the list\n";
                return this;
            }
        cout << "The list is empty!\n";
        return this;
    }

template <class T>
void SLL<T>::pushBack(T key)
{
    Node<T> *aux = new Node<T>(key);
    if (this->isEmpty())
    {
        head = aux;
        tail = aux;
        return;
    }
    tail->next = aux;
    tail = aux;
}

template <class T>
void SLL<T>::popBack()
{
    if (!tail)
    {
        cerr << "The list is empty!\n";
        return;
    }
    if (tail == head)
    {
        delete tail;
        tail = nullptr;
        head = nullptr;
        return;
    }
    Node<T> *curr = head;
    while (curr->next->next)
        curr = curr->next;
    delete tail;
    tail = curr;
    tail->next = nullptr;
}

template <class T>
SLL<T>* SLL<T>::topBackNode()
    {
        if (tail)
        {
            cout << "This is the last element in the list: " << tail->key << " with the adress: " << tail << '\n';
            return this;
        }
        else
            cerr << "!!!The element does not exist!!!\n";
        return this;
    }

template <class T>
bool SLL<T>::isEmpty()
{
    if (!head)
        return true;
    return false;
}

template <class T>
int SLL<T>::size()
{
    int ret = 0;
    Node<T> *curr = head;
    while (curr)
    {
        curr = curr->next;
        ret++;
    }
    return ret;
}

template <class T>
void SLL<T>::resize(int count)
{
    int pos = this->size();
    if (pos == count)
        return;
    if (count < pos)
        this->erase(count, pos);
    if (count > pos)
        this->insert(pos, count - pos, 0);
}

template <class T>
void SLL<T>::resize(int count, T key)
{
    int pos = this->size();
    if (pos == count)
        return;
    if (count < pos)
        this->erase(count, pos);
    if (count > pos)
        this->insert(pos, count - pos, key);
}

template <class T>
bool SLL<T>::inList(T key)
{
    Node<T> *curr = head;
    while (curr->next)
    {
        if (curr->key == key)
            return true;
        curr = curr->next;
    }
    return false;
}

template <class T>
int SLL<T>::find(T key)
{
    unsigned int pos = 0;
    Node<T> *curr = head;
    while (curr)
    {
        if (curr->key == key)
            return pos;
        curr = curr->next;
        pos++;
    }
    return -1;
}

template <class T>
void SLL<T>::emplace(int pos, T key)
{
    if (pos == 0)
    {
        this->pushFront(key);
        return;
    }
    Node<T> *curr = head;
    if (!this->getToPos(pos, curr))
        return;
    Node<T> *toInsert = new Node<T>(key, curr->next);
    curr->next = toInsert;
    if (!toInsert->next)
        tail = toInsert;
}

template <class T>
void SLL<T>::insert(int pos, int count, T key)
{
    if (pos == 0)
    {
        this->pushFront(key);
        Node<T> *curr = head;
        for (int i = 1; i < count; i++)
        {
            Node<T> *toInsert = new Node<T>(key, curr->next);
            curr->next = toInsert;
            curr = curr->next;
        }
        return;
    }
    Node<T> *curr = head;
    if (!this->getToPos(pos, curr))
        return;
    Node<T> *toInsert;
    for (int i = 0; i < count; i++)
    {
        toInsert = new Node<T>(key, curr->next);
        curr->next = toInsert;
        curr = curr->next;
    }
    if (!toInsert->next)
        tail = toInsert;
}

template <class T>
void SLL<T>::insertM(int pos)
{
    Node<T> *curr = head;
    if (!this->getToPos(pos, curr))
        return;
    cout << "How many values do you want to insert: ";
    int count;
    cin >> count;
    Node<T> *toInsert;
    for (int i = 0; i < count; i++)
    {
        T key;
        cin >> key;
        toInsert = new Node<T>(key);
        curr->next = toInsert;
        curr = curr->next;
    }
    if (!toInsert->next)
        tail = toInsert;
}

template <class T>
void SLL<T>::erase(int pos)
{
    if (this->isEmpty())
        return;
    if (pos == 0)
    {
        this->popFront();
        return;
    }
    Node<T> *curr = head;
    if (!this->getToPos(pos, curr))
        return;
    if (!curr->next)
        return;
    Node<T> *toDel = curr->next;
    curr->next = toDel->next;
    delete toDel;
    toDel = nullptr;
    if (!curr->next)
        tail = curr;
}

template <class T>
void SLL<T>::erase(int first, int last)
{
    if (this->isEmpty())
        return;
    int currp = 0;
    if (first == 0)
    {
        while (currp < last)
        {
            this->popFront();
            currp++;
        }
        return;
    }
    Node<T> *curr = head;
    if (!this->getToPos(first, curr))
        return;
    if (!curr->next)
        return;
    while (first + currp < last)
    {
        if (!curr)
            break;
        Node<T> *toDel = curr->next;
        curr->next = toDel->next;
        delete toDel;
        toDel = nullptr;
        currp++;
    }
    if (!curr->next)
        tail = curr;
}

template <class T>
void SLL<T>::empty()
{
    this->erase(0, this->size());
}

template <class T>
void SLL<T>::swap(int first, int second)
{
    if (first == second)
        return;
    if (first == 0)
    {
        Node<T> *aux;
        if (second == 1)
        {
            aux = head->next;
            head->next = aux->next;
            aux->next = head;
            head = aux;
            return;
        }
        Node<T> *curr = head;
        if (!this->getToPos(second, curr))
            return;
        Node<T> *tobeHead = curr->next;
        aux = head->next;
        head->next = curr->next->next;
        curr->next->next = aux;
        curr->next = head;
        if (!head->next)
            tail = head;
        head = tobeHead;
        return;
    }
    Node<T> *curr = head, *curr2 = head;
    if (!this->getToPos(first, curr))
        return;
    if (first + 1 == second)
    {
        curr2 = curr->next;
        curr->next = curr2->next;
        curr = curr->next;
        curr2->next = curr->next;
        curr->next = curr2;
        return;
    }
    if (!this->getToPos(second, curr2))
        return;
    Node<T> *aux1 = curr->next, *aux2 = curr2->next, *b1 = aux1->next;
    aux1->next = aux2->next;
    aux2->next = b1;
    curr->next = aux2;
    curr2->next = aux1;
    if (aux1->next == nullptr)
        tail = aux1;
}

template <class T>
void SLL<T>::swap(SLL<T> *other)
{
    Node<T> *auxh = this->head;
    Node<T> *auxt = this->tail;
    this->head = other->head;
    other->head = auxh;
    this->tail = other->tail;
    other->tail = auxt;
}

template <class T>
void SLL<T>::sort() // Basic, not efficiently
{
    int n = this->size();
    Node<T> *auxi = this->head, *auxb;
    for (int i = 0; i < n - 1; i++)
    {
        Node<T> *auxj = auxi->next, *auxm = auxi;
        int maxx = INT_MAX;
        for (int j = i + 1; j < n; j++)
        {
            if (auxm->key > auxj->key)
            {
                maxx = j;
                auxm = auxj;
            }
            auxj = auxj->next;
        }
        swap(i, maxx);
        if (i == 0)
        {
            auxb = this->head;
            auxi = auxb->next;
            continue;
        }
        auxb = auxb->next;
        auxi = auxb->next;
    }
    while (auxi->next)
        auxi = auxi->next;
    tail = auxi;
}

template <class T>
void SLL<T>::sort(int x) // Basic, not efficiently
{
    if (x != -1)
    {
        this->sort();
        return;
    }
    int n = this->size();
    Node<T> *auxi = this->head, *auxb;
    for (int i = 0; i < n - 1; i++)
    {
        Node<T> *auxj = auxi->next, *auxm = auxi;
        int maxx = INT_MAX;
        for (int j = i + 1; j < n; j++)
        {
            if (auxm->key < auxj->key)
            {
                maxx = j;
                auxm = auxj;
            }
            auxj = auxj->next;
        }
        swap(i, maxx);
        if (i == 0)
        {
            auxb = this->head;
            auxi = auxb->next;
            continue;
        }
        auxb = auxb->next;
        auxi = auxb->next;
    }
    while (auxi->next)
        auxi = auxi->next;
    tail = auxi;
}

template <class T>
SLL<T> &SLL<T>::operator=(const SLL<T> &other)
{
    if (this == &other)
        return *this;
    if (!this->isEmpty())
        this->empty();
    this->pushFront(other.head->key);
    Node<T> *aux = other.head->next, *to = this->head;
    while (aux)
    {
        Node<T> *toIns = new Node<T>(aux->key);
        to->next = toIns;
        to = to->next;
        aux = aux->next;
    }
    this->tail = to;
    return *this;
}

template <class T>
SLL<T>::SLL()
{
    head = nullptr;
    tail = nullptr;
}

template <class T>
SLL<T>::SLL(T key)
{
    head = new Node<T>(key, nullptr);
    tail = head;
}

template <class T>
SLL<T>::SLL(int count, T key)
{
    insert(0, count, key);
}

template <class T>
SLL<T>::SLL(const SLL<T> &other)
{
    this->pushFront(other.head->key);
    Node<T> *aux = other.head->next, *to = this->head;
    while (aux)
    {
        Node<T> *toIns = new Node<T>(aux->key);
        to->next = toIns;
        to = to->next;
        aux = aux->next;
    }
    this->tail = to;
}

template <class T>
SLL<T>::~SLL()
{
    while (this->head)
    {
        Node<T> *auxb = this->head;
        this->head = this->head->next;
        delete auxb;
        auxb = nullptr;
    }
    tail = nullptr;
}

template class SLL<int>;