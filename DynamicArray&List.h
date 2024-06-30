#pragma once
///Dynamic Array

template<typename T>
class DynamicArray {
public:
    DynamicArray() : array_() {}

    DynamicArray(const DynamicArray& other) : array_(other.array_) {}

    DynamicArray(size_t size, T defaultValue = 0) : array_(size, defaultValue) {}

    ~DynamicArray() {}

    size_t Size() const {
        return array_.Size();
    }

    void Resize(size_t newSize) {
        array_.Resize(newSize);
    }

    void PushBack(const T& value = 0) {
        array_.PushBack(value);
    }

    void PopBack() {
        array_.PopBack();
    }

    const T& operator[](const size_t i) const {
        return array_[i];
    }

    T& operator[](const size_t i) {
        return array_[i];
    }

    bool Empty() const {
        return array_.Size() == 0;
    }

    void Clear() {
        array_.Clear();
    }

private:
    Array<T> array_;
};


///List
template<typename T>
class List{
private:
    LinkedList<T> list;
public:
    List() = default;
    List(const List<T>& other) {
        list = other.list;
    }
    ~List() = default;

    void PushBack(const T& value) {
        list.PushBack(value);
    }
    void PopBack() {
        list.PopBack();
    }
    T Get(size_t i) const {
        return list[i];
    }
    size_t Size() const {
        return list.Size();
    }
    void Clear() {
        list.Clear();
    }
    T GetFirst() const {
        return list[0];
    }
    T GetLast() const {
        return list[list.Size() - 1];
    }
    List<T>* GetSubList(size_t start, size_t end) {
        return new List<T>(list.GetSubList(start, end));
    }
    size_t GetLenght() const {
        return list.Size();
    }
    void PushFront(const T& value) {
        list.Insert(0, value);
    }
    void Insert(size_t pos, const T& value) {
        list.Insert(pos, value);
    }
    void Erase(size_t pos) {
        list.Erase(pos);
    }
    List<T>& operator=(const List<T>& other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }
};