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
        T& operator*() { return current->info; };
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
        LinkedList<T>& operator=(const LinkedList<T>& other_list) {
            if (this != &other_list) {
                copy_list(other_list);
            }
            return *this;
        };
        void initialize_list() { destroy_list(); };
        bool is_empty() const { return first == nullptr; };
        void print() const {
            list::Node<T>* current = first;
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
        LinkedListIterator<T> begin() const { return LinkedListIterator<T>(first); };
        LinkedListIterator<T> end() const { return LinkedListIterator<T>(nullptr); };
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

    template <typename T>
    struct UnorderedLinkedList : public LinkedList<T> {
        bool search(const T& search_item) const override {
            list::Node<T>* current;
            bool found = false;
            current = this->first;
            while (current != nullptr && !found) {
                if (current->info == search_item) {
                    return true;
                }
                current = current->link;
            }
            return false;
        };
        void insert_first(const T& new_item) {
            list::Node<T>* new_node = new list::Node<T>;
            new_node->info = new_item;
            new_node->link = this->first;
            this->first = new_node;

            this->count++;

            if (this->last == nullptr) {
                this->last = new_node;
            }
        };
        void insert_last(const T& new_item) {
            list::Node<T>* new_node = new list::Node<T>;
            new_node->info = new_item;
            new_node->link = nullptr;

            if (this->first == nullptr) {
                this->first = new_node;
                this->last = new_node;
            }
            else {
                this->last->link = new_node;
                this->last = new_node;
            }
            this->count++;
        };
        void delete_node(const T& delete_item) {
            list::Node<T>*current, *trail_current;
            bool found;

            if (this->first == nullptr) {
                std::println("Cannot delete from an empty list.");
            }
            else {
                if (this->first->info == delete_item) {
                    current = this->first;
                    this->first = this->first->link;
                    this->count--;
                    if (this->first == nullptr) {
                        this->last = nullptr;
                    }
                    delete current;
                }
                else {
                    found = false;
                    trail_current = this->first;
                    current = this->first->link;

                    while (current != nullptr && !found) {
                        if (current->info != delete_item) {
                            trail_current = current;
                            current = current->link;
                        }
                        else {
                            found = true;
                        }
                        if (found) {
                            trail_current->link = current->link;
                            this->count--;

                            if (this->last == current) {
                                this->last = trail_current;
                            }
                            delete current;
                        }
                        else {
                            std::println("The item to be deleted is not in the list.");
                        }
                    }
                }
            }
        };
    };
} // namespace refalgo
