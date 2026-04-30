#include <iostream>
using namespace std;

class MyCircularQueue
{
private:
    int maxsize; // 큐 배열의 최대 크기
    int front;   // 첫 번째 요소 바로 앞 인덱스
    int rear;    // 마지막 요소의 인덱스
    int *list;   // 데이터를 저장할 배열 포인터
    int count;   // 현재 큐 안에 들어있는 데이터 개수

public:
    MyCircularQueue(int n = 10)
    {
        maxsize = n;
        list = new int[maxsize];
        front = 0;
        rear = 0;
        count = 0;
    }
    ~MyCircularQueue()
    {
        delete[] list;
    }
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const int &n);
    void dequeue();
    int Front();
    int Rear();
    int size() const;
    void print();
    void printDetail();
};

void MyCircularQueue::initialize()
{
    front = 0;
    rear = 0;
    count = 0;
}

bool MyCircularQueue::isEmpty() const
{
    return size() == 0;
}

bool MyCircularQueue::isFull() const
{
    return size() == maxsize - 1;
}

void MyCircularQueue::enqueue(const int &n)
{
    if (isFull())
    {
        cout << "=> Queue is full !" << endl;
        return;
    }
    rear++;
    if (rear > maxsize - 1)
        rear = 0;
    list[rear] = n;
    count++;
}

void MyCircularQueue::dequeue()
{
    // 0 1 2 3 4 5 6 7 8 9
    // - 1 2 3 4 5 6 7 8 9
    if (isEmpty())
    {
        cout << "=> Queue is empty !" << endl;
        return;
    }
    front++;
    ;
    if (front > maxsize - 1)
        front = 0;
    count--;
}

int MyCircularQueue::Front()
{
    return list[front + 1];
}

int MyCircularQueue::Rear()
{
    return list[rear];
}

int MyCircularQueue::size() const
{
    return count;
}

void MyCircularQueue::print()
{
    int f = front;
    int r = rear;

    while (f != r)
    {
        f++;
        if (f > maxsize - 1)
            f = 0;
        cout << list[f];
        if (f != r)
            cout << " => ";
    }
    cout << endl;
}

void MyCircularQueue::printDetail()
{
    cout << "Size : " << size() << endl;
    cout << "Queue :";
    int f = front;
    int r = rear;
    while (f != r)
    {
        f++;
        if (f > maxsize - 1)
            f = 0;
        cout << '[' << list[f] << ']';
    }
    cout << endl;
    cout << "index : ";
    f = front;
    r = rear;
    while (f != r)
    {
        f++;
        if (f > maxsize - 1)
            f = 0;
        cout << f;
        if (f != r)
            cout << " ";
    }
    cout << endl;
    cout << "front : " << front << ", rear : " << rear << endl;
}

int main()
{
    MyCircularQueue myQue;

    cout << "=====Dequeue x 1 =====" << endl;
    myQue.dequeue();
    myQue.printDetail();

    cout << "=====Enqueue x 7 (10 ~ 70) =====" << endl;
    for (int i = 0; i < 7; i++)
    {
        myQue.enqueue((i + 1) * 10);
    }
    myQue.printDetail();

    cout << "=====Dequeue x 3 =====" << endl;
    for (int i = 0; i < 3; i++)
        myQue.dequeue();
    myQue.printDetail();

    cout << "=====Enqueue x 6 (10 ~ 60) =====" << endl;
    for (int i = 0; i < 6; i++)
    {
        myQue.enqueue((i + 1) * 10);
        if (myQue.isFull())
        {
            cout << "=> Queue is full !" << endl;
            break;
        }
    }
    myQue.printDetail();

    return 0;
}