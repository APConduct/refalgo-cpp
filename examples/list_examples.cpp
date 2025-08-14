#include <iostream>
import refalgo;

int main() {
    using namespace refalgo;

    // Example: UnorderedLinkedList
    UnorderedLinkedList<int> ulist;
    ulist.insert_first(10);
    ulist.insert_last(20);
    ulist.insert_first(5);
    std::cout << "UnorderedLinkedList contents: ";
    ulist.print();
    std::cout << "\nLength: " << ulist.length() << "\n";
    std::cout << "Search 20: " << (ulist.search(20) ? "Found" : "Not found") << "\n";
    ulist.delete_node(10);
    std::cout << "After deleting 10: ";
    ulist.print();
    std::cout << "\n";

    // Example: OrderedLinkedList
    OrderedLinkedList<int> olist;
    olist.insert_first(15);
    olist.insert_last(5);
    olist.insert_last(25);
    olist.insert_last(10);
    std::cout << "OrderedLinkedList contents: ";
    olist.print();
    std::cout << "\nLength: " << olist.length() << "\n";
    std::cout << "Search 10: " << (olist.search(10) ? "Found" : "Not found") << "\n";
    olist.delete_node(15);
    std::cout << "After deleting 15: ";
    olist.print();
    std::cout << "\n";

    // Iterator example
    std::cout << "Iterating OrderedLinkedList: ";
    for (auto it = olist.begin(); it != olist.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
