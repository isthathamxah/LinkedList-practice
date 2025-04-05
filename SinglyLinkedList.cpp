#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    int info;
    Node* next;
  
    Node() {
        info = 0;
        next = NULL;
      
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
            DAS();
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
            q ->next = p ->next;
            p->next = q;
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
        q->next = p->next;
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
};

int main()
{
    cout << "Linked List:" << endl;
    list n;
    n.IAS(10);
    n.IAM(10, 2);
    n.IAE(22);
    n.display();

    return 0;
}
