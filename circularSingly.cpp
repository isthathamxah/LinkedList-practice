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
    list() {
        head = NULL;
    }

    // Insert at start (head)
    void IAS(int newValue)
    {
        Node* p = new Node();
        p->info = newValue;

        if (head == NULL) {
            p->next = p;  // Point to itself in case of circular list
            head = p;
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse until the last node
                temp = temp->next;
            }
            p->next = head;
            temp->next = p;  // Make the last node point to new node
            head = p;        // Update head
        }
    }

    // Delete from start (head)
    void DAS()
    {
        if (head == NULL) {
            cout << "List Underflow !!";
            return;
        }

        // Case: Only one node in the list
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* p = head;
        head = head->next;

        // Traverse to the last node to maintain the circular link
        Node* temp = head;
        while (temp->next != p) {
            temp = temp->next;
        }

        temp->next = head;  // Update last node to point to the new head
        delete p;           // Delete the old head
    }

    // Insert at end
    void IAE(int newValue)
    {
        if (head == NULL) {
            IAS(newValue);
            return;  
        }

        Node* p = new Node();
        p->info = newValue;
        p->next = head;

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = p;
    }

    // Delete at end
    void DAE()
    {
        if (head == NULL) {
            cout << "List UnderFlow!!";
            return;  
        }

        if (head->next == head) {
            DAS();
            return;
        }

        Node* p = head;
        Node* temp = NULL;
        while (p->next != head) {
            temp = p;
            p = p->next;
        }
        temp->next = head;
        delete p;
    }

    // Insert after matching node
    void IAM(int key, int newValue)
    {
        if (head == NULL) {
            cout << "List is Empty" << endl;
            return;
        }

        Node* p = head;
        do {
            if (p->info == key) {
                Node* q = new Node();
                q->info = newValue;
                q->next = p->next;
                p->next = q;
                return;
            }
            p = p->next;
        } while (p != head);  // Keep going until we return to the head

        cout << "Key not found" << endl;
    }

    // Delete the node after matching key
    void DAM(int key)
    {
        if (head == NULL) {
            cout << "List is Empty";
            return;
        }

        if (head->info == key) {
            DAS();
            return;
        }

        Node* p = head;
        do {
            if (p->next->info == key) {
                Node* temp = p->next;
                p->next = temp->next;
                delete temp;
                return;
            }
            p = p->next;
        } while (p != head);

        cout << "Key not found" << endl;
    }

    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* p = head;
        do {
            cout << p->info << " ";
            p = p->next;
        } while (p != head);  // Print until we return to the head
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
