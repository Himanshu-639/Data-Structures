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

Node* convertArr2LL(vector<int> & arr) {
    Node* ptr = new Node(arr[0]);
    ptr -> next = ptr;
    for (int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        temp -> next = ptr -> next;
        ptr -> next = temp;
        ptr = temp;
    }
    return ptr;
}

int lengthofLL(Node* ptr) {
    int cnt = 0;
    Node* temp = ptr -> next;
    do {
        cnt++;
        temp = temp -> next;
    } while(temp != ptr -> next);
    return cnt;
}

void print(Node* ptr) {
    Node* temp = ptr -> next;
    if (ptr == NULL) {
        cout << "The list is empty.";
    }
    else {
        do {
            cout << temp -> data << " ";
            temp = temp -> next;
        } while(temp != ptr -> next);
        cout<<endl;
    }
}

Node* insertAtBeg (Node* ptr, int val) {
    Node* newNode = new Node(val);
    if (ptr == NULL) {
        ptr = newNode;
        ptr -> next = newNode;
    }
    else {
        newNode -> next = ptr -> next;
        ptr -> next = newNode;
    }
    return ptr;
}

Node* insertAtEnd (Node* ptr, int val) {
    Node* newNode = new Node(val);
    if (ptr == NULL) {
        ptr = newNode;
        ptr -> next = newNode;
    }
    else {
        newNode -> next = ptr -> next;
        ptr -> next = newNode;
        ptr = newNode;
    }
    return ptr;
}

Node* insertAtK(Node* ptr, int el, int k) {
    int l = lengthofLL(ptr);
    if (k < 0 || k > (l + 1)) {
        cout << "Invalid Postion" << endl;
        return ptr;
    }
    else if (k == 1) {
        return insertAtBeg(ptr, el);
    }
    else {
        Node* newNode = new Node(el);
        Node* temp = ptr -> next;
        int i = 1;
        while (i < (k-1)) {
            temp = temp -> next;
            i++;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;  
        return ptr;
    }
}

Node* insertBeforeEl(Node* ptr, int el, int val) {
    if (ptr == NULL) {
        return NULL;
    }
    Node* temp = ptr -> next;
    if (temp -> data == el) {
        Node* newNode = new Node(val, temp);
        ptr -> next = newNode;
        return ptr;
    }
    else {
        while(temp -> next != ptr -> next) {
            if (temp -> next -> data == el) {
                Node* newNode = new Node(val, temp -> next);
                temp -> next = newNode;
                break;
            }
            temp = temp -> next;
        }
        return ptr;
    }
}

Node* insertAfterEl(Node* ptr, int el, int val) {
    if (ptr == NULL) {
        return NULL;
    }
    if (ptr -> data = el) {
        Node* newNode = new Node(val, ptr -> next);
        ptr -> next = newNode;
        ptr = newNode;
    }
    else {
        Node* temp = ptr -> next;
        while (temp -> next != ptr -> next) {
            if (temp -> data == el) {
                Node* newNode = new Node(val, temp -> next);
                temp -> next = newNode;
                break;
                }
                temp = temp -> next;
            }
            return ptr;
    }
}

Node* removeFromBeg(Node* ptr) {
    Node* temp = ptr -> next;
    if (temp == NULL) {
        return NULL;
    }
    else if (temp -> next == temp) {
        ptr = NULL;
        delete temp;
    }
    else {
        ptr -> next = ptr -> next -> next;
        delete temp;
    }
    return ptr;
}

Node* removeFromEnd(Node* ptr) {
    Node* current;
    Node* previous = ptr -> next;
    if (ptr -> next == NULL) {
        return NULL;
    }
    else if (ptr -> next == ptr) {
        ptr = NULL;
        delete previous;
    }
    else {
        while (previous -> next -> next != ptr -> next) {
            previous = previous -> next;
        }
        current = previous -> next;
        previous -> next = ptr -> next;
        delete current; 
    }
    return ptr;
}

Node* removeAtK(Node* ptr, int k) {
    if (ptr == NULL) {
        return NULL;
    }
    int i = 1;
    int l = lengthofLL(ptr);
    Node* current;
    Node* prevnode = ptr -> next;
    if (k < 1 || k > l) {
        return NULL;
    }
    else if (k == 1) {
        ptr = removeFromBeg(ptr);
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
    return ptr;
}

Node* removeEl(Node* ptr, int el) {
    if (ptr == NULL) {
        return NULL;
    }
    Node* temp = ptr -> next;
    if (ptr -> next -> data == el) {
        if (ptr -> next == ptr) {
            delete ptr;
            return NULL;
        }
        else {
            ptr -> next = temp -> next;
            delete temp;
            return ptr;
        }
    }
    Node* prevNode = temp;
    temp = temp -> next;
    while (temp != ptr -> next) {
        if (temp -> data == el) {
            prevNode -> next = temp -> next;
            if (temp == ptr) {
                ptr = prevNode;
            }
            delete temp;
            break;
        }
        prevNode = temp;
        temp = temp -> next;
        }
    return ptr;
}

Node* reverseCLL(Node* ptr) {
    if (ptr == NULL || ptr -> next == ptr) {
        return ptr;
    }
    Node* temp = ptr -> next;
    Node* current = ptr -> next;
    Node* nextNode = current -> next;
    Node* prevNode = ptr;
    do {
        current -> next = prevNode;
        prevNode = current;
        current = nextNode;
        nextNode = current -> next;
    } while (current != ptr -> next);

    ptr = temp;
    return ptr;
}

int main()
{
    vector<int> arr = {2, 4, 7 };
    Node* ptr = convertArr2LL(arr);
    Node* result = removeEl(ptr, 7);
    if (result == NULL) {
        cout << "The list is empty. "<<endl;
    } 
    else {
        print(result);
    }
    
    return 0;
}