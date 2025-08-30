#include <print>

import refalgo;

int main() {
    using namespace refalgo;

    // Example: Array-based Stack
    std::println("=== Array-based Stack Example ===");
    Stack<int> array_stack(5); // Create stack with capacity 5

    // Push some elements
    array_stack.push(10);
    array_stack.push(20);
    array_stack.push(30);

    std::println("Stack top after pushes: {}", array_stack.top());
    std::println("Stack is empty: {}", array_stack.is_empty() ? "Yes" : "No");
    std::println("Stack is full: {}", array_stack.is_full() ? "Yes" : "No");

    // Pop elements
    while (!array_stack.is_empty()) {
        std::println("Popping: {}", array_stack.top());
        array_stack.pop();
    }

    // Try to push more than capacity
    std::println("\nFilling stack to capacity:");
    for (int i = 1; i <= 6; i++) { // Try to push 6 items into capacity-5 stack
        std::print("Pushing {}: ", i);
        array_stack.push(i);
    }

    std::println("\n=== Linked Stack Example ===");
    linked::Stack<std::string> linked_stack;

    // Push some string elements
    linked_stack.push("First");
    linked_stack.push("Second");
    linked_stack.push("Third");

    std::println("Stack top: {}", linked_stack.top());
    std::println("Stack is empty: {}", linked_stack.is_empty() ? "Yes" : "No");
    std::println("Stack is full: {}", linked_stack.is_full() ? "Yes" : "No");

    // Pop all elements
    std::println("\nPopping all elements:");
    while (!linked_stack.is_empty()) {
        std::println("Popping: {}", linked_stack.top());
        linked_stack.pop();
    }

    // Try to pop from empty stack
    std::println("\nTrying to pop from empty stack:");
    linked_stack.pop();

    std::println("\n=== Stack Copy Example ===");
    Stack<int> original_stack(10);
    original_stack.push(100);
    original_stack.push(200);
    original_stack.push(300);

    // Copy constructor
    Stack<int> copied_stack = original_stack;

    std::println("Original stack top: {}", original_stack.top());
    std::println("Copied stack top: {}", copied_stack.top());

    // Modify original to show they're independent
    original_stack.pop();
    std::println("After popping from original:");
    std::println("Original stack top: {}", original_stack.top());
    std::println("Copied stack top (unchanged): {}", copied_stack.top());

    std::println("\n=== UnorderedLinkedList-based Stack Example ===");
    ul::linked::Stack<int> ul_stack;

    // Push some elements
    ul_stack.push(10);
    ul_stack.push(20);
    ul_stack.push(30);

    std::println("UL Stack top: {}", ul_stack.top());
    std::println("UL Stack is empty: {}", ul_stack.is_empty() ? "Yes" : "No");
    std::println("UL Stack is full: {}", ul_stack.is_full() ? "Yes" : "No");
    std::println("UL Stack length: {}", ul_stack.length()); // Inherited from UnorderedLinkedList

    // Pop all elements
    std::println("\nPopping all elements from UL Stack:");
    while (!ul_stack.is_empty()) {
        std::println("Popping: {}", ul_stack.top());
        ul_stack.pop();
    }

    // Demonstrate inherited list functionality
    std::println("\nDemonstrating inherited list functionality:");
    ul_stack.push(100);
    ul_stack.push(200);
    ul_stack.push(300);

    std::print("Stack contents (using inherited print method): ");
    ul_stack.print();
    std::println();

    std::println("Search for 200 in stack: {}", ul_stack.search(200) ? "Found" : "Not found");
}
