//
// RBT_Insert_Delete.cpp
// C++ code, harshly and successfully compiled by g++
//

#include <iostream>
#include <sstream>

class RBT{
    
    struct TreeNode {
        
        enum class Color {
            red, black
        };
        
        TreeNode* leftchild;
        TreeNode* rightchild;
        TreeNode* parent;
        
        int key;
        Color color;
        
        bool isBlack(void) const { return this->color == Color::black; };
        bool isRed(void) const { return this->color == Color::red; };
        
        bool siblingIsRight(void) { return this == this->parent->leftchild; };
        
        TreeNode(void): leftchild(nullptr), rightchild(nullptr), parent(nullptr), key(0), color(Color::red) {}
        
        TreeNode(int key): leftchild(nullptr), rightchild(nullptr), parent(nullptr), key(key), color(Color::red) {}
        
        int GetKey(void) const { return key; };
    };
    
    friend void printBT(const std::string& prefix, const TreeNode* node, bool isLeft, std::ostream& os);
    
    using Color = TreeNode::Color;

    TreeNode* root;
    TreeNode* neel;

    void LeftRotation(TreeNode* current);
    void RightRotation(TreeNode* current);
    
    void InsertFixedUpRBT(TreeNode* current);
    void InsertCase1(TreeNode*& current);
    void InsertCase2(TreeNode*& current);
    void InsertCase3(TreeNode*& current);
    
    void DeleteFixedUpRBT(TreeNode* current);
    void DeleteCase1(TreeNode*& current, TreeNode*& sibling);
    void DeleteCase2(TreeNode*& current, TreeNode*& sibling);
    void DeleteCase3(TreeNode*& current, TreeNode*& sibling);
    void DeleteCase4(TreeNode*& current, TreeNode*& sibling);
    
    TreeNode* Sibling(TreeNode* current);
    TreeNode* Successor(TreeNode* current);       // called by DeleteRBT()
    TreeNode* Leftmost(TreeNode* current);     // called by Successor()
    
    TreeNode* Search(int key);   // called by DeleteRBT()

public:
    
    RBT(void) {
        neel = new TreeNode;    // neel 需要配置記憶體
        neel->color = Color::black;        // neel 是黑色
        neel->key = -1;
        root = neel;            // 為了insert, 要把root 初始化成neel
        root->parent = neel;
    };
    
    void DestroyRecursive(TreeNode* node) {
        if (node) {
            DestroyRecursive(node->leftchild);
            DestroyRecursive(node->rightchild);
            delete node;
        }
    }

    ~RBT(void) {
        DestroyRecursive(this->root);
    }
    
    RBT(const RBT&) = delete;
    RBT(RBT&&) = delete;
    RBT& operator= (const RBT&) = delete;
    RBT& operator= (RBT&&) = delete;
    
    void InsertRBT(int key);
    void DeleteRBT(int key);

    bool exist(int key) { return Search(key) != nullptr; };
    
    void print(std::ostream& os = std::cout) {
        printBT("", this->root, false, os);
    }
    
    std::string to_string(void) {
        std::ostringstream os;
        this->print(os);
        return os.str();
    }
};



void RBT::DeleteRBT(int key) {
    
    // check if key already exist
    TreeNode* delete_node = Search(key);
    if (delete_node == nullptr) {
        std::cerr << "data not found.\n";
        return;
    }

    // make target (the note that actually deleted) has at most one child
    TreeNode* target = nullptr;
    bool has_two_child(!(delete_node->leftchild == neel || delete_node->rightchild == neel));
    target = has_two_child ? Successor(delete_node) : delete_node;
    
    // if left and right child both not neel, take left
    // if left is neel, take right
    // (if both are neel, this program will take right, it's actually doesn't matter)
    TreeNode* target_child = target->leftchild;
    if (target->leftchild == neel) {
        target_child = target->rightchild;
    }

    // update parent of taget_child
    target_child->parent = target->parent;
    
    // if target is root
    if (target == this->root) this->root = target_child;
    
    // target if left child
    else if (target == target->parent->leftchild) target->parent->leftchild = target_child;
    
    // target if left child
    else target->parent->rightchild = target_child;
        
    // case 3, target is not delete_note
    if (target != delete_node) {
        delete_node->key = target->key;
    }

    // 若刪除的node是黑色, 要從x進行修正, 以符合RBT的顏色規則
    if (target->isBlack()) {
        DeleteFixedUpRBT(target_child);
    }
    
    delete target;
}

void RBT::DeleteFixedUpRBT(TreeNode* current) {
    
    while (current != root && current->isBlack()) {
        
        TreeNode* sibling = Sibling(current);
        
        // Case 1
        if (sibling->isRed()) {
            DeleteCase1(current, sibling);
        } // possible lead to Case 2, 3, 4
        
        // Case 2
        if (sibling->leftchild->isBlack() && sibling->rightchild->isBlack()) {
            DeleteCase2(current, sibling);  // 若current更新到root, 即跳出迴圈
            continue;
        } // possible repeat or done
        
        // Case 3
        if (current->siblingIsRight() && sibling->rightchild->isBlack()){
            DeleteCase3(current, sibling);
        } // always leads to Case 4
        
        // Case 3
        if (!current->siblingIsRight() && sibling->leftchild->isBlack()){
            DeleteCase3(current, sibling);
        } // always leads to Case 4
        
        // Case 4, than it's done
        DeleteCase4(current, sibling);
    }
    
    current->color = Color::black;
}

void RBT::DeleteCase1(TreeNode*& current, TreeNode*& sibling) {
    
    sibling->color = Color::black;
    current->parent->color = Color::red;
    
    if (current->siblingIsRight()) LeftRotation(current->parent);
    else RightRotation(current->parent);
    
    sibling = Sibling(current);
}

void RBT::DeleteCase2(TreeNode*& current, TreeNode*& sibling) {
    
    sibling->color = Color::red;
    current = current->parent;
}

void RBT::DeleteCase3(TreeNode*& current, TreeNode*& sibling) {
    
    if (current->siblingIsRight()) sibling->leftchild->color = Color::black;
    else sibling->rightchild->color = Color::black;
    
    sibling->color = Color::red;
    
    if (current->siblingIsRight()) RightRotation(sibling);
    else LeftRotation(sibling);
    
    sibling = Sibling(current);
}

void RBT::DeleteCase4(TreeNode*& current, TreeNode*& sibling) {
    
    sibling->color = current->parent->color;
    current->parent->color = Color::black;
    
    if (current->siblingIsRight()) sibling->rightchild->color = Color::black;
    else sibling->leftchild->color = Color::black;
    
    if (current->siblingIsRight()) LeftRotation(current->parent);
    else RightRotation(current->parent);
    
    current = this->root;
    current->color = Color::black;
}


void RBT::InsertRBT(int key) {
    // 前半部與 InsertBST()之邏輯完全相同, 僅僅需要修改 NULL <-> NIL
    TreeNode* current_parent = neel;
    TreeNode* current = root;
    TreeNode* insert_node = new TreeNode(key);
    
    if (Search(key) != nullptr) {
        std::cerr << "data already exists.\n";
        return;
    }

    while (current != neel) {     // 把root初始化成neel, 這裡就可以用neel來做判斷
        
        current_parent = current;
        
        if (key < current->key) current = current->leftchild;
        else current = current->rightchild;
    }

    insert_node->parent = current_parent;

    
    if (current_parent == neel) {
        this->root = insert_node;
        insert_node->color = Color::black;
    }
    
    else if (insert_node->key < current_parent->key) current_parent->leftchild = insert_node;
        
    else current_parent->rightchild = insert_node;
    
    
    // 以下是對RBT之node的設定, 將child pointer指向NIL, 顏色設為紅色
    insert_node->leftchild = neel;
    insert_node->rightchild = neel;
    
    if (current_parent->color == Color::red)
        InsertFixedUpRBT(insert_node);   // 對可能出現紅色與紅色node相連之情形做修正
}



void RBT::InsertFixedUpRBT(TreeNode* current){

    // case0: parent是黑色, 就不用進回圈
    while (current->parent->color == Color::red) {   // 若parent是紅色即進入迴圈
        
        TreeNode* uncle = Sibling(current->parent);
        
        if (uncle->color == Color::red) {
            InsertCase1(current);
            continue;
        }
        
        if (current->siblingIsRight() xor current->parent->siblingIsRight()) {
            InsertCase2(current);
        }
        
        InsertCase3(current);
    }
    
    root->color = Color::black;    // 確保root是黑色
}

void RBT::InsertCase1(TreeNode*& current) {
    
    current->parent->color = Color::black;
    Sibling(current->parent)->color = Color::black;
    current->parent->parent->color = Color::red;
    current = current->parent->parent;
}

void RBT::InsertCase2(TreeNode*& current) {
    
    current = current->parent;
    
    if (current->siblingIsRight()) LeftRotation(current);
    else RightRotation(current);
}

void RBT::InsertCase3(TreeNode*& current) {
    
    current->parent->color = Color::black;
    current->parent->parent->color = Color::red;
    
    if (current->siblingIsRight()) RightRotation(current->parent->parent);
    else LeftRotation(current->parent->parent);
}

void RBT::LeftRotation(TreeNode* current){

    TreeNode* right_child = current->rightchild;     // 把y指向x的rightchild, 最後y會變成x的parent
    
    if (right_child->leftchild != this->neel) // update parent of right_child->leftchild
        right_child->leftchild->parent = current;
    
    right_child->parent = current->parent; // update parent of right_child
    
    current->parent = right_child; // update parent of current
    
    current->rightchild = right_child->leftchild;  // update child of current

    right_child->leftchild = current;  // update child of right_child

    // what connected to current is now connect to right_child
    if (current == this->root) this->root = right_child;
    else if (right_child->parent->leftchild == current) right_child->parent->leftchild = right_child;
    else right_child->parent->rightchild = right_child;
}


void RBT::RightRotation(TreeNode* current){

    TreeNode* left_child = current->leftchild;     // 把y指向x的rightchild, 最後y會變成x的parent
    
    if (left_child->rightchild != this->neel) // update parent of right_child->leftchild
        left_child->rightchild->parent = current;
    
    left_child->parent = current->parent; // update parent of right_child
    
    current->parent = left_child; // update parent of current
    
    current->leftchild = left_child->rightchild;  // update child of current

    left_child->rightchild = current;  // update child of right_child
    
    // what connected to current is now connect to right_child
    if (current == this->root) this->root = left_child;
    else if (left_child->parent->rightchild == current) left_child->parent->rightchild = left_child;
    else left_child->parent->leftchild = left_child;
}

RBT::TreeNode* RBT::Sibling(TreeNode* current) {
    if (current == current->parent->rightchild) return current->parent->leftchild;
    else return current->parent->rightchild;
}

RBT::TreeNode* RBT::Leftmost(TreeNode *current){
    
    while (current->leftchild != this->neel){
        current = current->leftchild;
    }
    return current;
}

RBT::TreeNode* RBT::Successor(TreeNode *current){
    
    return Leftmost(current->rightchild);
}

RBT::TreeNode* RBT::Search(int key){

    TreeNode *current = root;               // 將curent指向root作為traversal起點
         
    while (current != nullptr && key != current->key) {  // 兩種情況跳出迴圈：
                                                      // 1.沒找到 2.有找到
        if (key < current->key){
            current = current->leftchild;   // 向左走
        }
        else {
            current = current->rightchild;  // 向右走
        }
    }
    return current;
}

void printBT(const std::string& prefix, const RBT::TreeNode* node, bool isLeft, std::ostream& os = std::cout) {
    
    if (node == nullptr) return;
    
    os << prefix;

    os << (isLeft ? "├──" : "└──" );

    // print the value of the node
    os << node->key;
    if (node->isRed()) os << " r";
    std::endl(os);

    // enter the next tree level - left and right branch
    printBT(prefix + (isLeft ? "│   " : "    "), node->leftchild, true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->rightchild, false);
}

int main(void) {
    
    RBT my_tree;
    
    int choice = 0, key = 0;
    
    do {
        
        std::cin >> choice;
        
        if (choice == 1) {
            std::cin >> key;
            my_tree.InsertRBT(key);
            std::endl(std::cout);
            choice = 3;
        }
        
        if (choice == 2) {
            std::cin >> key;
            my_tree.DeleteRBT(key);
            std::endl(std::cout);
            choice = 3;
        }
        
        if (choice == 3) {
            my_tree.print();
            std::endl(std::cout);
        }
        
    } while (choice != 4);
    
    return 0;
}
