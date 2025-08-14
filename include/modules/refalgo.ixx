module;
#include "refalgo.hpp"
export module refalgo;
export namespace refalgo {
    template <typename T>
    using OrderedList = refalgo::OrderedLinkedList<T>;
    template <typename T>
    using UnorderedList = refalgo::UnorderedLinkedList<T>;
    template <typename T>
    using ListNode = refalgo::list::Node<T>;
} // namespace refalgo
