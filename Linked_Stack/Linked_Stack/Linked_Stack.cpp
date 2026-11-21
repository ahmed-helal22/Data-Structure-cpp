//#include <iostream>
//using namespace std;
//template <class t>
//class Stack
//{
//    struct node
//    {
//        t item;
//        node* next;
//    };
//    node *top,*cur;
//public:
//    Stack()
//    {
//        top = NULL;
//    }
//    void push(t newitem)
//    {
//        node* newitemptr = new node;
//        if (newitemptr == NULL) { cout << "problem"; }
//        else {
//            newitemptr->item = newitem;
//            newitemptr->next = top;
//            top = newitemptr;
//        }
//    }
//    bool isEmpty()
//    {
//        if (top == NULL)
//            return true;
//        else return false;
//    }
//    void pop()
//    {
//        if (isEmpty()) { cout << "problem2"; }
//        else
//        {
//            node* temp = top;
//            top = top->next;
//            temp = NULL;
//            delete temp;
//        }
//    }
//    void pop(t& stacktop)
//    {
//        if (isEmpty()) { cout << "problem2"; }
//        else
//        {
//            stacktop = top->item;
//            node* temp = top;
//            top = top->next;
//            delete temp;
//        }
//    }
//    void getTop(t& stacktop)
//    {
//        if (isEmpty()) { cout << "problem2" ; }
//        else
//        {
//            stacktop = top->item;
//            cout << stacktop;
//        }
//    }
//    void display()
//    {
//        cout << "stack items is [ ";
//        cur = top;
//        while(cur!=NUll)
//        {
//            cout <<cur->item<<" ";
//            cur=cur->next;
//        }
//        cout << "]";
//    }
//};
//int main()
//{
//    Stack<int>s;
//    s.push(200);
//    s.push(300);
//    s.push(500);
//    s.push(700);
//    s.pop();
//    s.display();
//}
#include <iostream>
using namespace std;

template <class t>
class Stack
{
    struct node
    {
        t item;
        node* next;
    };
    node* top, * cur;

public:
    Stack()
    {
        top = NULL;
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }

    void push(t newitem)
    {
        node* newitemptr = new node;
        if (newitemptr == NULL) { cout << "problem"; }
        else {
            newitemptr->item = newitem;
            newitemptr->next = top;
            top = newitemptr;
        }
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void pop()
    {
        if (isEmpty()) { cout << "problem2"; }
        else
        {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void pop(t& stacktop)
    {
        if (isEmpty()) { cout << "problem2"; }
        else
        {
            stacktop = top->item;
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void getTop(t& stacktop)
    {
        if (isEmpty()) { cout << "problem2"; }
        else
        {
            stacktop = top->item;
            cout << stacktop;
        }
    }

    void display()
    {
        cout << "stack items is [ ";
        cur = top;
        while (cur != NULL)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]";
    }
};

int main()
{
    Stack<int> s;
    s.push(200);
    s.push(300);
    s.push(500);
    s.push(700);
    s.pop();
    s.display();
}