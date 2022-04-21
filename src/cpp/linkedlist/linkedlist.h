#include <memory>

namespace mb_ds {
    namespace linkedlist {
        class Node {
        public:
          Node(int data): data{data}, next{nullptr} {}
          Node(int data, Node* next): data{data}, next{next} {}

          void append_to_tail(int data);

          int data;
          std::unique_ptr<Node> next;
        };

        // deletes the first node with data data if it exists
        Node* delete_node(int data, Node* head);
    }
}
