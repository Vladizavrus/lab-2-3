#pragma once
#include <cassert>
#include <memory>
#include "ImmutableLinkedList.h"
#include "DynamicArray&List.h"
#include "Heap.h"

void TestSequence(Sequence<int>* sequence) {

    PriorityQueue<int> pq;
    assert(pq.size() == 0);
    pq.Push(4);
    pq.Push(7);
    pq.Push(2);
    pq.Push(9);
    pq.Push(1);
    assert(pq.top() == 9);
    assert(pq.size() == 5);
    pq.Pop();
    assert(pq.size() == 4);
    assert(pq.top() == 7);
    for (int i = 0; i < 4; ++i) {
        pq.Pop();
    }
    assert(pq.size() == 0);
    pq.Push(52);
    pq.Push(73);
    pq.Push(12);
    pq.Push(89);
    pq.Push(11);
    assert(pq.top() == 89);
    pq.Pop();
    assert(pq.top() == 73);
    PriorityQueue<int> pq2 = pq.Map<int>([](int x) {return x * x; });
    assert(pq2.top() == 5329);
    assert(52==52);




    Queue<int> queue;


    assert(queue.Size() == 0);
    queue.PushBack(10);
    queue.PushBack(20);
    queue.PushBack(30);
    assert(queue.Size() == 3);


    assert(queue.front() == 10);
    assert(queue.back() == 30);


    queue.PopFront();
    assert(queue.Size() == 2);
    assert(queue.front() == 20);


    queue.PopBack();
    assert(queue.Size() == 1);
    assert(queue.back() == 20);


    queue.Clear();
    assert(queue.Size() == 0);
    assert(queue.Empty());


    queue.PushBack(10);
    queue.PushBack(20);
    queue.PushBack(30);
    auto even = [](const int& x) { return x % 2 == 0; };
    Queue<int> evenQueue = queue.where(even);
    assert(evenQueue.Size() == 3);
    assert(evenQueue.front() == 10);

    auto square = [](int& x) { x *= x; };
    queue.map(square);
    assert(queue.front() == 100);


    Queue<int> subQueue = queue.GetSubQueue(0, 1);
    assert(subQueue.Size() == 1);
    assert(subQueue.front() == 100);



    ///IMMUTABLELINKEDLIST ASSERTS
    ImmutableLinkedList<int> list1;
    ImmutableLinkedList<int> newList = list1.Insert(0, 10);
    assert(newList.Size() == 1);
    assert(newList[0] == 10);

    newList = newList.Insert(1, 20);
    assert(newList.Size() == 2);
    assert(newList[1] == 20);

    newList = newList.Insert(1, 15);
    assert(newList.Size() == 3);
    assert(newList[1] == 15);
    assert(newList[2] == 20);


    ImmutableLinkedList<int> list2;
    ImmutableLinkedList<int> newList2 = list2.Insert(0, 10);
    newList = newList.Insert(1, 20);
    newList = newList.Insert(2, 30);

    newList = newList.Erase(0);

    assert(newList[0] == 20);
    assert(newList[1] == 30);

    newList = newList.Erase(0);

    assert(newList[0] == 30);

    ///LINKEDLIST ASSERTS
    List<int> list;
    list.PushBack(1);
    list.PushFront(2);
    assert(list.Get(0) == 2);
    assert(list.Get(1) == 1);

    list.PushBack(3);
    list.PushBack(4);
    assert(list.Get(0) == 2);
    assert(list.Get(1) == 1);
    assert(list.Get(2) == 3);
    assert(list.Get(3) == 4);
    assert(list.GetFirst() == 2);
    assert(list.GetLast() == 4);

    list.PushBack(5);
    list.PushBack(6);
    assert(list.Get(0) == 2);
    assert(list.Get(1) == 1);
    assert(list.Get(2) == 3);
    assert(list.Get(3) == 4);
    assert(list.Get(4) == 5);
    assert(list.Get(5) == 6);
    assert(list.GetFirst() == 2);
    assert(list.GetLast() == 6);

    ///DYNAMICARRAY ASSERTS
    DynamicArray<int> dynArray;

    dynArray.PushBack(1);
    dynArray.PushBack(2);
    dynArray.PushBack(3);

    assert(dynArray.Size() == 3);
    assert(dynArray[0] == 1);
    assert(dynArray[1] == 2);
    assert(dynArray[2] == 3);

    dynArray.Clear();

    assert(dynArray.Size() == 0);
    assert(sequence->Size() == 0);

    sequence->PushBack(10);
    sequence->PushBack(20);

    assert((*sequence)[0] == 10);
    assert((*sequence)[1] == 20);

    ///MAIN ASSERTS
    Array<int> array;
    LinkedList<int> linkedlist;
    Sequence<int>* sequence2 = sequence == dynamic_cast<LinkedList<int>*>(sequence) ? static_cast<Sequence<int>*>(&array) : static_cast<Sequence<int>*>(&linkedlist);
    sequence2->PushBack(10);
    sequence2->PushBack(20);

    sequence->Insert(1, 15);
    assert((*sequence)[1] == 15);

    sequence->Insert(0, 5);
    assert((*sequence)[0] == 5);
    assert((*sequence)[1] == 10);
    assert((*sequence)[2] == 15);
    assert((*sequence)[3] == 20);

    sequence->Insert(sequence->Size(), 25);
    assert((*sequence)[sequence->Size() - 1] == 25);

    assert(sequence->Erase(1));
    assert((*sequence)[1] == 15);

    assert(sequence->Erase(0));

    assert(sequence->Erase(sequence->Size() - 1));
    sequence->Clear();
    assert(sequence->Size() == 0);

    assert(sequence->Size() == 0);

    sequence->PushBack(10);
    sequence->PushBack(20);

    assert((*sequence)[0] == 10);
    assert((*sequence)[1] == 20);

    sequence->PopBack();
    assert(sequence->Size() == 1);
    assert((*sequence)[0] == 10);

    sequence->Clear();
    assert(sequence->Size() == 0);

}


