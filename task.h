#pragma once
#include <iostream>


///SEQUENCE CLASS IMPLEMENTATION
template<typename T>
class Sequence {
public:
    virtual ~Sequence() = default;
    virtual size_t Size() const = 0;
    virtual void Clear() = 0;
    virtual void PushBack(const T& value) = 0;
    virtual bool Erase(size_t pos) = 0;
    virtual void Insert(size_t pos, const T& value) = 0;
    virtual T& operator[](const size_t i) = 0;
    virtual const T& operator[](const size_t i) const = 0;
    virtual void PopBack() = 0;
};

// LinkedList<T>::LinkedList() - конструктор класса LinkedList, инициализирует указатель на голову списка и размер списка.
// LinkedList<T>::~LinkedList() - деструктор класса LinkedList, освобождает память, занимаемую всеми узлами списка.
// void LinkedList<T>::PopBack() - удаляет последний элемент списка.
// void LinkedList<T>::PushBack(const T& value) - добавляет элемент в конец списка.
// size_t LinkedList<T>::Size() const - возвращает текущий размер списка.
// void LinkedList<T>::Clear() - очищает список, освобождая память, занимаемую всеми узлами списка.
// void LinkedList<T>::Insert(size_t pos, const T& value) - вставляет элемент на заданную позицию в списке.
// bool LinkedList<T>::Erase(size_t pos) - удаляет элемент из списка по указанной позиции.
// bool LinkedList<T>::operator==(const LinkedList& it) const - перегруженный оператор равенства для списков.
// bool LinkedList<T>::operator!=(const LinkedList& it) const - перегруженный оператор неравенства для списков.
// bool LinkedList<T>::operator<(const LinkedList& it) const - перегруженный оператор "меньше" для списков.
// bool LinkedList<T>::operator>(const LinkedList& it) const - перегруженный оператор "больше" для списков.
// bool LinkedList<T>::operator<=(const LinkedList& it) const - перегруженный оператор "меньше или равно" для списков.
// bool LinkedList<T>::operator>=(const LinkedList& it) const - перегруженный оператор "больше или равно" для списков.
// T& LinkedList<T>::operator[](const size_t i) - перегруженный оператор доступа к элементу списка по индексу.
// const T& LinkedList<T>::operator[](const size_t i) const - перегруженный оператор доступа к элементу списка по индексу для константного объекта.
// friend std::ostream& operator<<(std::ostream& ostream, const LinkedList& list) - перегруженный оператор вывода для списка в поток вывода.
// Node - вложенная структура, представляющая узел списка, содержащая значение элемента и указатель на следующий узел.


///LINKED LIST CLASS IMPLEMENTATION
///LINKED LIST CLASS IMPLEMENTATION
///LINKED LIST CLASS IMPLEMENTATION
///LINKED LIST CLASS IMPLEMENTATION
///LINKED LIST CLASS IMPLEMENTATION
template<typename T>
class LinkedList : public Sequence<T>{
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& value) : value(value), next(nullptr) {
        }
    };
    Node* head;
    size_t size_ = 0;
public:

    LinkedList() : head(nullptr), size_(0){}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size_ = 0;
    }
    T& front() const {
        if (!head) {
            throw std::out_of_range("Out of range");
        }
        return head->value;
    }
    T& back() const {
        if (!head) {
            throw std::out_of_range("Out of range");
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        return current->value;
    }
    void PopBack() {
        if(!head) {
            return;
        }
        Node* current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;

        --size_;
    }
    void PushFront(const T& value) {
        head = new Node(value);
        head->next = this->head;
        ++size_;
    }
    void PopFront() {
        if (!head) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        --size_;
    }

    void PushBack(const T& value) {
        if (!head) {
            head = new Node(value);
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(value);
        }
        ++size_;
    }
    size_t Size() const  {
        return size_;
    }

    void Clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size_ = 0;
    }

    void Insert(size_t pos, const T& value)  {
        if (pos > size_) {
            throw std::out_of_range("Out of range");
        }
        if (pos == 0) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (size_t i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            Node* newNode = new Node(value);
            newNode->next = current->next;
            current->next = newNode;
        }
        ++size_;
    }
    bool Empty() const  {
        return size_ == 0;
    }

    bool Erase(size_t pos)  {
        if (pos >= size_) {
            throw std::out_of_range("Out of range");
        }
        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (size_t i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        --size_;
        return true;
    }


    bool operator==(const LinkedList& it) const {
        if (size_ != it.size_) return false;
        Node* current = head;
        Node* it_current = it.head;
        while (current) {
            if (current->value != it_current->value) return false;
            current = current->next;
            it_current = it_current->next;
        }
        return true;
    }
    bool operator!=(const LinkedList& it) const {
        return !(*this == it);
    }

    bool operator<(const LinkedList& it) const {
        size_t mini = std::min(it.size_, size_);
        for (size_t i = 0; i < mini; ++i) {
            if ((*this)[i] < it[i]) {
                return true;
            }
        }
        return false;
    }

    bool operator>(const LinkedList& it) const {
        return it < *this;
    }

    bool operator<=(const LinkedList& it) const {
        return !(*this > it);
    }

    bool operator>=(const LinkedList& it) const {
        return !(*this < it);
    }

    T& operator[](const size_t i) {
        Node* current = head;
        for (size_t j = 0; j < i; ++j) {
            current = current->next;
        }
        return current->value;
    }
//int a = ll[3]
    const T& operator[](const size_t i) const {
        Node* current = head;
        for (size_t j = 0; j < i; ++j) {
            current = current->next;
        }
        return current->value;
    }

    friend std::ostream& operator<<(std::ostream& ostream, const LinkedList& list) {
        ostream << "Result LinkedList's size is " << list.size_ << ", elements are: ";
        Node* current = list.head;
        while (current) {
            ostream << current->value << ", ";
            current = current->next;
        }
        return ostream;
    }

};

//PushBack(T)
//Size()
//Resize(size_t)
//Reserve(size_t)
//PopBack(size_t)
//operator [] (size_t)
//operator << (T)
//operator << (ostream&, const Array<T>&)
//operator bool
//Clear() - очищает массив
//void Insert(size_t pos, const T& value) - вставляет элемент value на позицию pos. pos = 0 означает вставку в начало, pos = Size означает вставку в конец. Если pos > Size, то возвращает ошибку
//void Erase(size_t pos) - удаляет элемент на позиции pos. Если в массиве недостаточно элементов, то возвращает ошибку.
//operator < (const Array<T>&) - оператор лексикографического сравнения на меньше.



///ARRAY CLASS IMPLEMENTATION
///ARRAY CLASS IMPLEMENTATION
///ARRAY CLASS IMPLEMENTATION
///ARRAY CLASS IMPLEMENTATION
template<typename T>
class Array : public Sequence<T>{
public:
    Array() : size_(0),capacity_(2), val(new T[2]) {
    }

    Array(const Array& array) :  size_(array.size_), capacity_(array.capacity_), val(new T[capacity_]) {
        std::copy(array.val, array.val + size_, val);
    }

    Array(size_t size, T defaultValue = 0) :  size_(size), capacity_(size * 2), val(new T[capacity_]) {
        for (size_t i = 0; i < size; ++i) {
            val[i] = defaultValue;
        }
    }

    ~Array() {
        delete[] val;
    }

    size_t Size() const {
        return size_;
    }

    size_t Capacity() const {
        return capacity_;
    }

    void Reserve(size_t newCapacity) {
        if (newCapacity <= capacity_) {
            return;
        }
        T* tmp = new T[newCapacity];
        std::copy(val, val + size_, tmp);
        delete[] val;
        val = tmp;
        capacity_ = newCapacity;
    }

    void Resize(size_t newSize) {
        if (newSize == size_) return;
        if (newSize > capacity_) Reserve(newSize * 2);
        if (newSize < size_) {
            for (size_t i = newSize; i < size_; ++i) {
                val[i].~T();
            }
        }
        size_ = newSize;
    }

    void PushBack(const T& value = 0) {
        if (size_ == capacity_) {
            Reserve(capacity_ * 2);
        }

        val[size_++] = value;
    }

    void PopBack() {
        if (size_ == 0) {
            throw std::out_of_range("Empty array");
        }
        val[--size_].~T();
    }

    const T& operator[](const size_t i) const {
        return val[i];
    }

    T& operator[](const size_t i) {
        return val[i];
    }

    explicit operator bool() const {
        return size_ > 0;
    }

    bool operator<(const Array& it) const {
        size_t mini = std::min(it.size_, size_);
        for (size_t i = 0; i < mini; ++i) {
            if ((*this)[i] < it[i]) {
                return true;
            }
        }
        return false;
    }
    void operator = (const Array& it) {
        size_ = it.size_;
        capacity_ = it.capacity_;
        delete[] val;
        val = new T[capacity_];
        std::copy(it.val, it.val + size_, val);
    }
    bool operator>(const Array& it) const {
        return it < *this;
    }

    bool operator!=(const Array& it) const {
        return !(*this == it);
    }

    bool operator==(const Array& it) const {
        if (size_ != it.size_) return false;
        for (size_t i = 0; i < size_; ++i) {
            if ((*this)[i] != it[i]) return false;
        }
        return true;
    }

    bool operator<=(const Array& it) const {
        return !(*this > it);
    }

    bool operator>=(const Array& it) const {
        return !(*this < it);
    }

    Array& operator<<(const T& value) {
        PushBack(value);
        return *this;
    }

    Array& operator<<(const Array& it) {
        size_t temp = size_;
        Resize(size_ + it.size_);
        for (size_t i = temp; i < size_; ++i) {
            (*this)[i] = it[i - temp];
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& ostream, const Array& array) {
        ostream << "Result Array's capacity is " << array.capacity_ << " and size is " << array.size_ << ", elements are: ";
        for (size_t i = 0; i < array.size_; ++i) {
            ostream << array[i] << ", ";
        }
        return ostream;
    }
    friend std::istream& operator >> (std::istream& istream, const Array& array) {
        int n;
        std::cin>> n;
        for(int i = 0; i < n; ++i) {
            std::cin >> array[i];
        }
        return istream;
    }

    void Insert(size_t pos, const T& value) {
        if (pos > size_) {
            throw std::out_of_range("Out of range");
        }
        if (size_ == capacity_) {
            Reserve(capacity_ * 2);
        }
        for (size_t i = size_; i > pos; --i) {
            val[i] = val[i - 1];
        }
        val[pos] = value;
        ++size_;
    }

    bool Erase(size_t pos) {
        if (pos >= size_) {
            throw std::out_of_range("Out of range");
        }
        for (size_t i = pos; i < size_ - 1; ++i) {
            val[i] = val[i + 1];
        }
        --size_;
        return true;
    }

    void Clear() {
        delete[] val;
        val = new T[capacity_];
        size_ = 0;
    }

private:
    size_t size_;
    size_t capacity_;
    T* val;
};

template<typename T>
std::ostream& operator<<(std::ostream& ostream, const Array<T>& array) {
    ostream << "Result Array's capacity is " << array.capacity_ << " and size is " << array.size_ << ", elements are: ";
    for (size_t i = 0; i < array.size_; ++i) {
        ostream << array[i] << ", ";
    }
    return ostream;
}
