module;
#include <cassert>
#include <print>

export module refalgo.stack;

import refalgo.list;


export namespace refalgo {

// Abstract Stack ADT
template <typename T>
struct StackSpec {
    virtual void initialize() = 0;
    virtual bool is_empty() const = 0;
    virtual bool is_full() const = 0;
    virtual void push(const T& new_item) = 0;
    virtual T top() const = 0;
    virtual void pop() = 0;
    virtual ~StackSpec() = default;
};

template <typename T>
struct Stack : public StackSpec<T> {
public:
    const Stack<T>& operator=(const Stack<T>& other) {
        if (this != &other) {
            copy(other);
        }
        return *this;
    };
    void initialize() override { stack_top = 0; };
    bool is_empty() const override { return stack_top == 0; };
    bool is_full() const override { return stack_top == max_stack_size; };
    void push(const T& new_item) override {
        if (!is_full()) {
            list[stack_top] = new_item;
            stack_top++;
        }
        else {
            std::println("Cannot add to a full stack.");
        }
    };
    T top() const override {
        assert(stack_top != 0);
        return list[stack_top - 1];
    };
    void pop() override {
        if (!is_empty()) {
            stack_top--;
        }
        else {
            std::println("Cannot remove from an empty stack");
        }
    };
    Stack<T>(int stack_size = 100) {
        if (stack_size <= 0) {
            std::println("Size of the array to hold must be positive.");
            std::println("Creating an array of size 100.");
            max_stack_size = 100;
        }
        else {
            max_stack_size = stack_size;
        }
        stack_top = 0;
        list = new T[max_stack_size];
    }
    Stack<T>(const Stack<T>& other) {
        list = nullptr;
        copy(other);
    }
    // Remove all elements from the stack
    ~Stack() { delete[] list; }

private:
    int max_stack_size;
    int stack_top;
    T* list;

    void copy(const Stack<T>& other) {
        delete[] list;
        max_stack_size = other.max_stack_size;
        stack_top = other.stack_top;

        list = new T[max_stack_size];

        for (int j = 0; j < stack_top; j++) {
            list[j] = other.list[j];
        }
    };
};

namespace stack {
template <typename T>
struct Node {
    T info;
    Node<T>* link;
};
} // namespace stack

namespace linked {
template <typename T>

struct Stack : public StackSpec<T> {
public:
    Stack<T>& operator=(const Stack<T>& other) {
        if (this != &other) {
            copy(other);
        }
        return *this;
    };
    bool is_empty() const override { return stack_top == nullptr; };
    bool is_full() const override { return false; };
    void initialize() override {
        stack::Node<T>* temp;
        while (stack_top != nullptr) {
            temp = stack_top;
            stack_top = stack_top->link;
            delete temp;
        }
    };
    void push(const T& new_item) override {
        stack::Node<T>* new_node = new stack::Node<T>;
        new_node->info = new_item;
        new_node->link = stack_top;
        stack_top = new_node;
    };
    T top() const override {
        assert(stack_top != nullptr);
        return stack_top->info;
    };
    void pop() override {
        stack::Node<T>* temp;
        if (stack_top != nullptr) {
            temp = stack_top;
            stack_top = stack_top->link;
            delete temp;
        }
        else {
            std::println("Cannot remove from an empty stack.");
        }
    };
    Stack<T>(const Stack<T>& other) : stack_top(nullptr) { copy(other); };
    Stack<T>() : stack_top(nullptr){};
    ~Stack() { initialize(); };

protected:
    stack::Node<T>* stack_top;
    void copy(const Stack<T>& other) {
        stack::Node<T>*new_node, *current, *last;
        if (stack_top != nullptr) {
            initialize();
        }
        if (other.stack_top == nullptr) {
            stack_top = nullptr;
        }
        else {
            current = other.stack_top;

            stack_top = new stack::Node<T>;
            stack_top->info = current->info;
            stack_top->link = nullptr;

            last = stack_top;
            current = current->link;

            while (current != nullptr) {
                new_node = new stack::Node<T>;

                new_node->info = current->info;
                new_node->link = nullptr;
                last->link = new_node;
                last = new_node;
                current = current->link;
            }
        }
    };
};
} // namespace linked

namespace ul::linked {
template <typename T>
struct Stack : public refalgo::UnorderedLinkedList<T> {
    void initialize() { UnorderedLinkedList<T>::initialize_list(); };
    bool is_empty() const { return UnorderedLinkedList<T>::is_empty(); };
    bool is_full() const { return false; };
    void push(const T& new_item) { UnorderedLinkedList<T>::insert_first(new_item); };
    T top() const { return UnorderedLinkedList<T>::front(); };
    void pop() {
        if (!is_empty()) {
            this->delete_node(this->front());
        }
        else {
            std::println("Cannot remove from an empty stack.");
        }
    };
};
} // namespace ul::linked

} // namespace refalgo
