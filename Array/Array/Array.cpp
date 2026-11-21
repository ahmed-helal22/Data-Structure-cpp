#include <iostream>
using namespace std;

class array_list
{
private:
    int* arr;
    int maxSize;
    int length;

public:
    array_list(int size = 100)
    {
        maxSize = size;
        arr = new int[maxSize];
        length = 0;
    }

    ~array_list()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return (length == 0);
    }

    bool isFull()
    {
        return (length == maxSize);
    }

    int getLength()
    {
        return length;
    }

    void display()
    {
        cout << "Items in the list: [ ";
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }

    void insert(int index, int element)
    {
        if (isFull())
        {
            cout << "List is full!" << endl;
            return;
        }
        if (index < 0 || index > length)
        {
            cout << "Out of range!" << endl;
            return;
        }

        for (int i = length; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[index] = element;
        length++;
    }

    void append(int element)
    {
        insert(length, element);
    }

    void remove(int index)
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (index < 0 || index >= length)
        {
            cout << "Out of range!" << endl;
            return;
        }

        for (int i = index; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        length--;
    }

    int search(int element)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    void update(int index, int element)
    {
        if (index < 0 || index >= length)
        {
            cout << "Out of range!" << endl;
            return;
        }
        arr[index] = element;
    }

    int getElement(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Out of range!" << endl;
            return -1;
        }
        return arr[index];
    }

    void clear()
    {
        length = 0;
    }
};

int main()
{
    array_list myList(10);

    myList.append(10);
    myList.append(20);
    myList.append(30);

    cout << "After appending elements:" << endl;
    myList.display();

    myList.insert(1, 15);
    cout << "After inserting 15 at index 1:" << endl;
    myList.display();

    int pos = myList.search(20);
    if (pos != -1)
        cout << "Element 20 found at index: " << pos << endl;
    else
        cout << "Element not found!" << endl;

    myList.remove(2);
    cout << "After removing element at index 2:" << endl;
    myList.display();

    return 0;
}