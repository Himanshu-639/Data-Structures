#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

pair<Node*, Node*> convertArr2LL(vector<int> & arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    Node* tail = mover;
    tail -> next = head;
    return {head, tail};
}

int lengthofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    do {
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
        } while(temp != head);
        cout<<endl;
    }
}

Node* insertHead (Node* head, int val, Node*& tail) {
    Node* temp = new Node(val);
    if (head == NULL) {
        temp -> next = temp;
        head = tail = temp;
    }
    else {
        temp -> next = head;
        tail -> next = temp;
        head = temp;
    }
    return head;
}

Node* insertTail (Node* head, int val, Node*& tail) {
    Node* temp = new Node(val);
    if (head == NULL) {
        temp -> next = temp;
        head = tail = temp;
    }
    else {
        temp -> next = head;
        tail -> next = temp;
        tail = temp;
    }
    return head;
}

Node* insertAtK(Node* head, int el, int k, Node*& tail) {
    int l = lengthofLL(head);
    if (k < 0 || k > (l + 1)) {
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
        while (i < (k-1)) {
            temp = temp -> next;
            i++;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
        if (newNode -> next == head) {
            tail = newNode;
        }
        return head;
    }
}

Node* insertBeforeEl(Node *head, int el, int val, Node* &tail) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    if (temp -> data == el) {
        Node* newNode = new Node(val, temp);
        tail -> next = newNode;
        head = newNode;
        return head;
    }
    else {
        while(temp -> next != head) {
            if (temp -> next -> data == el) {
                Node* newNode = new Node(val, temp -> next);
                temp -> next = newNode;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
}

Node* insertAfterEl(Node* head, int el, int val, Node* &tail) {
    if (head == NULL) {
        return NULL;
    }
    if (head -> data == el) {
        Node* newNode = new Node(val, head -> next);
        head -> next = newNode;
        if (tail == head) {
            tail = newNode;
        }
        return head;
    }
    else{
        Node* temp = head -> next;
        while (temp != head) {
            if (temp -> data == el) {
                Node* newNode = new Node(val, temp -> next);
                temp -> next = newNode;
                if (temp == tail) {
                    tail = newNode;
                }
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
}

Node* removesHead(Node* head, Node* &tail) {
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
        tail -> next = head;
        delete temp;
    }
    return head;
}

Node* removesTail(Node* head, Node* &tail) {
    Node* current;
    Node* previous = head;
    if (head == NULL) {
        return NULL;
    }
    else if (tail -> next == tail) {
        head = NULL;
        tail = NULL;
        delete previous;
    }
    else {
        while (previous -> next -> next != head) {
            previous = previous -> next;
        }
        current = previous -> next;
        previous -> next = head;
        tail = previous;
        delete current; 
    }
    return head;
}

Node* removeAtK(Node* head, int k, Node* &tail) {
    if (head == NULL) {
        return NULL;
    }
    int i = 1;
    int l = lengthofLL(head);
    Node* current;
    Node* prevnode = head;
    if (k < 1 || k > l) {
        return NULL;
    }
    else if (k == 1) {
        head = removesHead(head, tail);
    }
    else {
        while (i < (k - 1)) {
            prevnode  = prevnode -> next;
            i++;
        }
        current = prevnode -> next;
        prevnode -> next = current -> next;
        delete current;
    }
    return head;
}

Node* removeEl(Node* head, int el, Node* &tail) {
    int l = lengthofLL(head);
    if (head == NULL) {
        return NULL;
    }
    int i = 0;
    Node* temp = head;
    Node* prevNode;
    Node* nextNode;
    if (head -> data == el) {
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head -> next;
            tail -> next = head;
            delete temp;
        }
    }
    else {
        while (i < l) {
            prevNode = temp;
            temp = temp -> next;
            i++;
            if (temp -> data == el) {
                prevNode -> next = temp -> next;
                if (temp == tail) {
                    tail = prevNode;
                }
                delete temp;
                break;
            }
        }
    }
    return head;
}

Node* reverseCLL(Node* head, Node* &tail) {
    if (head == 0 || head -> next == head) {
        return head;
    }
    Node* current = head;
    Node* nextNode = current -> next;
    Node* prevNode = tail;
    do {
        current -> next = prevNode;
        prevNode = current;
        current = nextNode;
        nextNode = current -> next;
    } while (current != head);

    tail = head;
    head = prevNode;
    return head;
}

int main()
{
    vector<int> arr = {2, 4, 7 };
    pair<Node*, Node*> result = convertArr2LL(arr);
    Node* head = result.first;
    Node* tail = result.second;
    head = removeEl(head, 7, tail);
    print(head -> next);

}