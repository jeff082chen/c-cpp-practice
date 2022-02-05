#ifndef LIST_SORT
#define LIST_SORT

#include <iostream>
#include <utility>
#include <algorithm>

class List {
    
    //Node物件，包含一個整數、一個指標以及一個無參數的建構式
    struct Node {
        int num; //資料
        Node* next; //指向下一筆資料的位置
        Node(void): num(0), next(nullptr) {} //無參數的建構式
    };
    
    Node* head; //指向list的最前端
    void merge(List& right, List& left); //將兩個由小到大排序好的list合併成一個由小到大排序好的list
    std::pair<List, List> split(void); //將一個list切割成前後兩半並回傳兩個新list
    
public:
    List(void): head(nullptr) {} //無參數的建構式
    void push(int new_val); //接收一個整數並插入在list的最前端
    void print(std::ostream& os = std::cout) const; //輸出list內的所有資料到指定的串流，預設為 std::cout
    void mergeSort(void); //以 merge sort 的方式將整個list由小到大排序
};



//接收一個整數並插入在list的最前端
void List::push(int new_val) {
    Node* new_node = new Node(); //產生一個新的Node
    new_node->num = new_val; //將資料填入
    new_node->next = head; //將新的Node指向原先的第一筆資料
    head = new_node; //head改指向新的Node
}

//輸出list內的所有資料到指定的串流
void List::print(std::ostream& os) const {
    Node* node = head; //產生一個指標指向第一筆資料
    while (node != nullptr) { //檢查是否還有資料尚未輸出
        os << node->num << "\n"; //輸出資料到指定串流並換行
        node = node->next; //指向下一筆資料
    }
}

//以 merge sort 的方式將整個list由小到大排序
void List::mergeSort(void) {
    if (head == nullptr || head->next == nullptr) {
        return; //如果這個list沒有資料或是只有一個資料，則不需要排序
    }
    auto result = split(); //將list切割為前後兩半
    result.first.mergeSort(); //遞迴呼叫 merge sort 函式排序前半段list
    result.second.mergeSort(); //遞迴呼叫 merge sort 函式排序後半段list
    merge(result.first, result.second); //將排序好的兩半list重新整合
}

//將兩個由小到大排序好的list合併成一個由小到大排序好的 main list
void List::merge(List& right, List& left) {
    Node* current = nullptr; //用來指向 main list 的尾端
    if(right.head->num > left.head->num) { //如果 right list 的第一筆資料比 left list 的第一筆資料大
        std::swap(right.head, left.head); //交換 right、left list
    }
    head = right.head; //main list 連接上 right list 的頭
    current = right.head;
    right.head = right.head->next; //right list 移動到下一筆資料
    while(right.head != nullptr) { //檢查 right list 是否還有資料剩餘
        if(right.head->num > left.head->num) { //如果 left list 的第一筆資料是較小的那個
            current->next = left.head; //main list 的尾端改指向 left list 的第一筆資料
            std::swap(right.head, left.head); //交換 right、left list
        }
        right.head = right.head->next; //right list 移動到下一筆資料
        current = current->next; //current 指向 main list 新的尾端
    }
    //跳出 while 迴圈表示 right list 已經空了，此時 left list 仍會剩下一筆以上的資料
    current->next = left.head; //將 left list剩下的資料全部接到 main list 的尾端
}

//將 main list 切割成前後兩半並回傳兩個新list
std::pair<List, List> List::split(void) {
    List right, left;
    Node* hare = head->next; //hare指向 main list 的第二個元素
    Node* tortoise = head; //tortoise指向 main list 的第一個元素
    //hare一次往後跑兩格，tortoise一次只跑一格
    //當hare跑到最後一筆資料時，tortoise會剛好在list的正中間
    while (hare != nullptr) {
        hare = hare->next;
        if (hare != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
    }
    right.head = head; //將 right list 的head指向 main list 的第一筆資料
    left.head = tortoise->next; //將 left list 的head指向 main list 的正中間
    tortoise->next = nullptr; //左右兩list斷開連結
    head = nullptr; //main list 和 right list 斷開連結
    return std::make_pair(right, left); //左右兩list打包成一個pair回傳
}

#endif
