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
