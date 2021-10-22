#include <iostream>

using namespace std;

template <class T> class Node {
private:
    T data; // The object information
    Node* next; // Pointer to the next node element
    Node* prev;

public:

    Node() {
        this->data = this->next = this->prev = NULL;
    }

    Node(T new_data, Node* next_node, Node* prev_node) {
        this->data = new_data;
        this->next = next_node;
        this->prev = prev_node;
    }

    Node(T new_data) {
        this->data = new_data;
        this->next = NULL;
        this->prev = NULL;
    }

    void set_data(T new_data) {
        this->data = new_data;
    }

    T get_data() {
        return this->data;
    }

    void set_next(Node* next_node) {
        this->next = next_node;
    }

    void set_prev(Node* back_node) {
        this->prev = back_node;
    }

    Node* get_next() {
        return this->next;
    }
    Node* get_prev() {
        return this->prev;
    }
};


template <class T> class CircularLinkedList {
    Node<T>* head;
    Node<T>* tail;

public:
    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

    ~CircularLinkedList() {

    }

    // Method adds data to the begining of the list
    void add_begin(T data) {
        if (this->head != NULL) {
            Node<T>* temp = new Node<T>(data);
            temp->set_prev(this->tail);
            temp->set_next(this->head);
            this->head->set_prev(temp);
            this->head = temp;
            this-> tail->set_next(this->head);
            if(this->head->get_next() == this->head){
              this-> tail = temp;
            }
            
        } else{
            this->head = new Node<T>(data);
            this->head->set_prev(this->head);
            this->head->set_next(this->head);
            this->tail = this->head;
        }
    }

    // Method adds data to the end of the list
    void add_end(T data) {
        if (head == NULL) { //if our list is currently empty
            this->add_begin(data); //Create new node of type T
        }
        else { //if not empty add to the end and move the tail
            Node<T>* temp = new Node<T>(data);
            temp->set_prev(this->tail);
            temp->set_next(this->head);
            this->tail->set_next(temp);
            this->tail=temp;
        }
    }

    // Method adds info to the begining of the list
    void add_after_node(T value_insert, T value_target) {
        Node<T>* target_node = this->search_node(value_target);
        // current node is empty the node wasn't found 
        if (!target_node) {
            return;
        }

        if(target_node == this->tail) {
            this->add_end(value_insert);
            return;
        }

        Node<T>* node_insert = new Node<T>(value_insert);
        node_insert->set_next(target_node->get_next());
        node_insert->set_prev(target_node);
        target_node->set_next(node_insert);
    }


    void delete_node(T value) {
        if (!this->head) {
            // Empty linked list, no values to delete
            return;
        }

        // Check if the node to delete is the head
        if (this->head->get_data() == value) {
            Node<T>* temp = this->head;
            this->head = this->head->get_next();
            this->head->set_prev(this->tail);
            this->tail->set_next(this->head);
            delete temp;
            return;
        }
        
        if (this->tail->get_data() == value) {
            Node<T> *temp = this->tail;
            this->tail = this->tail->get_prev();
            this->tail->set_next(this->head);
            this->head->set_prev(this->tail);
            delete temp;
            return;
        }


        Node<T>* target_node = this->search_node(value);

        // current node is empty the node wasn't found 
        if (!target_node) {
            return;
        }

        Node<T>* next = target_node->get_next();
        target_node->get_prev()->set_next(next);
        next->set_prev(target_node->get_prev());
        delete target_node;
    }

    Node<T>* search_node(T value_target) {
        Node<T>* current_node = this->head;
        // Search for the node to delete
        do {
            if (current_node->get_data() == value_target) {
                return current_node;
            }
            current_node = current_node->get_next();
        }while (current_node != this->head);
        
        return NULL;
    }

    void print_list() {
        Node<T>* current_node = this->head;
        do {
            cout << current_node->get_data() << " -> ";

            current_node = current_node->get_next();

        }while (current_node != this->head);
        cout << endl;
    }


};



int main() {
    CircularLinkedList<int> firstList;

    firstList.add_begin(3);
    firstList.add_end(6);
    firstList.add_after_node(7,6); 
    firstList.add_begin(5);
    firstList.add_begin(2);
    firstList.add_end(8);
    firstList.print_list();

    firstList.delete_node(7);
    firstList.delete_node(3);
    firstList.delete_node(5);
    firstList.print_list();
    return 0;
}
