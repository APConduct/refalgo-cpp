#pragma once

#include <cassert>
#include <cstddef>
#include <print>
namespace refalgo {
    namespace list {
        template <typename T>
        struct Node {
            T info;
            Node<T>* link;
        };
    } // namespace list

    template <typename T>
    struct LinkedListIterator {
    protected:
        list::Node<T>* current;

    public:
        LinkedListIterator() : current(nullptr) {};
        LinkedListIterator(list::Node<T>* ptr) : current(ptr) {};
        T operator*() { return current->info; };
        LinkedListIterator<T> operator++() {
            current = current->link;
            return *this;
        };
        bool operator==(const LinkedListIterator<T>& rhs) const { return current == rhs.current; };
        bool operator!=(const LinkedListIterator<T>& rhs) const { return current != rhs.current; };
    };

    template <typename T>
    struct LinkedList {
    public:
        const LinkedList<T>& operator=(const LinkedList<T>& other_list) {
            if (this != &other_list) {
                copy_list(other_list);
            }
            return *this;
        };
        void initialize_list() { destroy_list(); };
        bool is_empty() const { return first == nullptr; };
        void print() const {
            list::Node<T>* current;
            current = first;
            while (current != nullptr) {
                std::print("{} ", current->info);
                current = current->link;
            };
        };
        int length() const { return count; };
        void destroy_list() {
            list::Node<T>* temp;
            while (first != nullptr) {
                temp = first;
                first = first->link;
                delete temp;
            }
            last = nullptr;
            count = 0;
        };
        T front() const {
            assert(first != nullptr);
            return first->info;
        };
        T back() const {
            assert(last != nullptr);
            return last->info;
        };
        virtual bool search(const T& search_item) const = 0;
        virtual void insert_first(const T& new_item) = 0;
        virtual void insert_last(const T& new_item) = 0;
        virtual void delete_node(const T& delete_item) = 0;
        LinkedListIterator<T> begin() {
            LinkedListIterator<T> temp(first);
            return temp;
        };
        LinkedListIterator<T> end() {
            LinkedListIterator<T> temp(nullptr);
            return temp;
        };
        LinkedList() : first(nullptr), last(nullptr), count(0) {};
        LinkedList(const LinkedList<T>& other_list) : first(nullptr) { copy_list(other_list); };
        ~LinkedList() { destroy_list(); };

    protected:
        int count;
        list::Node<T>* first;
        list::Node<T>* last;

    private:
        void copy_list(const LinkedList<T>& other_list) {
            list::Node<T>* new_node;
            list::Node<T>* current;
            if (first != nullptr) {
                destroy_list();
            }
            if (other_list.first == nullptr) {
                first = nullptr;
                last = nullptr;
                count = 0;
            }
            else {
                current = other_list.first;
                count = other_list.count;

                first = new list::Node<T>;

                first->info = current->info;
                first->link = nullptr;

                last = first;
                current = current->link;

                while (current != nullptr) {
                    new_node = new list::Node<T>;
                    new_node->info = current->info;
                    new_node->link = nullptr;

                    last->link = new_node;
                    last = new_node;

                    current = current->link;
                }
            }
        };
    };
} // namespace refalgo
