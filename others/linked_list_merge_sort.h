

#ifndef LIST_SORT
#define LIST_SORT



#include <iostream>
#include <algorithm>

template <typename T>
class List {
    
    struct Node {
        T num;
        Node* next;
        Node(void): num(T()), next(nullptr) {}
        Node(T num, Node* next): num(num), next(next) {}
    };
    
    Node* head;
    void merge(List<T>& right, List<T>& left);
    void split(List<T>& right, List<T>& left);
    
public:
    List(void): head(nullptr) {}
    ~List(void);
    List(const List<T>&) = delete;
    List(List<T>&&) = delete;
    List<T> operator= (const List<T>&) = delete;
    List<T> operator= (List<T>&&) = delete;
    
    void push(T new_val);
    void print(std::ostream& os = std::cout) const;
    void mergeSort(void);
};





template <typename T>
List<T>::~List(void) {
    if(head == nullptr) {
        return;
    }
    Node* last = head;
    do {
        Node* next = last->next;
        delete last;
        last = next;
    } while(last != nullptr);
}

template <typename T>
void List<T>::push(T new_val) {
    head = new Node(new_val, head);
}

template <typename T>
void List<T>::print(std::ostream& os) const {
    Node* node = head;
    while (node != nullptr) {
        os << node->num << "\n";
        node = node->next;
    }
}

template <typename T>
void List<T>::mergeSort(void) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    List right, left;
    split(right, left);
    right.mergeSort();
    left.mergeSort();
    merge(right, left);
}

template <typename T>
void List<T>::merge(List& right, List& left) {
    Node* current = nullptr;
    if (right.head->num > left.head->num) {
        std::swap(right.head, left.head);
    }
    head = right.head;
    current = right.head;
    right.head = right.head->next;
    while (right.head != nullptr) {
        if (right.head->num > left.head->num) {
            current->next = left.head;
            std::swap(right.head, left.head);
        }
        right.head = right.head->next;
        current = current->next;
    }
    current->next = left.head;
    left.head = nullptr;
}

template <typename T>
void List<T>::split(List<T>& right, List<T>& left) {
    Node* hare = head->next;
    Node* tortoise = head;
    while (hare != nullptr) {
        hare = hare->next;
        if (hare != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
    }
    right.head = head;
    left.head = tortoise->next;
    tortoise->next = nullptr;
    head = nullptr;
}


#endif
