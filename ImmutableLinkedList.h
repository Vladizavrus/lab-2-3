#pragma once
template<typename T>
class ImmutableLinkedList{
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& value) : value(value), next(nullptr) {}
    };
    Node* head;
    size_t size_;

public:
    ImmutableLinkedList() : head(nullptr), size_(0) {}

    ~ImmutableLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ImmutableLinkedList(const ImmutableLinkedList& other) : head(nullptr), size_(0) {
        Node* other_current = other.head;
        Node* this_last = nullptr;
        while (other_current) {
            Node* new_node = new Node(other_current->value);
            if (!head) {
                head = new_node;
            } else {
                this_last->next = new_node;
            }
            this_last = new_node;
            other_current = other_current->next;
            ++size_;
        }
    }

    ImmutableLinkedList& operator=(const ImmutableLinkedList& other) {
        if (this == &other) return *this;

        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size_ = 0;

        Node* other_current = other.head;
        Node* this_last = nullptr;
        while (other_current) {
            Node* new_node = new Node(other_current->value);
            if (!head) {
                head = new_node;
            } else {
                this_last->next = new_node;
            }
            this_last = new_node;
            other_current = other_current->next;
            ++size_;
        }

        return *this;
    }

    ImmutableLinkedList Insert(size_t pos, const T& value) const {
        if (pos > size_) {
            throw std::out_of_range("Out of range");
        }
        ImmutableLinkedList result(*this);

        if (pos == 0) {
            Node* newNode = new Node(value);
            newNode->next = result.head;
            result.head = newNode;
            ++result.size_;
            return result;
        }

        Node* current = result.head;
        for (size_t i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
        ++result.size_;

        return result;
    }

    ImmutableLinkedList Erase(size_t pos) const {
        if (pos >= size_) {
            throw std::out_of_range("Out of range");
        }
        ImmutableLinkedList result(*this);

        if (pos == 0) {
            Node* temp = result.head;
            result.head = result.head->next;
            delete temp;
            --result.size_;
            return result;
        }

        Node* current = result.head;
        for (size_t i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        --result.size_;

        return result;
    }

    ImmutableLinkedList PopBack() const {
        if (!head) {
            return *this;
        }
        ImmutableLinkedList result(*this);

        Node* current = result.head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        --result.size_;

        return result;
    }

    size_t Size() const {
        return size_;
    }

    const T& operator[](const size_t i) const {
        if (i >= size_) {
            throw std::out_of_range("Out of range");
        }
        Node* current = head;
        for (size_t j = 0; j < i; ++j) {
            current = current->next;
        }
        return current->value;
    }
};

