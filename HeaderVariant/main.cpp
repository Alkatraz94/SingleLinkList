#include <iostream>
#include "SingleList.h"

using namespace std;

int main()
{
    SLL<int> *res = new SLL<int>(5);
    res->pushBack(0);
    res->pushBack(3);
    res->pushBack(1);
    res->pushBack(2);
    res->pushBack(4);
    res->sort(-1);
    res->emplace(4, 9);
    delete res;
    res = nullptr;
    return 0;
}