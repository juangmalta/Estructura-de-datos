#include <iostream>

using namespace std;

template <class T> class Node {


    public:
        Node(T new_data,int prio, Node* next_node, Node* prev_node){
            this->data = new_data;
            this->next = next_node;
            this->prev = prev_node;
        }

        Node(T new_data, int p){
            this->data = new_data;
            this->priority = p;
            this->next = NULL;
            this->prev = NULL;
        }

        void set_data(T new_data){
            this->data = new_data;
        }

        T get_data(){
            return this->data;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        }

        Node* get_next(){
            return this->next;
        }

        void set_prev(Node *prev_node) {
            this->prev = prev_node;
        }

        Node* get_prev() {
            return this->prev;
        }

        int get_prio(){
          return this -> priority;
        }
};


template <class T> class PriortiyQueue{
    Node<T>* front;
    Node<T>* rear;
    int size;

    public:
        PriortiyQueue(){
            front = NULL;
            rear = NULL;
        }

        // Method adds info to the begining of the list
        void enqueue(T add, int prio) {
          Node<T> *newNode = new Node<T>(add, prio);
          if(size == 0){
              this->rear = newNode;
              this->front = this->rear;
              newNode->set_next(NULL);
              newNode->set_prev(NULL);
              size ++;
          }

          else{
            Node<T>* current_node = this->rear;
              // Search for the node to delete
            while(current_node->get_prio()<= newNode->get_prio()){
                current_node = current_node->get_next();
            }

              // current node is empty the node wasn't found
            if(!current_node){
                return;
            }

            Node<T>* next_square = current_node->get_next();
            Node<T>* node_insert = new Node<T>(add,prio, next_square, current_node);

            //cout << node_insert->get_prev() << endl;
            next_square->set_prev(node_insert);
            current_node->set_next(node_insert);
          }
        }

        void dequeue (){
         if(this->size > 0){
          Node<T> *node2delete = this->front;
          this->front = node2delete->get_prev();
          this->front->set_next(NULL);
          delete node2delete;
          size--;

      }
      else{
        cout<<"Empty queue <3"<<endl;
      }
    }

    T getFront(){
      if (size==0){
        return -1;
      }
      else return this->front->get_data();

    }
};

int main(){
  PriortiyQueue<char> Cola;
  Cola.enqueue('A',1);
  Cola.enqueue('B',2);
  Cola.enqueue('C',3);
  Cola.enqueue('D',4);
  Cola.enqueue('E',2);
  Cola.enqueue('C',4);
  cout<<Cola.getFront()<<endl;
  Cola.dequeue();
  cout<<Cola.getFront()<<endl;
  Cola.dequeue();
  Cola.dequeue();
  cout<<Cola.getFront()<<endl;
  Cola.dequeue();
  cout<<Cola.getFront()<<endl;
  return 0;
}
