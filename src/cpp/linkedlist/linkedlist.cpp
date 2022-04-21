#include "linkedlist.h"
#include <memory>

using namespace mb_ds;

void linkedlist::Node::append_to_tail(int data) {
    // TODO:: why namespace for node not found automatically
    if (next == nullptr) {
        next = std::unique_ptr<Node>(new mb_ds::linkedlist::Node(data));
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
        return head->next.get();
    }
    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != data) {
        curr = curr->next.get();
    }
    if(curr->next != nullptr) {
        auto tmp = std::move(curr->next);
        curr->next = std::move(tmp->next);
    }
    return head;
}
