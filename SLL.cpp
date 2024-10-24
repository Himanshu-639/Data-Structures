#include "SLL.h"
#include <iostream>
#include <vector>
using namespace std;

Node::Node(int data1, Node *next1) {
        data = data1;
        next = next1;
}

Node::Node(int data1) {
        data = data1;
        next = nullptr;
}


Node* convertArr2LL(vector<int> &arr) {
    Node *head= new Node(arr[0]);
    Node *mover = head;
    for(int i = 1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

int lengthofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp) {
        temp = temp -> next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node* head, int val) {
    Node* temp = head;
    while(temp) {
        if(temp -> data == val) return 1;
        temp = temp -> next;
    }
    return 0;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

Node* removesHead(Node* head) {
    if (head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

Node* removesTail(Node* head) {
    if (head == NULL || head -> next == NULL) return head;
    Node* temp = head;
    while(temp -> next -> next != NULL) {
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = nullptr;
    return head;

}

Node* removeK(Node* head, int k) {
    if(head == NULL) return head;
    if(k == 1) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) {
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* removeEl(Node* head, int el) {
    if(head == NULL) return head;
    if(head -> data == el) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if(temp -> data == el) {
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node* head, int val) {
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    Node* newNode = new Node(val);
    temp -> next = newNode;
    return head;
}

Node* insertAtK(Node* head, int el, int k) {
    if(head == NULL) {
        if(k == 1) {
            return new Node(el);
        }
    else {
        return head;
        }
    }
    if (k ==1) {
        return new Node(el, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        if (cnt == (k-1)) {
            Node* x = new Node(el, temp -> next);
            temp -> next = x;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int el, int val) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    if (temp -> data == val) {
        Node* newNode = new Node(el, temp);
        head = newNode;
        return head;
    }
    else {
        while(temp -> next != NULL) {
            if (temp -> next -> data == val) {
                Node* x = new Node(el, temp -> next);
                temp -> next = x;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
}

Node* reverseLL(Node* head) {
    Node* prevNode = 0;
    Node* currentNode;
    Node* nextNode;
    currentNode = nextNode = head;
    while (nextNode != NULL) {
        nextNode = nextNode -> next;
        currentNode -> next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    return head;
}

/*int main()
{
    vector<int> arr = {2, 5, 8, 7}; 
    Node *head = convertArr2LL(arr);
    head = insertBeforeValue(head, 9, 2);
    print(head);
}*/