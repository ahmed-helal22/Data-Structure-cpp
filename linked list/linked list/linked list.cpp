#include <iostream>
using namespace std;

// تعريف كلاس العقدة (Node)
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// تعريف كلاس القائمة الموصولة (LinkedList)
class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    // فحص ما إذا كانت القائمة فارغة
    bool isEmpty() {
        return length == 0;
    }

    // إضافة عنصر في بداية القائمة
    void insertFirst(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    // إضافة عنصر في نهاية القائمة
    void insertLast(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // إضافة عنصر في موضع معين (Index يبدأ من 0)
    void insertAtPosition(int pos, int val) {
        if (pos < 0 || pos > length) {
            cout << "Out of range\n";
            return;
        }

        if (pos == 0) {
            insertFirst(val);
        }
        else if (pos == length) {
            insertLast(val);
        }
        else {
            Node* newNode = new Node(val);
            Node* cur = head;
            for (int i = 0; i < pos - 1; i++) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            length++;
        }
    }

    // طباعة جميع عناصر القائمة
    void print() {
        Node* cur = head;
        cout << "[ ";
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }
};

int main() {
    LinkedList list;

    list.insertFirst(10);      // [ 10 ]
    list.insertFirst(20);      // [ 20 10 ]
    list.insertLast(30);       // [ 20 10 30 ]
    list.insertAtPosition(1, 15); // [ 20 15 10 30 ]

    cout << "LinkedList contents: ";
    list.print();

    return 0;
}