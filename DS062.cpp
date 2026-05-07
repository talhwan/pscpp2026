#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class MyLLQueue {
private:
    Node* front;
    Node* rear;

public:
    MyLLQueue() {
        front = rear = NULL;
    }

    ~MyLLQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == NULL;
    }

    void enqueue(int value) {

        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {

        if (isEmpty())
            return;

        Node* temp = front;

        if (front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
        }

        delete temp;
    }

    int Front() const {

        if (isEmpty())
            return -1;

        return front->data;
    }
};

string ordinal(int n) {

    if (n == 1) return "1st";
    if (n == 2) return "2nd";
    if (n == 3) return "3rd";

    return to_string(n) + "th";
}

int main() {

    int n;
    cin >> n;

    MyLLQueue q;

    // 초기값
    int first = 1;
    int second = 1;

    q.enqueue(first);
    q.enqueue(second);

    cout << "1st : 1" << endl;

    if (n == 1) {
        cout << "=> fibonacci(1) : 1" << endl;
        return 0;
    }

    cout << "2nd : 1" << endl;

    if (n == 2) {
        cout << "=> fibonacci(2) : 1" << endl;
        return 0;
    }

    int fib = 1;

    for (int i = 3; i <= n; i++) {

        // 첫 번째 값
        int a = q.Front();
        q.dequeue();

        // 두 번째 값
        int b = q.Front();

        // 새로운 피보나치 값
        fib = a + b;

        // Queue에 추가
        q.enqueue(fib);

        cout << ordinal(i) << " : " << fib << endl;
    }

    cout << "=> fibonacci(" << n << ") : " << fib << endl;

    return 0;
}