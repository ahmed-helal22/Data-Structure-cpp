#include <iostream>
using namespace std;
const int max_size = 100;
template <class t>
class stack
{
private:
    int top;
    t item[max_size];
public:
    stack():top(-1){}
    void push(t element)
    {
        if(top>=max_size-1)
        {
            cout << "its full\n";
        }
        else
        {
            top++;
            item[top] = element;
        }
    }
    bool is_Empty()
    {
        if (top == -1) { return true; }
        else return false;
    }
    void pop()
    { if(is_Empty())
    {
        cout << "stack empty";
    }
    else
        top--;
    }
    void pop(t&element)
    {
        if (is_Empty())
        {
            cout << "stack empty";
        }
        else
        {
            element = item[top];
            top--;
        }
    }
    void getTop(t& element)
    {
        if (is_Empty())
        {
            cout << "stack empty";
        }
        else {
            element = item[top];
            cout << element << endl;
        }
    }
    void print()
    {
        cout << "[";
        for (int i=top;i>=0;i--)
        {
            cout << item[i]<<" ";
        }
        cout << "]";
    }
};
int main()
{
    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.pop();
    int y = 0;
    s.getTop(y);
    s.print();
}


