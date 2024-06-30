#pragma once
#include <iostream>
#include <stdexcept>
#include "task.h"
template<typename T>
class Heap : public Array<T> {
public:
    void siftDown(size_t i) {
        size_t largest = i;
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if (left < this->Size() && this->operator[](left) > this->operator[](largest)) {
            largest = left;
        }

        if (right < this->Size() && this->operator[](right) > this->operator[](largest)) {
            largest = right;
        }

        if (largest != i) {
            std::swap(this->operator[](i), this->operator[](largest));
            siftDown(largest);
        }
    }
    void siftUp(size_t i){
        while (i > 0 && (*this)[i] > (*this)[(i - 1) / 2]){
            std::swap((*this)[i], (*this)[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
};

template<typename T>
class PriorityQueue : private Heap<T> {
public:
    PriorityQueue() = default;
    //можно построить быстрее чем за O(nlog(n)) строя через siftDown, тогда построение будет за O(n)
    ~PriorityQueue() = default;
    size_t size(){
        return this->Size();
    }
    T top() const {
        if (this->Size() <= 0) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        return (*this)[0];
    }
    void Push(const T& key) {
        this->PushBack(key);
        size_t i = this->Size() - 1;
        this->siftUp(i);
    }
    void Pop(){
        (*this)[0] = (*this)[this->Size() - 1];
        this->Resize(this->Size() - 1);
        this->siftDown(0);
    }
    template<typename U>
    PriorityQueue<U> Map(std::function<U(const T&)> func) const {
        PriorityQueue<U> result;
        for (size_t i = 0; i < this->Size(); ++i) {
            result.Push(func((*this)[i]));
        }
        return result;
    }

    PriorityQueue<T> where(std::function<bool(const T&)> func) const {
        PriorityQueue<T> result;
        for(size_t i = 0; i != this->Size(); ++i){
            if(func((*this)[i])){
                result.Push((*this)[i]);
            }
        }
        return result;
    }

    template<typename U>
    U reduce(std::function<U(const T&, const T&)> func, U c) const {
        U res = c;
        for(int i = 0; i != this->Size(); ++i){
            res = func((*this)[i], res);
        }
        return res;
    }

};
