#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }

    Node(int val, Node* left1, Node* right1) {
        data = val;
        left = left1;
        right = right1;
    }

    void preorder(Node* root) {
        if (root == NULL) {
            return;
        }
        cout  << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
};

int main() {
    
    int ele = 3;
    Node* root = new Node(ele);
    root -> left = new Node(4);
    root -> right = new Node(5);
    root -> right -> left = new Node(7);
    root -> preorder(root);

    return 0;
}