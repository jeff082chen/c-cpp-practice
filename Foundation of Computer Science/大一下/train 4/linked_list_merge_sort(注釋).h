

#ifndef LIST_SORT
#define LIST_SORT



#include <iostream>
#include <algorithm>

template <typename T>
class List {

    struct Node { //節點，用於構造鏈結串列
        T num;
        Node* next;
        Node(void): num(T()), next(nullptr) {}
    };

    Node* head;
    void merge(List<T>& right, List<T>& left); //將兩個由小到大排序好的list合併成一個由小到大排序好的list
    void split(List<T>& right, List<T>& left); //將一個list切割成前後兩半

public:
    List(void): head(nullptr) {}
    ~List(void); //解構元，用於在程式結尾釋放List佔用的記憶體空間
    //28~31 禁止使用者對List物件進行任何的複製和搬移
    List(const List<T>&) = delete;
    List(List<T>&&) = delete;
    List<T> operator= (const List<T>&) = delete;
    List<T> operator= (List<T>&&) = delete;

    void push(T new_val); //接收一筆資料並插入在list的最前端
    void print(std::ostream& os = std::cout) const; //輸出list內的所有資料到指定的串流，預設為 std::cout
    void mergeSort(void); //以 merge sort 的方式將整個list由小到大排序
};




//解構元，用於在程式結尾釋放List佔用的記憶體空間
template <typename T>
List<T>::~List(void) {
    // 如果list 沒有任何資料則無需釋放記憶體空間
    if (head == nullptr) return;

    Node* last = head;
    do { //一個一個把所有節點釋放掉
        Node* next = last->next;
        delete last;
        last = next;
    } while (last != nullptr);
}

//接收一筆資料並插入在list的最前端
template <typename T>
void List<T>::push(T new_val) {
    Node* new_node = new Node();
    new_node->num = new_val;
    new_node->next = head;
    head = new_node;
}

//輸出list內的所有資料到指定的串流，預設為 std::cout
template <typename T>
void List<T>::print(std::ostream& os) const {
    Node* node = head;
    while (node != nullptr) {
        os << node->num << "\n";
        node = node->next;
    }
}

//以 merge sort 的方式將整個list由小到大排序
template <typename T>
void List<T>::mergeSort(void) {
    if (head == nullptr || head->next == nullptr) {
        return;  //如果這個list沒有資料或是只有一個資料，則不需要排序
    }
    List right, left;
    //82~85 分割成前後兩半並個別遞迴呼叫 merge sort 函式進行排序，最後將排序好的兩半list重新整合
    split(right, left);
    right.mergeSort();
    left.mergeSort();
    merge(right, left);
}

//以 merge sort 的方式將整個list由小到大排序
template <typename T>
void List<T>::merge(List& right, List& left) {
    Node* current = nullptr;
    //93~98 將 main list 先接上最小的一筆資料
    if (right.head->num > left.head->num) {
        std::swap(right.head, left.head);
    }
    head = right.head;
    current = right.head;
    right.head = right.head->next;
    //100~107 不斷將 right、left list 中較小的資料加入 main list
    while (right.head != nullptr) {
        if (right.head->num > left.head->num) {
            current->next = left.head;
            std::swap(right.head, left.head);
        }
        right.head = right.head->next;
        current = current->next;
    }
    //109~110 將剩下的資料全部加入 main list
    current->next = left.head;
    left.head = nullptr;
}

//將一個list切割成前後兩半
template <typename T>
void List<T>::split(List<T>& right, List<T>& left) {
    Node* hare = head->next;
    Node* tortoise = head;
    //120~126 hare一次往後跑兩格，tortoise一次只跑一格
    //當hare跑到最後一筆資料時，tortoise會剛好在list的正中間
    while (hare != nullptr) {
        hare = hare->next;
        if (hare != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
    }
    //128~131 將 right list 連接上 main list 的前半
    //left list 連接上 main list 的後半
    //最後將前後兩半斷開連接
    right.head = head;
    left.head = tortoise->next;
    tortoise->next = nullptr;
    head = nullptr;
}


#endif
