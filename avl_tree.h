#include "node.h"

class AVLTree {
private:
    Node* root;
    int height(Node* node);
    int balance(Node* node);
    Node* rotate_left(Node* node);	
    Node* rotate_right(Node* node);	
    Node* insert_node(int value, Node* root);
    Node* remove_node(int value, Node* root);
    Node* make_balance(Node* node, int value);
public:
    AVLTree();
    void insert(int value);
    void remove(int value);
    bool search(int value);
    Node* getRoot();
    int max();
};
