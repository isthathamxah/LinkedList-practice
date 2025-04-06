#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int info;
    Node* next;
    Node* pre;
    Node(int val = 0) {
        info = val;
        next = NULL;
        pre = NULL;
    }
};

class list
{
    Node* head;
public:
    list()
    {
        head = NULL;
    }

    void IAS(int newValue)
    {
        Node* p = new Node();
        p->info = newValue;
        p->next = head;
        p->pre = NULL;
        if (head != NULL)
        {
            head->pre = p;
        }
        head = p;
    }

    void DAS()
    {
        if (head == NULL)
        {
            cout << "List Underflow !!";
            return;
        }
        Node* p = head;
        head = head->next;
        delete p;
        if (head != NULL)
            head->pre = NULL;
    }

    void IAE(int newValue)
    {
        if (head == NULL)
        {
            IAS(newValue);
            return;
        }
        Node* q = NULL;
        Node* p;
        for (p = head; p != NULL; p = p->next)
        {
            q = p;
        }

        p = new Node();
        p->info = newValue;
        p->next = NULL;
        q->next = p;
        p->pre = q;
    }

    void DAE()
    {
        if (head == NULL)
        {
            cout << "List UnderFlow!!";
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* p;
        Node* q = NULL;
        for (p = head; p->next != NULL; p = p->next)
        {
            q = p;
        }
        delete p;
        q->next = NULL;
    }

    void IAM(int key, int newValue)
    {
        Node* p;
        for (p = head; p != NULL && p->info != key; p = p->next);

        if (p == NULL)
        {
            IAE(newValue);
        }
        else
        {
            Node* q = new Node();
            q->info = newValue;
            Node* r = p->next;

            q->next = r;
            p->next = q;
            q->pre = p;

            if (r != NULL) {
                r->pre = q;
            }
        }
    }

    void DAM(int key)
    {
        if (head == NULL)
        {
            cout << "List is Empty";
            return;
        }

        if (head->info == key)
        {
            DAS();
            return;
        }

        Node* q = NULL;
        Node* p;
        for (p = head; p != NULL && p->info != key; p = p->next)
            q = p;

        if (p == NULL)
        {
            cout << "Key not found";
            return;
        }

        Node* r = p->next;
        q->next = r;
        if (r != NULL)
        {
            r->pre = q;
        }
        delete p;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        for (Node* p = head; p != nullptr; p = p->next) {
            cout << p->info << " ";
        }
        cout << endl;
    }
    bool isEmpty()
    {
        return head = NULL;
    }
};

class Stack {
    list l;
public:
    void push(int newValue);
    void pop();
    bool isEmpty();
   
    void display();
};
void Stack::push(int newValue)
{
    l.IAS(newValue);
}
void Stack::pop() 
{
    l.DAS();
}
bool Stack::isEmpty()
{
    return l.isEmpty();
}
void Stack::display()
{
    l.display();
}
class Queue {
    list l;
public:
    void insert(int newValue)
    {
        l.IAE(newValue);
    }
    void remove()
    {
        l.DAE();
    }
    bool isEmpty()
    {
        return l.isEmpty();
    }
    void display()
    {
        l.display();
    }
};
int main()
{
    cout << "Doubly Linked List:" << endl;
    list n;
    n.IAS(10);
    n.IAM(10, 2);
    n.IAE(22);
    n.display();

    cout << "\nQueue: " << endl;
    Queue q;
    q.insert(1);
    q.insert(2);
    q.display();

    cout << "\nStack : " << endl;
    Stack s;
    s.push(1);
    s.push(2);
    s.display();
    return 0;
}
