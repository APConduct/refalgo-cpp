#include <print>

import refalgo;

int main() {
    using namespace refalgo;

    // Example: Array-based Queue
    std::println("=== Array-based Queue Example ===");
    Queue<int> array_queue(5); // Create queue with capacity 5

    // Add some elements
    array_queue.add_queue(10);
    array_queue.add_queue(20);
    array_queue.add_queue(30);

    std::println("Queue front after adds: {}", array_queue.front());
    std::println("Queue back after adds: {}", array_queue.back());
    std::println("Queue is empty: {}", array_queue.is_empty() ? "Yes" : "No");
    std::println("Queue is full: {}", array_queue.is_full() ? "Yes" : "No");

    // Remove elements (FIFO behavior)
    std::println("\nRemoving elements (FIFO order):");
    while (!array_queue.is_empty()) {
        std::println("Front element: {}", array_queue.front());
        array_queue.delete_queue();
    }

    // Try to add more than capacity
    std::println("\nFilling queue to capacity:");
    for (int i = 1; i <= 6; i++) { // Try to add 6 items into capacity-5 queue
        std::print("Adding {}: ", i);
        array_queue.add_queue(i);
    }

    std::println("\n=== Linked Queue Example ===");
    LinkedQueue<std::string> linked_queue;

    // Add some string elements
    linked_queue.add_queue("First");
    linked_queue.add_queue("Second");
    linked_queue.add_queue("Third");

    std::println("Queue front: {}", linked_queue.front());
    std::println("Queue back: {}", linked_queue.back());
    std::println("Queue is empty: {}", linked_queue.is_empty() ? "Yes" : "No");
    std::println("Queue is full: {}", linked_queue.is_full() ? "Yes" : "No");

    // Remove all elements
    std::println("\nRemoving all elements (FIFO order):");
    while (!linked_queue.is_empty()) {
        std::println("Front element: {}", linked_queue.front());
        linked_queue.delete_queue();
    }

    // Try to remove from empty queue
    std::println("\nTrying to remove from empty queue:");
    linked_queue.delete_queue();

    std::println("\n=== Queue Copy Example ===");
    Queue<int> original_queue(10);
    original_queue.add_queue(100);
    original_queue.add_queue(200);
    original_queue.add_queue(300);

    // Copy constructor
    Queue<int> copied_queue = original_queue;

    std::println("Original queue front: {}", original_queue.front());
    std::println("Original queue back: {}", original_queue.back());
    std::println("Copied queue front: {}", copied_queue.front());
    std::println("Copied queue back: {}", copied_queue.back());

    // Modify original to show they're independent
    original_queue.delete_queue();
    std::println("\nAfter removing from original:");
    std::println("Original queue front: {}", original_queue.front());
    std::println("Copied queue front (unchanged): {}", copied_queue.front());

    std::println("\n=== Queue Assignment Example ===");
    LinkedQueue<int> queue1;
    LinkedQueue<int> queue2;

    // Fill queue1
    queue1.add_queue(1);
    queue1.add_queue(2);
    queue1.add_queue(3);

    // Fill queue2
    queue2.add_queue(99);
    queue2.add_queue(98);

    std::println("Before assignment:");
    std::println("Queue1 front: {}, back: {}", queue1.front(), queue1.back());
    std::println("Queue2 front: {}, back: {}", queue2.front(), queue2.back());

    // Assignment
    queue2 = queue1;

    std::println("\nAfter assignment (queue2 = queue1):");
    std::println("Queue1 front: {}, back: {}", queue1.front(), queue1.back());
    std::println("Queue2 front: {}, back: {}", queue2.front(), queue2.back());

    // Modify queue1 to show independence
    queue1.delete_queue();
    std::println("\nAfter removing from queue1:");
    std::println("Queue1 front: {}", queue1.front());
    std::println("Queue2 front (unchanged): {}", queue2.front());

    std::println("\n=== Circular Array Demonstration ===");
    Queue<char> circular_queue(4);

    // Fill queue
    circular_queue.add_queue('A');
    circular_queue.add_queue('B');
    circular_queue.add_queue('C');

    std::println("Initial queue front: {}, back: {}", circular_queue.front(), circular_queue.back());

    // Remove one, add one (demonstrates circular behavior)
    circular_queue.delete_queue();
    circular_queue.add_queue('D');
    std::println("After remove A, add D - front: {}, back: {}", circular_queue.front(), circular_queue.back());

    circular_queue.delete_queue();
    circular_queue.add_queue('E');
    std::println("After remove B, add E - front: {}, back: {}", circular_queue.front(), circular_queue.back());

    return 0;
}
