#include <memory>

namespace mb_ds {
    namespace linkedlist {
        template <typename T>
        class Node {
        public:
          Node(T data): data{data}, next{nullptr} {}
          Node(std::initializer_list<T> data) {
              if (data.size() == 0) {
                  throw std::invalid_argument("data cannot be empty");
              }
              this->data = *data.begin();
              for (unsigned long datum_index = 1; datum_index < data.size(); datum_index++) {
                  this->append_to_tail(data.begin()[datum_index]);
              }
          }
          Node(T data, Node* next): data{data}, next{next} {}

          void append_to_tail(T data);

          T data;
          std::unique_ptr<Node<T>> next;
        };

        // deletes the first node with data data if it exists
        template <typename T>
        Node<T>* delete_node(T data, Node<T>* head);
    }
}

template <typename T>
void mb_ds::linkedlist::Node<T>::append_to_tail(T data) {
    // TODO:: why namespace for node not found automatically
    if (next == nullptr) {
        next = std::unique_ptr<Node<T>>(new mb_ds::linkedlist::Node<T>(data));
    } else {
        next->append_to_tail(data);
    }
}

// TODO:: check namespace finding automatically in argument
template <typename T>
mb_ds::linkedlist::Node<T>* mb_ds::linkedlist::delete_node(T data, mb_ds::linkedlist::Node<T>* head) {
    if (head==nullptr) {
        return head;
    }
    if (head->data == data) {
        return head->next.get();
    }
    Node<T>* curr = head;
    while (curr->next != nullptr && curr->next->data != data) {
        curr = curr->next.get();
    }
    if(curr->next != nullptr) {
        auto tmp = std::move(curr->next);
        curr->next = std::move(tmp->next);
    }
    return head;
}