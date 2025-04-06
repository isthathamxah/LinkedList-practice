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
public:
    Node* head;

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
        return head == NULL;
    }
};
void concatenate(list &l1,list&l2)
{
    if (l1.head == NULL)
    {
        l1.head = l2.head;
        return;
    }
    Node* p = l1.head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = l2.head;
    if (l2.head != NULL)
    {
        l2.head->pre = p;
    }
}

int main()
{
    list l1, l2;

    l1.IAE(1);
    l1.IAE(2);
   
    l2.IAE(3);
    l2.IAE(4);

    cout << "List 1 before concatenation: ";
    l1.display();

    cout << "List 2: ";
    l2.display();

    concatenate(l1, l2);

    cout << "List 1 after concatenation: ";
    l1.display();

    return 0;
}
