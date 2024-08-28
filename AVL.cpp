//
// Created by gabri on 6/5/2024.
//
#include "AVL.h"
using namespace std;

// how to do this: traverse tree with root node, less than left, greater than right subtree
// needs to be unique cant == root or sub node
// get balance factor of the ancestor node ->> perform rotation, then print successful

bool AVLTree::insert(string name, string ufid) {
    if (!check_name(name) || !check_number(ufid)) {
        return false;
    }
    insertWorked = true;
    this->root = insertHelper(this->root, name, ufid);
    return insertWorked;
}


Node *AVLTree::insertHelper(Node* root, string name, string ufid) {
    // nothing in tree
    if (root == nullptr) {
        return new Node(name, ufid);

    } else if (stoi(ufid) < stoi(root->ufid)) {
        root->left = insertHelper(root->left, name, ufid);
        updateHeight(root);
    } else if (stoi(ufid) > stoi(root->ufid)){
        root->right = insertHelper(root->right, name, ufid);
        updateHeight(root);
    } else {
        insertWorked = false;
        return root;
    }
    // Balance Factor of x = Height (left subtree of x) - Height (right subtree of x)
    // Need to update height:
    if(getBalancefactor(root) < -1){
        if(getBalancefactor(root->right) > 0){
            root = rotaterightleft(root);
            updateHeight(root);// need to update height
        }
        else{
            root = rotateleft(root);
            updateHeight(root);
        }
    }
    else if(getBalancefactor(root) > 1){
        if(getBalancefactor(root->left) < 0){
            root = rotateleftright(root);
            updateHeight(root);
        }
        else{
            root = rotateright(root);
            updateHeight(root);
        }
    }
    return root;
}


bool AVLTree::remove(string ufid) {
    if (!check_number(ufid)) {
        return false;
    }
    deleteWorked = true;
    // dont set it bc we are removing something
    this->root = removeHelper(this->root, ufid);
    return deleteWorked;
}

// Documentation: trees slide number 38
Node *AVLTree::removeHelper(Node *root, string ufid) {
    // the item is not in the tree
    if (root == nullptr) {
        deleteWorked = false;
        return root;
    }
    if(stoi(ufid) < stoi(root->ufid)){
        root->left = removeHelper(root->left, ufid);
        return root;
    }
    else if(stoi(ufid) > stoi(root->ufid)){
        // delete from right subtree
        root->right = removeHelper(root->right, ufid);
        return root;
    }
    // item is in the local root
    else {
        // no children
        if(root->left == nullptr && root->right == nullptr){
            // set the parent local root to null
            delete root;
            return nullptr;
        }
        // one child
        // only left child
        else if(root->left != nullptr && root->right == nullptr){
            Node* tmp = root->left;
            root->left = nullptr;
            delete root;
            return tmp;
        }
        // only left child
        else if(root->left == nullptr && root->right != nullptr){
            Node* tmp = root->right;
            root->right = nullptr;
            delete root;
            return tmp;
        }
        // two children
        else{
            if(root->left->right == nullptr){
                Node* tmp = root->left;
                tmp->right = root->right;
                root->left = nullptr;
                root->right = nullptr;
                delete root;
                return tmp;
            }
            else{
                Node* tmp = root->left;
                // rightmost node in left subtree
                while(tmp->right->right != nullptr){
                    tmp = tmp->right;
                }
                root->ufid = tmp->right->ufid;
                root->name = tmp->right->name;

                Node* tmp2 = tmp->right->left;
                tmp->right->left = nullptr;
                delete tmp->right;
                tmp->right = tmp2;
                return root;

            }

        }
    }
}

void AVLTree::helperInorder(Node *helproot) {
    if(helproot == nullptr)
        return;
    else
    {
        helperInorder(helproot->left);
        parsing += helproot->name + ", ";
        helperInorder(helproot->right);
    }
}

// in order traversal
void AVLTree::inorder() {
    parsing = "";
    helperInorder(this->root);
    cout << parsing.substr(0, parsing.size() -2) << endl;
}



void AVLTree::helperPreorder(Node *helproot) {
    if(helproot == nullptr)
        return;
    else
    {
        parsing += helproot->name + ", ";
        helperPreorder(helproot->left);
        helperPreorder(helproot->right);
    }
}

void AVLTree::helperPostorder(Node *helproot) {
    if(helproot == nullptr)
        return;
    else
    {
        helperPostorder(helproot->left);
        helperPostorder(helproot->right);
        parsing += helproot->name + ", ";
    }
}

void AVLTree::preorder() {
    parsing = "";
    helperPreorder(this->root);
    cout << parsing.substr(0, parsing.size() -2) << endl;
}

void AVLTree::postorder() {
    parsing = "";
    helperPostorder(this->root);
    cout << parsing.substr(0, parsing.size() -2) << endl;
}





// right right case
// code from Balanced trees slide 12
// question for line 11
Node* AVLTree::rotateleft(Node* node) {
    Node* grandchild = node->right->left;
    Node* newParent = node->right;
    newParent ->left = node;
    node ->right = grandchild;
    updateHeight(node);
    return newParent;
}

// left left case
Node *AVLTree::rotateright(Node* node) {
    Node* grandchild = node->left->right;
    Node* newParent = node->left;
    newParent ->right = node;
    node ->left = grandchild;
    updateHeight(node);
    return newParent;
}

// right left case
Node *AVLTree::rotateleftright(Node *node) {
    node->left = rotateleft(node->left);
    updateHeight(node->left);
    return rotateright(node);
}

Node *AVLTree::rotaterightleft(Node *node) {
    node ->right = rotateright(node->right);
    updateHeight(node->right);
    return rotateleft(node);
}

void AVLTree::updateHeight(Node *node) {
    int left_height;
    int right_height;

    if(node->left == nullptr){
        left_height = 0;
    }
    else{
        left_height = node->left->height;
    }
    if(node->right == nullptr){
        right_height = 0;
    }
    else{
        right_height = node->right->height;
    }
    node->height = 1 + max(left_height, right_height);
}

int AVLTree::getBalancefactor(Node *node) {
    int left_height;
    int right_height;

    if(node->left == nullptr){
        left_height = 0;
    }
    else{
        left_height = node->left->height;
    }
    if(node->right == nullptr){
        right_height = 0;
    }
    else{
        right_height = node->right->height;
    }
    return left_height - right_height;
}



Node *AVLTree::searchIDHelper(Node *node, int ufid) {
    // no node there
    if(node == nullptr){
        return nullptr;
    }
    // if node matches ufid
    if(ufid == stoi(node->ufid)){
        return node;
    }
    // ufid less than node
    if(ufid < stoi(node->ufid)){
        return searchIDHelper(node->left, ufid);
    }
    // ufid greater than node
    return searchIDHelper(node->right, ufid);
}


string AVLTree::searchID(string ufid) {
    Node * node = searchIDHelper(this->root, stoi(ufid));
    if (node == nullptr)
        return "unsuccessful";
    return node->name;
}

void AVLTree::searchNameHelper(Node *node, string name) {
    // no node there
    if(node == nullptr){
        return;
    }
    // if node matches name
    if(name == node->name){
        cout << node->ufid << endl;
        namesFound++;
    }
    searchNameHelper(node->left, name);
    searchNameHelper(node->right, name);
}

void AVLTree::searchName(string name) {
    namesFound = 0;
    searchNameHelper(this->root, name);
    if (namesFound == 0)
        cout << "unsuccessful" << endl;
}

int AVLTree::getLevelCount() {
    if(root == nullptr){
        return 0;
    }
    return root->height;
}

int AVLTree::getInorderhelper(Node *node, int in_order_count) {
    if (node == nullptr)
        return  in_order_count;
    in_order_count = getInorderhelper(node->left, in_order_count);
    in_order_count--;
    if (in_order_count == 0) {
        inordervalue = node;
        return in_order_count;
    }
    in_order_count = getInorderhelper(node->right, in_order_count);
    return in_order_count;
}

Node *AVLTree::getInorder(int in_order_count) {
   inordervalue = nullptr;
   getInorderhelper(root, in_order_count);
   return inordervalue;
}

bool AVLTree::removeInorder(int number) {
    Node* node = getInorder(number + 1);
    if(node == nullptr){
        return false;
    }
    remove(node->ufid);
    return true;
}

bool AVLTree::getinsertworked() {
    return insertWorked;
}

bool check_name(string &name) {
    for(char letter : name){
        // write c++ documentation for isalpha, isspace amd isdigit
        if(isalpha(letter)){
            continue;
        }
        else if(isspace(letter)){
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

bool check_number(string &number) {
    if(number.size() != 8){
        return false;
    }
    for(char each_number : number){
        if(isdigit(each_number)){
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}