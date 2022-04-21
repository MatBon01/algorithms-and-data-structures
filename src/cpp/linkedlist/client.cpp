#include "linkedlist.h"
#include <iostream>
#include <string>
#include <memory>

using namespace mb_ds;

template <typename T>
void print_list(linkedlist::Node<T>* head) {
    linkedlist::Node<T>* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << std::endl;
        curr = curr->next.get();
    }
}

int main() {
    std::shared_ptr<linkedlist::Node<int>> list1 = std::shared_ptr<linkedlist::Node<int>>(new linkedlist::Node<int> {5, 3, 7, 9});

    linkedlist::delete_node(7, list1.get());

    print_list(list1.get());

    std::shared_ptr<linkedlist::Node<std::string>> list2 = std::shared_ptr<linkedlist::Node<std::string>>(new linkedlist::Node<std::string> {"zero", "one", "two", "gone", "three", "four"});

    linkedlist::delete_node(std::string("gone"), list2.get());

    print_list(list2.get());
}

