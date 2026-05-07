#include <iostream>
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
    // 생성자
    MyLLQueue() {
        front = NULL;
        rear = NULL;
    }

    // 소멸자
    ~MyLLQueue() {
        initialize();
    }

    // Queue 초기화
    void initialize() {
        while (!isEmpty()) {
            dequeue();
        }
        front = rear = NULL;
    }

    // Queue가 비어있는지 확인
    bool isEmpty() const {
        return front == NULL;
    }

    // 데이터 삽입
    void enqueue(const int& value) {

        Node* newNode = new Node(value);

        // Queue가 비어있을 때
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // 데이터 삭제
    void dequeue() {

        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node* temp = front;

        // 노드가 1개일 때
        if (front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
        }

        delete temp;
    }

    int getData(int type) const {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        if(type == 0){
            return front->data;
        } else {
            return rear->data;
        }
    }

    // Front 값 반환
    int Front() const {
        return getData(0);

        // if (isEmpty()) {
        //     cout << "Queue is Empty!" << endl;
        //     return -1;
        // }

        // return front->data;
    }

    // Rear 값 반환
    int Rear() const {
        return getData(1);
        
        // if (isEmpty()) {
        //     cout << "Queue is Empty!" << endl;
        //     return -1;
        // }

        // return rear->data;
    }

    // 전체 출력
    void printAll() const {

        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node* current = front;

        cout << "Queue : ";

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {

    MyLLQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.printAll();

    cout << "Front : " << q.Front() << endl;
    cout << "Rear : " << q.Rear() << endl;

    cout << endl;

    q.dequeue();
    q.printAll();

    cout << "Front : " << q.Front() << endl;
    cout << "Rear : " << q.Rear() << endl;

    cout << endl;

    q.dequeue();
    q.dequeue();

    q.printAll();

    return 0;
}