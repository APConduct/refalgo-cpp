#include <iostream>
import refalgo;

int main() {
    using namespace refalgo;

    // Example: Array-based Stack
    std::cout << "=== Array-based Stack Example ===\n";
    Stack<int> array_stack(5); // Create stack with capacity 5

    // Push some elements
    array_stack.push(10);
    array_stack.push(20);
    array_stack.push(30);

    std::cout << "Stack top after pushes: " << array_stack.top() << "\n";
    std::cout << "Stack is empty: " << (array_stack.is_empty() ? "Yes" : "No") << "\n";
    std::cout << "Stack is full: " << (array_stack.is_full() ? "Yes" : "No") << "\n";

    // Pop elements
    while (!array_stack.is_empty()) {
        std::cout << "Popping: " << array_stack.top() << "\n";
        array_stack.pop();
    }

    // Try to push more than capacity
    std::cout << "\nFilling stack to capacity:\n";
    for (int i = 1; i <= 6; i++) { // Try to push 6 items into capacity-5 stack
        std::cout << "Pushing " << i << ": ";
        array_stack.push(i);
    }

    std::cout << "\n=== Linked Stack Example ===\n";
    linked::Stack<std::string> linked_stack;

    // Push some string elements
    linked_stack.push("First");
    linked_stack.push("Second");
    linked_stack.push("Third");

    std::cout << "Stack top: " << linked_stack.top() << "\n";
    std::cout << "Stack is empty: " << (linked_stack.is_empty() ? "Yes" : "No") << "\n";
    std::cout << "Stack is full: " << (linked_stack.is_full() ? "Yes" : "No") << "\n";

    // Pop all elements
    std::cout << "\nPopping all elements:\n";
    while (!linked_stack.is_empty()) {
        std::cout << "Popping: " << linked_stack.top() << "\n";
        linked_stack.pop();
    }

    // Try to pop from empty stack
    std::cout << "\nTrying to pop from empty stack:\n";
    linked_stack.pop();

    std::cout << "\n=== Stack Copy Example ===\n";
    Stack<int> original_stack(10);
    original_stack.push(100);
    original_stack.push(200);
    original_stack.push(300);

    // Copy constructor
    Stack<int> copied_stack = original_stack;

    std::cout << "Original stack top: " << original_stack.top() << "\n";
    std::cout << "Copied stack top: " << copied_stack.top() << "\n";

    // Modify original to show they're independent
    original_stack.pop();
    std::cout << "After popping from original:\n";
    std::cout << "Original stack top: " << original_stack.top() << "\n";
    std::cout << "Copied stack top (unchanged): " << copied_stack.top() << "\n";
}
