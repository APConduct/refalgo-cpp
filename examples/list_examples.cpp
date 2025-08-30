#include <print>

import refalgo;

int main() {
    using namespace refalgo;

    // Example: UnorderedLinkedList
    UnorderedLinkedList<int> ulist;
    ulist.insert_first(10);
    ulist.insert_last(20);
    ulist.insert_first(5);
    std::print("UnorderedLinkedList contents: ");
    ulist.print();
    std::println("\nLength: {}", ulist.length());
    std::println("Search 20: {}", (ulist.search(20) ? "Found" : "Not found"));
    ulist.delete_node(10);
    std::print("After deleting 10: ");
    ulist.print();
    std::println();

    // Example: OrderedLinkedList
    OrderedLinkedList<int> olist;
    olist.insert_first(15);
    olist.insert_last(5);
    olist.insert_last(25);
    olist.insert_last(10);
    std::print("OrderedLinkedList contents: ");
    olist.print();
    std::println("\nLength: {}", olist.length());
    std::println("Search 10: {}", (olist.search(10) ? "Found" : "Not found"));
    olist.delete_node(15);
    std::print("After deleting 15: ");
    olist.print();
    std::println();

    // Iterator example
    std::print("Iterating OrderedLinkedList: ");
    for (auto it = olist.begin(); it != olist.end(); ++it) {
        std::print("{} ", *it);
    }
    std::println();
    return 0;
}
