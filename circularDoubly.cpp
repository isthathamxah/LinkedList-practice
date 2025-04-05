#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    int info;
    Node* next;
    Node* prev;

    Node() {
        info = 0;
        next = prev = NULL;
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
            // If the list is empty, the node's next and prev point to itself, making it circular
            p->next = p;
            p->prev = p;
            head = p;  // Set head to the new node
        } else {
            // If the list is not empty, insert the new node at the head
            Node* temp = head->prev;  // Get the last node
            p->next = head;           // The new node points to the current head
            p->prev = temp;           // The new node's prev points to the last node
            head->prev = p;           // The current head's prev points to the new node
            temp->next = p;           // The last node's next points to the new node
            head = p;                 // Update head to point to the new node
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
            head = NULL;  // Set head to NULL when the list becomes empty
            return;
        }

        Node* p = head;          // Save the current head to delete later
        head = head->next;       // Move head to the next node

        // Update the last node to point to the new head
        Node* temp = head->prev;
        temp->next = head;
        head->prev = temp;

        delete p;                // Delete old head
    }

    // Insert at end
    void IAE(int newValue)
    {
        if (head == NULL) {
            IAS(newValue);  // If the list is empty, insert at the start
            return;
        }

        Node* p = new Node();
        p->info = newValue;
        p->next = head;          // The new node points to head (circular)
        p->prev = head->prev;    // The new node's prev points to the last node

        // Update the previous last node to point to the new node
        head->prev->next = p;    // Last node's next points to new node
        head->prev = p;          // Head's prev points to the new node
    }

    // Delete from end
    void DAE()
    {
        if (head == NULL) {
            cout << "List UnderFlow!!";
            return;  
        }

        // Case: Only one node in the list
        if (head->next == head) {
            DAS();  // If only one node, just delete it from the start
            return;
        }

        Node* p = head->prev;    // Get the last node
        Node* temp = p->prev;     // Get the second last node
        temp->next = head;        // The second last node's next points to head
        head->prev = temp;        // Head's prev points to the second last node
        delete p;                 // Delete the last node
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
                // Create a new node
                Node* q = new Node();
                q->info = newValue;
                q->next = p->next;     // The new node's next points to the current node's next
                q->prev = p;           // The new node's prev points to the current node
                p->next->prev = q;     // The current node's next node's prev points to the new node
                p->next = q;           // The current node's next points to the new node
                return;
            }
            p = p->next;
        } while (p != head);  // Keep going until we return to the head

        cout << "Key not found" << endl;  // If the key is not found in the list
    }

    // Delete the node after matching key
    void DAM(int key)
    {
        if (head == NULL) {
            cout << "List is Empty";
            return;
        }

        // Special case: if the node to be deleted is the head
        if (head->info == key) {
            DAS();  // Delete from the start
            return;
        }

        Node* p = head;
        do {
            if (p->next->info == key) {
                // The node to be deleted is p->next
                Node* temp = p->next;
                p->next = temp->next;      // Skip the node to be deleted
                temp->next->prev = p;     // Update the next node's prev pointer
                delete temp;              // Delete the node
                return;
            }
            p = p->next;
        } while (p != head);  // Keep going until we return to the head

        cout << "Key not found" << endl;  // If key is not found
    }

    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* p = head;
        do {
            cout << p->info << " ";    // Print current node's info
            p = p->next;               // Move to the next node
        } while (p != head);  // Keep going until we return to the head
        cout << endl;
    }
};

int main()
{
    cout << "Doubly Circular Linked List:" << endl;
    list n;
    n.IAS(10);
    n.IAM(10, 2);
    n.IAE(22);
    n.display();

    return 0;
}
