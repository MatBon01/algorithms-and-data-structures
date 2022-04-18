#include "linkedlist.h"
#include <iostream>

using namespace mb_ds;

int main() {
    linkedlist::Node* node = new linkedlist::Node {5};

    node->append_to_tail(3);
    node->append_to_tail(7);
    node->append_to_tail(9);

    linkedlist::delete_node(7, node);

    linkedlist::Node* curr = node;
    while (curr != nullptr) {
        std::cout << curr->data << std::endl;
        curr = curr->next;
    }

    delete node;
}
