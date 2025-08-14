module;
export module refalgo;

export import refalgo.bubble_sort;
export import refalgo.insertion_sort;
export import refalgo.list;


export namespace refalgo {
    template <typename T>
    using OrderedList = refalgo::OrderedLinkedList<T>;
    template <typename T>
    using UnorderedList = refalgo::UnorderedLinkedList<T>;
    template <typename T>
    using ListNode = refalgo::list::Node<T>;
} // namespace refalgo
