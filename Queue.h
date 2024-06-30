#include "task.h"
#include <functional>
template <typename T>
class Queue{
private:
    LinkedList<T> q;

public:
    Queue() = default;
    ~Queue() = default;
    T& front() const {
        return q.front();
    }
    T& back() const {
        return q.back();
    }
    void PopBack() {
        q.PopBack();
    }
    void PopFront() {
        q.PopFront();
    }
    void PushBack(const T& value) {
        q.PushBack(value);
    }
    Queue operator + (Queue<T> other) {
        Queue<T> temp;
        while(!q.Empty()){
            temp.PushBack(q.front());
            q.PopFront();
        }
        while(!other.q.Empty()){
            temp.PushBack(other.q.front());
            other.q.PopFront();
        }
        return temp;
    }
    Queue operator += (Queue<T> other){
        while(!other.q.Empty()){
            q.PushBack(other.q.front());
            other.q.PopFront();
        }
        return *this;
    }
    Queue GetSubQueue(const size_t i, const size_t j) const {
        Queue temp;
        for (size_t k = i; k < j; ++k) {
            temp.PushBack(q[k]);
        }
        return temp;
    }

    template<typename Function>
    void map(Function func) {
        if(q.Empty()) throw std::out_of_range("Queue is empty");
        for (size_t i = 0; i < q.Size(); ++i) {
            T& element = q[i];
            func(element);
        }
    }

    template<typename Function>
    void map(Function func) const {
        if(q.Empty()) throw std::out_of_range("Queue is empty");
        for (size_t i = 0; i < q.Size(); ++i) {
            const T& element = q[i];
            func(element);
        }
    }

    Queue<T> where(std::function<bool(const T&)> func) const {
        Queue<T> temp;
        for (size_t i = 0; i < q.Size(); ++i) {
            const T& element = q[i];
            if (func(element)) {
                temp.PushBack(element);
            }
        }
        return temp;
    }

    template<typename Function>

    T reduce(const Function& func, const T& c) const {
        T result = c;
        for (size_t i = 0; i < q.Size(); ++i) {
            T el = q[i];
            result = func(el, result);
        }
        return result;
    }


    size_t Size() const {
        return q.Size();
    }

    bool Empty() const {
        return q.Empty();
    }
    void Clear() {
        q.Clear();
    }

};

