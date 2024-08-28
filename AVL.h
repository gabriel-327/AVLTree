#ifndef PROJECT1_AVL_H
#define PROJECT1_AVL_H
#include <iostream>
#include <cctype>
using namespace std;

// Code from Jackie and Neil project breakdown video
struct Node{
    // Node attributes
    string name;
    string ufid;
    int height;
    Node* left;
    Node* right;

    // parametrized constructor
    Node(string name, string ufid){
        this->name = name;
        this->ufid = ufid;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
    // Destructor
    ~Node(){
        if(left != nullptr){
            delete left;
        }
        if(right != nullptr){
            delete right;
        }
    }
};

class AVLTree{
private:
    Node* root;
    // Class variables used
    bool insertWorked;
    bool deleteWorked;
    int namesFound;
    string parsing;
    Node* inordervalue;
    // Helper functions
    Node* insertHelper(Node* root, string name, string ufid);
    Node* removeHelper(Node* root, string ufid);
    void helperInorder(Node* helproot);
    void helperPreorder(Node* helproot);
    void helperPostorder(Node* helproot);
    Node* searchIDHelper(Node* node, int ufid);
    void searchNameHelper(Node* node, string name);
    int getInorderhelper(Node* node, int in_order_count);
    Node* getInorder(int in_order_count);

    // Rotation functions
    Node* rotateleft(Node* node);
    Node* rotateright(Node* node);
    Node* rotateleftright(Node* node);
    Node* rotaterightleft(Node* node);

    // Height functions
    void updateHeight(Node* node);
    int getBalancefactor(Node* node);

public:
    // Public functions to use in main
    bool insert(string name, string ufid);
    bool remove(string ufid);
    string searchID(string ufid);
    void searchName(string name);
    int getLevelCount();
    bool removeInorder(int number);
    bool getinsertworked();
    void inorder();
    void preorder();
    void postorder();

    // constructor
    AVLTree(){
     this->root = nullptr;
     insertWorked = true;
    }
    //Destructor
    ~AVLTree(){
        delete root;
    }
};

// Functions to help in main
bool check_name(string &name);
bool check_number(string &number);






#endif //PROJECT1_AVL_H
