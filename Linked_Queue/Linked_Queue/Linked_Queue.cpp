#include <iostream>
using namespace std;
template<class t>
class linked_queue
{
private:
    struct node
    {
        t item;
        node* next; 
    };

    node* frontptr; 
    node* rearptr;  
    int length;

public:
    linked_queue()
    {
        frontptr = rearptr = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return (length == 0);
    }

    void enqueue(t element)
    {
        if (isEmpty())
        {
            frontptr = new node;
            frontptr->item = element;
            frontptr->next = NULL;
            rearptr = frontptr; 
            length++;
        }
        else
        {
            node* newitem = new node;
            newitem->item = element;
            newitem->next = NULL;
            rearptr->next = newitem;
            rearptr = newitem;
            length++;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "it is empty" << endl;
        }
        else
        {
            node* tempptr = frontptr; 
            if (frontptr == rearptr)
            {
                frontptr = NULL;
                rearptr = NULL;
                length = 0;
            }
            else
            {
                frontptr = frontptr->next;
                tempptr->next = NULL;
                delete tempptr;
                length--;
            }
        }
    }

    t getfront()
    {
        if (isEmpty())
        {
            cout << "wrong" << endl;
            return -1; 
        }
        return frontptr->item;
    }

    t getrear() 
    {
        if (isEmpty()) 
        {
            cout << "wrong" << endl;
            return -1; 
        }
        return rearptr->item;
    }

    void display()
    {
        node* curptr = frontptr;
        cout << "items in queue : [";
        while (curptr != NULL)
        {
            cout << curptr->item << " ";
            curptr = curptr->next;
        }
        cout << "]" << endl;
    }

    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    linked_queue<int> q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);

    q.display(); 

    cout << "Front: " << q.getfront() << endl;
    cout << "Rear: " << q.getrear() << endl;

    q.clear();
    q.display(); 

    return 0;
}