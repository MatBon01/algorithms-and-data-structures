#include "linkedlist.h"

using namespace mb_ds;

void linkedlist::Node::append_to_tail(int data) {
    // TODO:: why namespace for node not found automatically
    // TODO:: are you allowed to use new or am I doing it wrong?
    // TODO:: must you delete the next element in the destructor if it exists?
    if (next == nullptr) {
        next = new mb_ds::linkedlist::Node(data);
    } else {
        next->append_to_tail(data);
    }
}

// TODO:: check namespace finding automatically in argument
linkedlist::Node* linkedlist::delete_node(int data, linkedlist::Node* head) {
    if (head==nullptr) {
        return head;
    }
    if (head->data == data) {
        return head->next;
    }
    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != data) {
        curr = curr->next;
    }
    if(curr->next != nullptr) {
        Node* tmp = curr->next;
        curr->next = tmp->next;
        tmp->next = nullptr;
        // TODO: will this call the destructor
        delete tmp;
    }
    return head;
}
