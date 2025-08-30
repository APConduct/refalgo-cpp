#include <iostream>
import refalgo;

int main() {
    using namespace refalgo;

    // Example: Array-based Queue
    std::cout << "=== Array-based Queue Example ===\n";
    Queue<int> array_queue(5); // Create queue with capacity 5

    // Add some elements
    array_queue.add_queue(10);
    array_queue.add_queue(20);
    array_queue.add_queue(30);

    std::cout << "Queue front after adds: " << array_queue.front() << "\n";
    std::cout << "Queue back after adds: " << array_queue.back() << "\n";
    std::cout << "Queue is empty: " << (array_queue.is_empty() ? "Yes" : "No") << "\n";
    std::cout << "Queue is full: " << (array_queue.is_full() ? "Yes" : "No") << "\n";

    // Remove elements (FIFO behavior)
    std::cout << "\nRemoving elements (FIFO order):\n";
    while (!array_queue.is_empty()) {
        std::cout << "Front element: " << array_queue.front() << "\n";
        array_queue.delete_queue();
    }

    // Try to add more than capacity
    std::cout << "\nFilling queue to capacity:\n";
    for (int i = 1; i <= 6; i++) { // Try to add 6 items into capacity-5 queue
        std::cout << "Adding " << i << ": ";
        array_queue.add_queue(i);
    }

    std::cout << "\n=== Linked Queue Example ===\n";
    LinkedQueue<std::string> linked_queue;

    // Add some string elements
    linked_queue.add_queue("First");
    linked_queue.add_queue("Second");
    linked_queue.add_queue("Third");

    std::cout << "Queue front: " << linked_queue.front() << "\n";
    std::cout << "Queue back: " << linked_queue.back() << "\n";
    std::cout << "Queue is empty: " << (linked_queue.is_empty() ? "Yes" : "No") << "\n";
    std::cout << "Queue is full: " << (linked_queue.is_full() ? "Yes" : "No") << "\n";

    // Remove all elements
    std::cout << "\nRemoving all elements (FIFO order):\n";
    while (!linked_queue.is_empty()) {
        std::cout << "Front element: " << linked_queue.front() << "\n";
        linked_queue.delete_queue();
    }

    // Try to remove from empty queue
    std::cout << "\nTrying to remove from empty queue:\n";
    linked_queue.delete_queue();

    std::cout << "\n=== Queue Copy Example ===\n";
    Queue<int> original_queue(10);
    original_queue.add_queue(100);
    original_queue.add_queue(200);
    original_queue.add_queue(300);

    // Copy constructor
    Queue<int> copied_queue = original_queue;

    std::cout << "Original queue front: " << original_queue.front() << "\n";
    std::cout << "Original queue back: " << original_queue.back() << "\n";
    std::cout << "Copied queue front: " << copied_queue.front() << "\n";
    std::cout << "Copied queue back: " << copied_queue.back() << "\n";

    // Modify original to show they're independent
    original_queue.delete_queue();
    std::cout << "\nAfter removing from original:\n";
    std::cout << "Original queue front: " << original_queue.front() << "\n";
    std::cout << "Copied queue front (unchanged): " << copied_queue.front() << "\n";

    std::cout << "\n=== Queue Assignment Example ===\n";
    LinkedQueue<int> queue1;
    LinkedQueue<int> queue2;

    // Fill queue1
    queue1.add_queue(1);
    queue1.add_queue(2);
    queue1.add_queue(3);

    // Fill queue2
    queue2.add_queue(99);
    queue2.add_queue(98);

    std::cout << "Before assignment:\n";
    std::cout << "Queue1 front: " << queue1.front() << ", back: " << queue1.back() << "\n";
    std::cout << "Queue2 front: " << queue2.front() << ", back: " << queue2.back() << "\n";

    // Assignment
    queue2 = queue1;

    std::cout << "\nAfter assignment (queue2 = queue1):\n";
    std::cout << "Queue1 front: " << queue1.front() << ", back: " << queue1.back() << "\n";
    std::cout << "Queue2 front: " << queue2.front() << ", back: " << queue2.back() << "\n";

    // Modify queue1 to show independence
    queue1.delete_queue();
    std::cout << "\nAfter removing from queue1:\n";
    std::cout << "Queue1 front: " << queue1.front() << "\n";
    std::cout << "Queue2 front (unchanged): " << queue2.front() << "\n";

    std::cout << "\n=== Circular Array Demonstration ===\n";
    Queue<char> circular_queue(4);

    // Fill queue
    circular_queue.add_queue('A');
    circular_queue.add_queue('B');
    circular_queue.add_queue('C');

    std::cout << "Initial queue front: " << circular_queue.front() << ", back: " << circular_queue.back() << "\n";

    // Remove one, add one (demonstrates circular behavior)
    circular_queue.delete_queue();
    circular_queue.add_queue('D');
    std::cout << "After remove A, add D - front: " << circular_queue.front() << ", back: " << circular_queue.back()
              << "\n";

    circular_queue.delete_queue();
    circular_queue.add_queue('E');
    std::cout << "After remove B, add E - front: " << circular_queue.front() << ", back: " << circular_queue.back()
              << "\n";

    return 0;
}
