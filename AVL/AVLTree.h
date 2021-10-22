#ifndef _BST_H_
#define _BST_H_

  #include<iostream>
  #include "NodeTree.h"

  template <class T>
  class AVLTree { 
  private:
      NodeTree<T> *root;
      void preorder(NodeTree<T>* nodo);
      void postorder(NodeTree<T>* nodo);
      void inorder(NodeTree<T>* nodo);
      
      // AVL methods
      int max(int a, int b);
      NodeTree<T> *rightRotate(NodeTree<T> *y);
      NodeTree<T> *leftRotate(NodeTree<T> *x);
      int getBalance(NodeTree<T> *N);

  public: 
      AVLTree();
      ~AVLTree();
      void clearMemory(NodeTree<T> *p);
      bool search(T valor);
      void insert(T valor);
      NodeTree<T> *insertRec(NodeTree<T> *r, T valor);
      void callPreorder();
      void callPostorder();
      void callInorder(); 
      // AVL methods
      int height(NodeTree<T> *N);
      
      
  }; 

  template<class T>
  AVLTree<T>::AVLTree() {
    std::cout << "--->Creando un AVLTree vacio: " <<  this << std::endl;
    root = nullptr;
  }

  template<class T>
  AVLTree<T>::~AVLTree() {
    std::cout << "--->Liberando memoria del AVLTree: " << this << std::endl;
    clearMemory(root);
  }

  template<class T>
  void AVLTree<T>::clearMemory(NodeTree<T> *p) {
    if (p != NULL) {
      clearMemory(p->left);
      clearMemory(p->right);
      delete p;
      p = NULL;
    }
  }

  template<class T>
  bool AVLTree<T>::search(T valor) {
    NodeTree<T> *p = root;
    while(p != nullptr) {
      if (p->data == valor) {
        return true;
      }
      else { 
        p = (valor < p->data ? p->left : p->right);
      }
    }
    return false;
  }

  // A utility function to get the
  // height of the tree
  template<class T>
  int AVLTree<T>::height(NodeTree<T> *N) {
      if (N == nullptr)
          return 0;
      return N->height;
  }
  
  // A utility function to get maximum
  // of two integers
  template<class T>
  int AVLTree<T>::max(int a, int b) {
      return (a > b)? a : b;
  }

  // A utility function to right
  // rotate subtree rooted with y
  // See the diagram given above.
  template<class T>
  NodeTree<T> *AVLTree<T>::rightRotate(NodeTree<T> *y) {
    NodeTree<T> *x = y->left;
    NodeTree<T> *T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    // Return new root
    return x;
  }

  // A utility function to left
  // rotate subtree rooted with x
  // See the diagram given above.
  template<class T> 
  NodeTree<T> *AVLTree<T>::leftRotate(NodeTree<T> *x) {
      NodeTree<T> *y = x->right;
      NodeTree<T> *T2 = y->left;
      // Perform rotation
      y->left = x;
      x->right = T2;
      // Update heights
      x->height = max(height(x->left), height(x->right)) + 1;
      y->height = max(height(y->left), height(y->right)) + 1;
      // Return new root
      return y;
  }
  
  // Get Balance factor of node N
  template<class T> 
  int AVLTree<T>::getBalance(NodeTree<T> *N) {
      if (N == nullptr)
          return 0;
      return height(N->left) - height(N->right);
  }

  // Recursive function to insert a key
  // in the subtree rooted with node and
  // returns the new root of the subtree.
  template<class T>
  NodeTree<T>* AVLTree<T>::insertRec(NodeTree<T>* node, T key) {
      /* 1. Perform the normal BST insertion */
      if (node == NULL)
          return(new NodeTree<T>(key));
  
      if (key < node->data)
          node->left = insertRec(node->left, key);
      else if (key > node->data)
          node->right = insertRec(node->right, key);
      else // Equal keys are not allowed in BST
          return node;
  
      /* 2. Update height of this ancestor node */
      node->height = 1 + max(height(node->left),
                          height(node->right));
  
      /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
      int balance = getBalance(node);
  
      // If this node becomes unbalanced, then
      // there are 4 cases
  
      // Left Left Case
      if (balance > 1 && key < node->left->data)
          return rightRotate(node);
  
      // Right Right Case
      if (balance < -1 && key > node->right->data)
          return leftRotate(node);
  
      // Left Right Case
      if (balance > 1 && key > node->left->data) {
          node->left = leftRotate(node->left);
          return rightRotate(node);
      }
  
      // Right Left Case
      if (balance < -1 && key < node->right->data) {
          node->right = rightRotate(node->right);
          return leftRotate(node);
      }
  
      /* return the (unchanged) node pointer */
      return node;
  }

  template<class T>
  void AVLTree<T>::insert(T valor) {
    root = insertRec(root, valor);  
  }

  template<class T>
  void AVLTree<T>::preorder(NodeTree<T>* nodo){
      if(nodo != nullptr){
        std::cout << nodo->data << " ";
        preorder(nodo->left); // left
        preorder(nodo->right); // right
      }
  }
    

  template<class T>
  void AVLTree<T>::inorder(NodeTree<T>* nodo) {
      if(nodo != nullptr){
      inorder(nodo->left);
      std::cout << nodo->data << " ";
      inorder(nodo->right);
      }
  }

  template<class T>
  void AVLTree<T>::postorder(NodeTree<T>* nodo) {
      if(nodo != nullptr){
      postorder(nodo->left);
      postorder(nodo->right);
      std::cout << nodo->data << " ";
      }
  }

  template<class T>
  void AVLTree<T>::callPostorder() {
    postorder(root);
    std::cout << std::endl;
  }

  template<class T>
  void AVLTree<T>::callInorder(){
    inorder(root);
    std::cout << std::endl;
  }

  template<class T>
  void AVLTree<T>::callPreorder(){
    preorder(root);
    std::cout << std::endl;
  }

#endif // _BST_H_