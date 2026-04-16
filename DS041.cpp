#include <iostream>
using namespace std;

class Node
{
public:
    int data;   // 숫자 정보 저장
    Node *next; // 다음 노드 가리키기!!
    Node(int d)
    {
        data = d;
        next = nullptr; // 이것은 아무것도 가르키지 않는 다는 '포인터' (C++ 11 버젼인가 부터 활용 가능!)
        // next = NULL; // NULL은 진짜 아무것도 가르키기 않는다는 것!! 0도 됨..
    } // 생성자!!, 숫자 정보는 저장하고, next에는 비워두기.
}; // 하나의 노드!!

class LinkedStack
{
private:
    Node *stacktop; // 스택의 맨위가 뭔지!!

public:
    LinkedStack();
    ~LinkedStack();
    void initialize();
    bool isEmpty() const;
    void push(const Node &n);
    void pop();
    int peek() const;
    void printAll() const;
};

LinkedStack::LinkedStack()
{
    stacktop = nullptr;
}

LinkedStack::~LinkedStack()
{
    initialize();
}

void LinkedStack::initialize()
{
    while (!isEmpty())
    {
        pop();
    }
}

bool LinkedStack::isEmpty() const
{
    return stacktop == nullptr;
}

void LinkedStack::push(const Node &n)
{
    Node *node = new Node(n.data);
    if (isEmpty())
    {
        stacktop = node;
        return;
    }

    node->next = stacktop;
    stacktop = node;
}

void LinkedStack::pop()
{
    if (isEmpty())
    {
        return;
    }
    Node *tmp = stacktop;
    stacktop = stacktop->next;
    delete tmp;
}

int LinkedStack::peek() const
{
    return stacktop->data;
}

void LinkedStack::printAll() const
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }

    int count = 0;
    Node *tmp = stacktop;
    while (tmp != nullptr)
    {
        cout << tmp->data;
        if (tmp->next != nullptr)
        {
            cout << " -> ";
        }
        tmp = tmp->next;
        count++;
    }
    cout << " (" << count << " nodes)" << endl;
}

int main()
{
    LinkedStack *linkedStack = new LinkedStack();
    string input;
    int inputVal;
    while (1)
    {

        cin >> input;
        if (input == "push")
        {
            cin >> inputVal;
            linkedStack->push(Node(inputVal));
        }
        else if (input == "pop")
        {
            linkedStack->pop();
        }
        else if (input == "peek")
        {
            cout << linkedStack->peek() << endl;
        }
        else if (input == "print")
        {
            linkedStack->printAll();
        }
        else if (input == "clear")
        {
            linkedStack->initialize();
        }
        else if (input == "q")
        {
            cout << "Bye!";
            break;
        }
    }

    delete linkedStack;

    return 0;
}