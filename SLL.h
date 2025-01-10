#ifndef SLL_H
#define SLL_H

#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data1, Node *next1);
    Node(int data1);
};


Node* convertArr2LL(vector<int> &arr);
int lengthofLL(Node* head);
Node* checkIfPresent(Node* head, int val);
void print(Node* head);
Node* removesHead(Node* head);
Node* removesTail(Node* head);
Node* removeK(Node* head, int k);
Node* removeEl(Node* head, int el);
Node* insertHead(Node* head, int val);
Node* insertTail(Node* head, int val);
Node* insertAtK(Node* head, int el, int k);
Node* insertBeforeValue(Node* head, int el, int val);
Node* reverseLL(Node* head);

#endif
