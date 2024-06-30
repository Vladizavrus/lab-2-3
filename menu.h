#pragma once
#include "Queue.h"
#include <iostream>

using namespace std;

void PrintMenu() {
    cout << "Queue Menu\n";
    cout << "-----------------------------------\n";
    cout << "1. Add element to back of the queue\n";
    cout << "2. Remove element from back of the queue\n";
    cout << "4. Remove element from front of the queue\n";
    cout << "5. Print elements\n";
    cout << "6. Check if queue is empty\n";
    cout << "7. Get size of the queue\n";
    cout << "8. Clear the queue\n";
    cout << "9. Apply 'where' function\n";
    cout << "10. Apply 'map' function\n";
    cout << "11. Apply 'reduce' function\n";
    cout << "12. Exit\n";
}

void QueueMenu() {
    Queue<int> queue;
    PrintMenu();

    int option;
    while (true) {
        cout << "If you want to show menu again enter 0" << endl;

        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 0:
                PrintMenu();
                break;
            case 1: {
                int value;
                cout << "Enter the element to add to the back of the queue: ";
                cin >> value;
                queue.PushBack(value);
                cout << "Element added to the back.\n";
                break;
            }
            case 2: {
                if (queue.Empty()) {
                    cout << "Queue is empty. Cannot remove from back.\n";
                    break;
                }
                cout << "Removing element from back of the queue...\n";
                queue.PopBack();
                cout << "Element removed from back.\n";
                break;
            }

            case 4: {
                if (queue.Empty()) {
                    cout << "Queue is empty. Cannot remove from front.\n";
                    break;
                }
                cout << "Removing element from front of the queue...\n";
                queue.PopFront();
                cout << "Element removed from front.\n";
                break;
            }
            case 5: {
                if (queue.Empty()) {
                    cout << "Queue is empty.\n";
                    break;
                }
                cout << "Elements in the queue:\n";
                for (size_t i = 0; i < queue.Size(); ++i) {
                    cout << queue.GetSubQueue(i, i + 1).front() << " ";
                }
                cout << endl;
                break;
            }
            case 6: {
                if (queue.Empty()) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Queue is not empty.\n";
                }
                break;
            }
            case 7: {
                cout << "Size of the queue: " << queue.Size() << endl;
                break;
            }
            case 8: {
                queue.Clear();
                cout << "Queue cleared.\n";
                break;
            }
            case 9: {
                if (queue.Empty()) {
                    cout << "Queue is empty. Cannot apply 'where' function.\n";
                    break;
                }
                cout << "Applying 'where' function...\n";
                auto even = [](const int& x) { return x % 2 == 0; };
                auto result = queue.where(even);
                cout << "Elements where function is true:\n";
                for (size_t i = 0; i < result.Size(); ++i) {
                    cout << result.GetSubQueue(i, i + 1).front() << " ";
                }
                cout << endl;
                break;
            }
            case 10: {
                if (queue.Empty()) {
                    cout << "Queue is empty. Cannot apply 'map' function.\n";
                    break;
                }
                cout << "Applying 'map' function...\n";
                auto square = [](int& x) { x *= x; };
                queue.map(square);
                cout << "Elements after applying map function:\n";
                for (size_t i = 0; i < queue.Size(); ++i) {
                    cout << queue.GetSubQueue(i, i + 1).front() << " ";
                }
                cout << endl;
                break;
            }
            case 11: {
                if (queue.Empty()) {
                    cout << "Queue is empty. Cannot apply 'reduce' function.\n";
                    break;
                }
                cout << "Applying 'reduce' function...\n";
                auto sum = [](const int& x, const int& y) { return x + y; };
                int result = queue.reduce(sum, 0);
                cout << "Result of reduce function: " << result << endl;
                break;
            }
            case 12: {
                cout << "Exiting...\n";
                return;
            }
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}
void LinkedListMenu() {
    LinkedList<int> sequence;
    PrintMenu();

    int option;
    while (true) {
        cout << "If you want to show menu again enter 0" << endl;

        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 0:
                PrintMenu();
                break;
            case 1: {
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                sequence.PushBack(value);
                cout << "Element added.\n";
                break;
            }
            case 2: {
                if (sequence.Size() == 0) {
                    cout << "Sequence is empty. Cannot remove.\n";
                    break;
                }
                cout << "Removing last element...\n";
                sequence.PopBack();
                cout << "Element removed.\n";
                break;
            }
            case 3: {
                if (sequence.Size() == 0) {
                    cout << "Sequence is empty.\n";
                    break;
                }
                cout << "Elements in the sequence:\n";
                for (size_t i = 0; i < sequence.Size(); ++i) {
                    cout << sequence[i] << " ";
                }
                cout << endl;
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                size_t index;
                int value;
                cout << "Enter the index to insert: ";
                cin >> index;
                cout << "Enter the value to insert: ";
                cin >> value;
                sequence.Insert(index, value);
                cout << "Element inserted.\n";
                break;
            }
            case 6: {
                size_t index;
                cout << "Enter the index to erase: ";
                cin >> index;
                if (index >= sequence.Size()) {
                    cout << "Invalid index.\n";
                } else {
                    sequence.Erase(index);
                    cout << "Element at index " << index << " erased.\n";
                }
                break;
            }
            case 7: {
                cout << "Exiting...\n";

                return;
            }
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}


void ArrayMenu() {
    Sequence<int>* sequence = new Array<int>();
    PrintMenu();

    int option;
    while (true) {
        cout << "If you want to show menu again enter 0" << endl;

        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 0:
                PrintMenu();
                break;
            case 1: {
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                sequence->PushBack(value);
                cout << "Element added.\n";
                break;
            }
            case 2: {
                if (sequence->Size() == 0) {
                    cout << "Sequence is empty. Cannot remove.\n";
                    break;
                }
                cout << "Removing last element...\n";
                // Приведение типа нужно, чтобы вызвать методы Array
                Array<int> *array = dynamic_cast<Array<int> *>(sequence);
                array->PopBack();
                cout << "Element removed.\n";
                break;
            }
            case 3: {
                if (sequence->Size() == 0) {
                    cout << "Sequence is empty.\n";
                    break;
                }
                cout << "Elements in the sequence:\n";
                for (size_t i = 0; i < sequence->Size(); ++i) {
                    cout << (*sequence)[i] << " ";
                }
                cout << endl;
                break;
            }
            case 4: {
                // Можно пропустить реализацию проверки конструкторов, так как они не влияют на меню
                break;
            }
            case 5: {
                size_t index;
                int value;
                cout << "Enter index to insert: ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                sequence->Insert(index, value);
                cout << "Element inserted.\n";
                break;
            }
            case 6: {
                size_t index;
                cout << "Enter index to erase: ";
                cin >> index;
                sequence->Erase(index);
                cout << "Element erased.\n";
                break;
            }
            case 7: {
                cout << "Exiting...\n";
                delete sequence;
                return;
            }
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}

