#include "SinglyLinkedList.h"

bool deleteMiddle(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        return false;
    }
    node->data = node->next->data;
    node->next = node->next->next;
    Node* d;
    d = node->next;
    delete d;
    return true;

}

int main() {
    SinglyLinkedList* list1 = new SinglyLinkedList();

    Node* x;
    for (int i = 1; i <= 5; i++) {
        if (i == 2) {
            x = list1->insert(rand() % 5);
            cout <<"data @ 2nd to be inserted: "<<x->data<<endl<<endl;
        } else {
            list1->insert(rand() % 5);
        }
    }

    list1->print();

    deleteMiddle(x);
    cout << "\nAfter deleting\n" << endl;
    list1->print();


}