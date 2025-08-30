module;
#include <cassert>
#include <print>

export module refalgo.queue;

export namespace refalgo {
template <typename T>
struct QueueSpec {
public:
    virtual bool is_empty() const = 0;
    virtual bool is_full() const = 0;
    virtual void initialize() = 0;
    virtual T front() const = 0;
    virtual T back() const = 0;
    virtual void add_queue(const T& new_element) = 0;
    virtual void delete_queue() = 0;
    virtual ~QueueSpec() = default;
};

template <typename T>
struct Queue : public QueueSpec<T> {
    Queue<T>& operator=(const Queue<T>& other) {
        if (this != &other) {
            delete[] list;
            max_size = other.max_size;
            count = other.count;
            queue_front = 0;
            queue_rear = count - 1;
            list = new T[max_size];
            for (int i = 0; i < count; i++) {
                list[i] = other.list[(other.queue_front + i) % other.max_size];
            }
        }
        return *this;
    };
    bool is_empty() const override { return count == 0; };
    bool is_full() const override { return count == max_size; };
    void initialize() override {
        queue_front = 0;
        queue_rear = max_size - 1;
        count = 0;
    };
    T front() const override {
        assert(!is_empty());
        return list[queue_front];
    };
    T back() const override {
        assert(!is_empty());
        return list[queue_rear];
    };
    void add_queue(const T& new_element) override {
        if (!is_full()) {
            queue_rear = (queue_rear + 1) % max_size;
            count++;
            list[queue_rear] = new_element;
        }
        else {
            std::println("Cannot add to a full queue.");
        }
    };
    void delete_queue() override {
        if (!is_empty()) {
            count--;
            queue_front = (queue_front + 1) % max_size;
        }
        else {
            std::println("Cannot remove from an empty queue.");
        }
    };
    Queue<T>(int size = 100) {
        if (size <= 0) {
            std::println("The size of the array to hold the queue must be positive.");
            std::println("Creating an array of size 100");
            max_size = 100;
        }
        else {
            max_size = size;
        }

        queue_front = 0;
        queue_rear = max_size - 1;
        count = 0;
        list = new T[max_size];
    };
    Queue<T>(const Queue<T>& other) {
        max_size = other.max_size;
        count = other.count;
        queue_front = 0;
        queue_rear = count - 1;
        list = new T[max_size];
        for (int i = 0; i < count; i++) {
            list[i] = other.list[(other.queue_front + i) % other.max_size];
        }
    };
    ~Queue() { delete[] list; };

private:
    int max_size;
    int count;
    int queue_front;
    int queue_rear;
    T* list;
};

namespace queue {
template <typename T>
struct Node {
    T info;
    Node<T>* link;
};
} // namespace queue

template <typename T>
struct LinkedQueue : public QueueSpec<T> {
public:
    LinkedQueue<T>& operator=(const LinkedQueue<T>& other) {
        if (this != &other) {
            initialize(); // Clear current queue
            queue::Node<T>* current = other.queue_front;
            while (current != nullptr) {
                add_queue(current->info);
                current = current->link;
            }
        }
        return *this;
    };
    bool is_empty() const override { return queue_front == nullptr; };
    bool is_full() const override { return false; };
    void initialize() override {
        queue::Node<T>* temp;
        while (queue_front != nullptr) {
            temp = queue_front;
            queue_front = queue_front->link;
            delete temp;
        }
        queue_rear = nullptr;
    };
    T front() const override {
        assert(queue_front != nullptr);
        return queue_front->info;
    };
    T back() const override {
        assert(queue_rear != nullptr);
        return queue_rear->info;
    };
    void add_queue(const T& new_element) override {
        queue::Node<T>* new_node = new queue::Node<T>;
        new_node->info = new_element;
        new_node->link = nullptr;
        if (queue_front == nullptr) {
            queue_front = new_node;
            queue_rear = new_node;
        }
        else {
            queue_rear->link = new_node;
            queue_rear = queue_rear->link;
        }
    };
    void delete_queue() override {
        queue::Node<T>* temp;
        if (!is_empty()) {
            temp = queue_front;
            queue_front = queue_front->link;
            delete temp;
            if (queue_front == nullptr) {
                queue_rear = nullptr;
            }
        }
        else {
            std::println("Cannot remove from an empty queue.");
        }
    };
    LinkedQueue() : queue_front(nullptr), queue_rear(nullptr) {}
    LinkedQueue(const LinkedQueue<T>& other) : queue_front(nullptr), queue_rear(nullptr) {
        queue::Node<T>* current = other.queue_front;
        while (current != nullptr) {
            add_queue(current->info);
            current = current->link;
        }
    }
    ~LinkedQueue() {
        queue::Node<T>* temp;
        while (queue_front != nullptr) {
            temp = queue_front;
            queue_front = queue_front->link;
            delete temp;
        }
        queue_rear = nullptr;
    }

private:
    queue::Node<T>* queue_front;
    queue::Node<T>* queue_rear;
};
} // namespace refalgo
