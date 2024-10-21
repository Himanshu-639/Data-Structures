#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node* deleteHead(Node* head) {
    if (head == NULL || head -> next == NULL) {
        return NULL;
    }
    Node* prev = head;
    head = head -> next;
    head -> prev = nullptr;
    prev -> next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == NULL || head -> next == NULL) {
        return NULL;
    }
    Node* tail = head;
    while(tail -> next != NULL) {
        tail = tail -> next;
    }
    Node* newTail = tail -> prev;
    newTail -> next = nullptr;
    tail -> prev = nullptr;
    delete tail;
    return head;
}

Node* deleteKthElement(Node* head, int k) {
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) break;
        temp = temp -> next;
    }
    Node* bck = temp -> prev;
    Node* fnt = temp -> next;
    if (bck == NULL && fnt == NULL) {
        delete temp;
        return NULL;
    }
    else if (bck == NULL) {
        return deleteHead(head);
    }
    else if (fnt == NULL) {
        return deleteTail(head);
    }
    else {
        temp -> next = nullptr;
        temp -> prev = nullptr;
        bck -> next = fnt;
        fnt -> prev = bck;
        return head;
    }
}

void deleteK(Node* temp) {
    Node* bck = temp -> prev;
    Node* frnt = temp -> next;
    if (frnt == NULL) {
        bck -> next = nullptr;
        temp -> prev = nullptr;
        delete temp;
        return;
    }
    bck -> next = frnt;
    frnt -> prev = bck;
    temp -> next = nullptr;
    temp -> prev = nullptr;
    delete temp;
}

Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    head -> prev = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
    if (head -> next == NULL) {
        return insertBeforeHead(head, val);
    }
    Node* tail = head;
    while (tail -> next != NULL) {
        tail = tail -> next;
    }
    Node* bck = tail -> prev;
    Node* newNode = new Node(val, tail, bck);
    bck -> next = newNode;
    tail -> prev = newNode;
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val) {
    if (k == 1) {
        return insertBeforeHead(head, val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) {
            break;
        }
        temp = temp -> next;
    }
    Node* bck = temp -> prev;
    Node* newNode = new Node(val, temp, bck);
    bck -> next = newNode;
    temp -> prev = newNode;
    return head;
}

Node* insertBeforeNode(Node* node, int val) {
    Node* bck = node -> prev;
    Node* newNode = new Node(val, node, bck);
    bck -> next = newNode;
    node -> prev = newNode;
}

Node* reverseDLL(Node* head) {
    Node* tail;
    Node* nextNode;
    Node* prevNode;
    Node* currentNode;
    tail = head;
    while (tail -> next != NULL) {
        tail = tail -> next;
    }
    if (head == NULL) {
        return NULL;
    }
    else {
        currentNode = head;
        while (currentNode != NULL) {
            nextNode = currentNode -> next;
            currentNode -> next = currentNode -> prev;
            currentNode -> prev = nextNode;
            currentNode= nextNode;
        }
    }
    currentNode = head;
    head = tail;
    tail = currentNode;
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    head = reverseDLL(head);
    print(head);
    return 0;
}