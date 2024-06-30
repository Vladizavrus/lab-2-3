#pragma once
#if defined(_LIBCPP_VECTOR) || defined(_LIBCPP_LIST) || defined(_LIBCPP_DEQUE) || defined(_LIBCPP_FORWARD_LIST)
#error "include vector, list or deque forbidden"
#endif
#include "menu.h"
#include "asserts.h"

using namespace std;

int main() {

    cout<<"Testing...\n";

    LinkedList<int> linkedList;
    TestSequence(&linkedList);

    Array<int> array;
    TestSequence(&array);

    cout << "All tests passed successfully!" << endl;

    QueueMenu();


    return 0;
}


