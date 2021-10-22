#include<iostream>
#include<vector>
using namespace std;

template <class T>class Node{
    public:
        T data;
        Node* next;

        void set_data(T new_data){
            this->data=new_data;
        }
        void set_next(Node *next_node){
            this->next=next_node;
        }
};


