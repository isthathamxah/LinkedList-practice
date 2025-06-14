#include<iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int info;
    Node* next;
    Node* pre;

    Node() {
        info = 0;
        next = pre = NULL;
    }
};

// List class that manages head and provides all functions
class List {
private:
    Node* head;

    // Creates a new node with the given value
    Node* createNode(int newvalue) {
        Node* p = new Node();
        p->info = newvalue;
        p->next = NULL;
        p->pre = NULL;
        return p;
    }

public:
    List() {
        head = NULL;
    }

    // Sorted insertion into the doubly linked list
    void SortedInsertion(int newvalue) {
        Node* n = createNode(newvalue);

        // Case 1: Empty list
        if (head == NULL) {
            head = n;
            return;
        }

        // Case 2: Insert at beginning
        if (head->info >= newvalue) {
            n->next = head;
            head->pre = n;
            head = n;
            return;
        }

        // Case 3: Insert somewhere in middle or end
        Node* q = NULL;
        Node* p;
        for (p = head; p != NULL && p->info < newvalue; p = p->next) {
            q = p;
        }

        // Inserting between q and p
        n->next = p;
        n->pre = q;
        q->next = n;

        if (p != NULL) {
            p->pre = n;
        }
    }

    // Display list contents
    void Display() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        cout << "Sorted List: ";
        for (Node* p = head; p != NULL; p = p->next) {
            cout << p->info << " ";
        }
        cout << endl;
    }

    // Calculate and return average of all elements
    double Average() {
        if (head == NULL) return 0;

        int sum = 0, count = 0;
        Node* current = head;

        while (current != NULL) {
            sum += current->info;
            count++;
            current = current->next;
        }

        return static_cast<double>(sum) / count;
    }
};

// Main function
int main() {
    List l;
    int n, val;

    cout << "How many numbers to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> val;
        l.SortedInsertion(val);
    }

    l.Display();
    cout << "Average: " << l.Average() << endl;

    return 0;
}
