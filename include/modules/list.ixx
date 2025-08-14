module;
#include <cassert>
#include <cstddef>
#include <print>
export module refalgo.list;


export namespace refalgo {
    namespace list {
        template <typename T>
        struct Node {
            T info;
            Node<T>* link;

        public:
            const Node<T>& operator=(const Node<T>& other) {
                info = other.info;
                link = other.link;
                return *this;
            };

            void set_info(const T& new_info) { info = new_info; };
            void set_link(Node<T>* new_link) { link = new_link; };
            T& get_info() { return info; };
            const T& get_info() const { return info; };
            Node<T>* get_link() { return link; };
            const Node<T>* get_link() const { return link; };
            Node<T>() : info(), link(nullptr){};
            Node(const T& elem, Node<T>* ptr = nullptr) : info(elem), link(ptr) {};
            Node(const Node<T>& other) : info(other.info), link(other.link) {};
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
        void reverse_print(list::Node<T>* current) const {
            if (current != nullptr) {
                reverse_print(current->link);
                std::print("{} ", current->info);
            }
        }
        void print_list_reverse() const {
            reverse_print(this->first);
            std::println();
        }
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

        void rotate() {
            if (first == nullptr || first == last) {
                return;
            }
            last->link = first;
            first = first->link;
            last->link->link = nullptr;
            last = last->link;
        }

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
        void insert_first(const T& new_item) override {
            list::Node<T>* new_node = new list::Node<T>;
            new_node->info = new_item;
            new_node->link = this->first;
            this->first = new_node;

            this->count++;

            if (this->last == nullptr) {
                this->last = new_node;
            }
        };
        void insert_last(const T& new_item) override {
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
        void delete_node(const T& delete_item) override {
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

    template <typename T>
    struct OrderedLinkedList : public LinkedList<T> {
    public:
        bool search(const T& search_item) const override {
            bool found = false;
            list::Node<T>* current = this->first;

            while (current != nullptr && !found) {
                if (current->info >= search_item) {
                    found = true;
                }
                else {
                    current = current->link;
                }
            }
            if (found) {
                found = (current->info == search_item);
            }
            return found;
        };
        void insert(const T& new_item) {
            list::Node<T>*current, *trail_current = nullptr, *new_node = new list::Node<T>;
            bool found;
            new_node->info = new_item;
            new_node->link = nullptr;

            if (this->first == nullptr) {
                this->first = new_node;
                this->last = new_node;
                this->count++;
            }
            else {
                current = this->first;
                found = false;

                while (current != nullptr && !found) {
                    if (current->info >= new_item) {
                        found = true;
                    }
                    else {
                        trail_current = current;
                        current = current->link;
                    }
                }
                if (current == this->first) {
                    new_node->link = this->first;
                    this->first = new_node;
                    this->count++;
                }
                else {
                    trail_current->link = new_node;
                    new_node->link = current;

                    if (current == nullptr) {
                        this->last = new_node;
                    }
                    this->count++;
                }
            }
        };
        void insert_first(const T& new_item) override { insert(new_item); };
        void insert_last(const T& new_item) override { insert(new_item); };
        void delete_node(const T& delete_item) override {
            list::Node<T>*current, *trail_current = nullptr;
            bool found;
            if (this->first == nullptr) {
                std::println("Cannot delete from an empty list");
            }
            else {
                current = this->first;
                found = false;

                while (current != nullptr && !found) {
                    if (current->info >= delete_item) {
                        found = true;
                    }
                    else {
                        trail_current = current;
                        current = current->link;
                    }
                }

                if (current == nullptr) {
                    std::println("The item to be deleted is not in the list");
                }
                else {
                    if (current->info == delete_item) {
                        if (this->first == current) {
                            this->first = this->first->link;
                            if (this->first == nullptr) {
                                this->last = nullptr;
                            }
                            delete current;
                        }
                        else {
                            trail_current->link = current->link;
                            if (current == this->last) {
                                this->last = trail_current;
                            }
                            delete current;
                        }
                        this->count--;
                    }
                    else {
                        std::println("The item to be deleted is not in the list.");
                    }
                }
            }
        };
    };

    namespace duo {
        template <typename T>
        struct Node {
            T info;
            Node<T>* next;
            Node<T>* back;
        };
    } // namespace duo

    template <typename T>
    struct DoublyLinkedList {
    public:
        /*const*/ DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);
        void initialize() { destroy(); };
        bool is_empty() const { return first == nullptr; };
        void destroy() {
            duo::Node<T>* temp;
            while (this->first != nullptr) {
                temp = this->first;
                this->first = this->first->next;
                delete temp;
            }
            this->last = nullptr;
            this->count = 0;
        };
        void print() const {
            duo::Node<T>* current;
            current = first;
            while (current != nullptr) {
                std::print("{} ", current->next);
            }
        };
        void reverse_print() const {
            duo::Node<T>* current = last;
            while (current != nullptr) {
                std::print("{} ", current->info);
            }
        };
        int length() const { return count; };
        T front() const {
            assert(first != nullptr);
            return first->info;
        };
        T back() const {
            assert(last != nullptr);
            return last->info;
        };
        bool search(const T& search_item) const {
            bool found = false;
            duo::Node<T>* current = first;
            while (current != nullptr && !found) {
                if (current->info >= search_item) {
                    found = true;
                }
                else {
                    current = current->next;
                }
            }
            if (found) {
                found = (current->info == search_item);
            }
            return found;
        };
        void insert(const T& insert_item) {
            duo::Node<T>*current, *trail_current, *new_node = new duo::Node<T>;
            bool found;
            new_node->info = insert_item;
            new_node->next = nullptr;
            new_node->back = nullptr;
            if (first == nullptr) {
                first = new_node;
                last = new_node;
                count++;
            }
            else {
                found = false;
                current = first;
                while (current != nullptr && !found) {
                    if (current->info >= insert_item) {
                        found = true;
                    }
                    else {
                        trail_current = current;
                        current = current->next;
                    }
                }
                if (current == first) {
                    first->back = new_node;
                    new_node->next = first;
                    first = new_node;
                    count++;
                }
                else {
                    if (current != nullptr) {
                        trail_current->next = trail_current;
                        new_node->back = trail_current;
                        new_node->next = current;
                        current->back = new_node;
                    }
                    else {
                        trail_current->next = new_node;
                        new_node->back = trail_current;
                        last = new_node;
                    }
                    count++;
                }
            }
        };
        void delete_node(const T& delete_item) {
            duo::Node<T>*current, *trail_current;
            bool found;

            if (first == nullptr) {
                std::println("Cannot delete from an empty list.");
            }
            else if (first->info == delete_item) {
                current = first;
                first = first->next;
                if (first != nullptr) {
                    first->back = nullptr;
                }
                else {
                    last = nullptr;
                }
                count++;
                delete current;
            }
            else {
                found = false;
                current = first;
                while (current != nullptr && !found) {
                    if (current->info == delete_item) {
                        found = true;
                    }
                    else {
                        current = current->next;
                    }
                }
                if (current == nullptr) {
                    std::println("The item to be deleted is not in the list.");
                }
                else if (current->info == delete_item) {
                    trail_current = current->back;
                    trail_current->next = current->next;
                    if (current->next != nullptr) {
                        current->next->back = trail_current;
                    }
                    if (current == last) {
                        last = trail_current;
                    }
                    count--;
                    delete current;
                }
                else {
                    std::println("The item to be deleted is not in the list.");
                }
            }
        }
        DoublyLinkedList() : last(nullptr), first(nullptr), count(0) {};
        DoublyLinkedList(const DoublyLinkedList& other) : first(nullptr), last(nullptr) { copy_list(other); };
        ~DoublyLinkedList() { destroy(); };

    protected:
        int count;
        duo::Node<T>* first;
        duo::Node<T>* last;

    private:
        void copy_list(const DoublyLinkedList& other);
    };


    struct IntLinkedList : public UnorderedLinkedList<int> {
    public:
        void split_even_odd_list(IntLinkedList& even_list, IntLinkedList& odd_list) {
            refalgo::list::Node<int>* current = this->first;
            while (current != nullptr) {
                if (current->info % 2 == 0) {
                    even_list.insert_last(current->info);
                }
                else {
                    odd_list.insert_last(current->info);
                }
                current = current->link;
            }
        }
    };
} // namespace refalgo
