#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

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

pair<Node*, Node*> convertArr2LL(vector<int> & arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        temp -> prev = mover;
        mover = temp;
    }
    Node* tail = mover;
    tail -> next = head;
    head -> prev = tail;
    return {head, tail};
}

int lengthofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    do{
        cnt++;
        temp = temp -> next;
    } while(temp != head);
    return cnt;
}

void print(Node* head) {
    Node* temp = head;
    if (head == NULL) {
        cout << "The list is empty.";
    }
    else {
        do {
            cout << temp -> data << " ";
            temp = temp -> next;
        } while (temp != head);
        cout << endl;
    }
}

Node* insertHead(Node* head, int val, Node* &tail) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = tail = temp;
        temp -> next = head;
        temp -> prev = tail;
    }
    else {
        temp -> next = head;
        head -> prev = temp;
        temp -> prev = tail;
        tail -> next = temp;
        head = temp;
    }
    return head;
}

Node* insertTail(Node* head, int val, Node* &tail) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = tail = temp;
        temp -> next = head;
        temp -> prev = tail;
    }
    else {
        temp -> prev = tail;
        tail -> next = temp;
        temp -> next = head;
        head -> prev = temp;
        tail = temp;
    }
    return head;
}

Node* insertAtK(Node* head, int el, int k, Node* &tail) {
    int l = lengthofLL(head);
    if (k < 1 || k > (l + 1)) {
        cout << "Invalid Postion" << endl;
        return head;
    }
    else if (k == 1) {
        return insertHead(head, el, tail);
    }
    else {
        Node* newNode = new Node(el);
        Node* temp = head;
        int i = 1;
        while (i < (k - 1)) {
            temp = temp -> next;
            i++;
        }
        temp -> next -> prev = newNode;
        newNode -> next = temp -> next;
        newNode -> prev = temp;
        temp -> next = newNode;
        if (newNode -> next == head) {
            tail = newNode;
        }
        return head;
    }
}

Node* removeHead(Node* head, Node* &tail) {
    Node* temp = head;
    if (head == NULL) {
        return NULL;
    }
    else if (head -> next == head) {
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else {
        head = head -> next;
        head -> prev = tail;
        tail -> next = head;
        delete temp;
    }
    return head;
}

Node* removeTail(Node* head, Node* &tail) {
    Node* temp = tail;
    if (head == NULL) {
        return NULL;
    }
    if (head -> next == head) {
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else {
    tail = tail -> prev;
    tail -> next = head;
    head -> prev = tail;
    delete temp;
    }
    return head;
}

Node* removeAtK(Node* head, int k, Node* &tail) {
    if (head == NULL) {
        return NULL;
    }
    int i = 1;
    int l = lengthofLL(head);
    Node* temp = head;
    if (k < 1 || k > l) {
        cout << "Invalid Position" << endl;
    }
    else if (k == 1) {
        head = removeHead(head, tail);
    }
    else {
        while (i < k) {
            temp = temp -> next;
            i++;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        if (temp == tail) {
            tail = temp -> prev;
        }
        delete temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 6, 8};
    pair<Node*, Node*> result = convertArr2LL(arr);
    Node* head = result.first;
    Node* tail = result.second;
    head = removeAtK(head, 3, tail);
    print(head);
}