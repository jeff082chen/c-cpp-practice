

#include <iostream>
#include <string>

struct student {
    std::string ID, name;
    int year, height, weight, Chinese, Mathematics, English;
    
    std::string to_string(void) const {
        return ID + ", " + name + ", " +
               "year: " + std::to_string(year) + ", " +
               "height: " + std::to_string(height) + ", " +
               "weight: " + std::to_string(weight) + ", " +
               "Chinese: " + std::to_string(Chinese) + ", " +
               "Mathematics: " + std::to_string(Mathematics) + ", " +
               "English: " + std::to_string(English);
    }
    
    friend std::istream& operator>> (std::istream& is, student& temp) {
        std::cout << "ID: ";
        is >> temp.ID;
        std::cout << "name: ";
        is >> temp.name;
        std::cout << "year: ";
        is >> temp.year;
        std::cout << "height: ";
        is >> temp.height;
        std::cout << "weight: ";
        is >> temp.weight;
        std::cout << "Chinese: ";
        is >> temp.Chinese;
        std::cout << "Mathematics: ";
        is >> temp.Mathematics;
        std::cout << "English: ";
        is >> temp.English;
        return is;
    }
    
    friend std::ostream& operator<< (std::ostream& os, const student& data) {
        os << data.to_string();
        return os;
    }
};


class List {
protected:
    struct Node {
        student num;
        Node* next;
        Node(void): num(student()), next(nullptr) {}
    };
    
    Node* head;
    int size = 0;
    
public:
    List(void): head(nullptr) {}
    ~List(void);
    List(const List&) = delete;
    List(List&&) = delete;
    List operator= (const List&) = delete;
    List operator= (List&&) = delete;
    
    void push(student new_val);
    void pop(void);
    void print(std::ostream& os = std::cout) const;
};

class list_with_average : public List {
    float ave_year, ave_height, ave_weight, ave_Chinese, ave_Mathematics, ave_English;
    using super = List;
    
    void culculate(void) {
        ave_year = ave_height = ave_weight = ave_Chinese = ave_Mathematics = ave_English = 0;
        Node* node = head;
        while (node != nullptr) {
            ave_year += node->num.year;
            ave_height += node->num.height;
            ave_weight += node->num.weight;
            ave_Chinese += node->num.Chinese;
            ave_Mathematics += node->num.Mathematics;
            ave_English += node->num.English;
            node = node->next;
        }
        ave_year /= size;
        ave_height /= size;
        ave_weight /= size;
        ave_Chinese /= size;
        ave_Mathematics /= size;
        ave_English /= size;
    }
    
public:
    
    void print(std::ostream& os = std::cout) {
        culculate();
        super::print(os);
        os << "Average year: " << ave_year << ", height: " << ave_height << " , weight:" << ave_weight << '\n';
        os << "Average Chinese: " << ave_Chinese << ", Mathematics: " << ave_Mathematics << " , English:" << ave_English << '\n';
    }
    
};


List::~List(void) {
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

void List::push(student new_val) {
    Node* new_node = new Node();
    new_node->num = new_val;
    new_node->next = head;
    head = new_node;
    ++size;
}

void List::pop(void) {
    Node* temp = head;
    head = head->next;
    delete temp;
    --size;
}

void List::print(std::ostream& os) const {
    Node* node = head;
    while (node != nullptr) {
        os << node->num << "\n";
        node = node->next;
    }
}
