#include <iostream>
#include <string>
#include <cassert>

using namespace std;

template <class Type>
class arrayQueueType {
private:
    int maxSize; // أقصى حجم للمصفوفة
    int count;   // عدد العناصر الحالية
    int front;   // مؤشر أول عنصر
    int rear;    // مؤشر آخر عنصر
    Type* list;  // المصفوفة الديناميكية

public:
    // 1. Constructor
    arrayQueueType(int size = 100) {
        if (size <= 0) {
            maxSize = 100;
        }
        else {
            maxSize = size;
        }
        front = 0;
        rear = maxSize - 1;
        count = 0;
        list = new Type[maxSize];
    }

    // 2. Destructor
    ~arrayQueueType() {
        delete[] list;
    }

    // 3. هل الـ Queue فارغ؟
    bool isEmptyQueue() const {
        return (count == 0);
    }

    // 4. هل الـ Queue ممتلئ؟
    bool isFullQueue() const {
        return (count == maxSize);
    }

    // 5. إضافة عنصر (Enqueue)
    void addQueue(Type newElement) {
        if (!isFullQueue()) {
            rear = (rear + 1) % maxSize; // تحريك دائرية
            list[rear] = newElement;
            count++;
        }
        else {
            cout << "Queue is Full, cannot add: " << newElement << endl;
        }
    }

    // 6. حذف عنصر (Dequeue)
    void deleteQueue() {
        if (!isEmptyQueue()) {
            front = (front + 1) % maxSize;
            count--;
        }
        else {
            cout << "Queue is Empty, cannot delete." << endl;
        }
    }

    // 7. أول عنصر
    Type frontQueue() const {
        assert(!isEmptyQueue());
        return list[front];
    }

    // 8. آخر عنصر
    Type rearQueue() const {
        assert(!isEmptyQueue());
        return list[rear];
    }

    // 9. دالة البحث عن عنصر (queueSearch)
    int queueSearch(Type element) {
        int pos = -1;
        if (!isEmptyQueue()) {
            // المرور على العناصر من front إلى ما قبل rear دائرية
            for (int i = front; i != rear; i = (i + 1) % maxSize) {
                if (list[i] == element) {
                    pos = i; // إرجاع الفهرس في المصفوفة
                    break;
                }
            }
            // فحص العنصر الأخير عند rear إذا لم يُعثر عليه في الحلقة
            if (pos == -1) {
                if (list[rear] == element) {
                    pos = rear;
                }
            }
        }
        else {
            cout << "Queue is Empty!" << endl;
        }
        return pos;
    }

    // 10. طباعة عناصر الـ Queue
    void printQueue() {
        if (!isEmptyQueue()) {
            for (int i = front; i != rear; i = (i + 1) % maxSize) {
                cout << list[i] << " ";
            }
            cout << list[rear] << endl;
        }
        else {
            cout << "Queue is Empty" << endl;
        }
    }
};

int main() {
    arrayQueueType<string> q1(5);

    q1.addQueue("assss");
    q1.addQueue("bbbb");
    q1.addQueue("nnn");
    q1.addQueue("bbbb");
    q1.addQueue("gggg");

    q1.printQueue();

    // تجربة البحث عن عنصر
    int index = q1.queueSearch("nnn");
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    }
    else {
        cout << "Element not found!" << endl;
    }

    return 0;
}