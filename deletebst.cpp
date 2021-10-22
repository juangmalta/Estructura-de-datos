#include <iostream>

using namespace std;

template <class T> class node{
    public:
      int key;
      T data; // The object information key
      node *left, *right;

    node(int key, T data) {
        this->key = key;
        this->data = data;
        this->left = this->right = NULL;
    }
};

template<class T> void insertnode(node<T> *root, int key, T value){
  if(key < root->key){
   if(root->left){
    	insertnode(root->left, key, value);
   } else{
    	root->left= new node(key, value);
   }
  }else{
   if(root->right){
    	insertnode(root->right, key, value);
   } else{
    	root->right= new node(key, value);
   }
  }
}

template<class T>void printInorder(node<T> *root){
  if(root){
    printInorder(root->left);
    cout << root->data << endl;
    printInorder(root->right);
  }
}

template<class T> void printPreorder(node<T> *root){
  if(root){
    cout << root->data << endl;
    printInorder(root->left);
    printInorder(root->right);
  }
}

template<class T> void printPostorder(node<T> *root){
  if(root){
    printInorder(root->left);
    printInorder(root->right);
    cout << root->data << endl;
  }
}

template<class T> void printLevel(node<T> *root){
  if(root==NULL){
    return;
  }

  else{
    queue<node<T>*> q;
    q.push(root);
    while(q.empty()==false){
      node<T> * print(q.front());
      cout<<print->data<<endl;
      q.pop();

      if(print->left != NULL){
    		q.push(print->left);
      }

      if(print->right!=NULL){
        q.push(print->right);
      }
    }
  }
}

template<class T> node<T> *search(node<T> *root, int key){
  if(key < root->key){
    if(root->left){
      search(root->left, key);
    } else{
      return root;
    }
    } else{
		if(root->right){
			search(root->right, key);
		} else{
			return root;
		}
	}
}


// template<class T>void nodeDelete(node<T> *root, int key){
//   if(!root){

//     return;
//   }
//   // Encontrar el valor.


// //olamundo.cpp
//   // Revisar si tiene hijos o no, igualmente si tiene un padre. Para saber que delete usar.
//   if(){

//   }
// }

int main() {
  node<char> *root = new node(4, 'A');
  insertnode(root,2, 'B');
  insertnode(root, 3, 'C');
  insertnode(root,5, 'D');
  insertnode(root,6, 'E');
  cout<<"In Order"<<endl;
  printInorder(root);
  cout << "Preorder: \n";
  printPreorder(root);
  cout << "Post Order:" <<endl;
  printPostorder(root);
  cout<<"Level Print: "<<endl;
  printLevel(root);
  cout<<endl;
  cout<<search(root, 4)->data<<endl;

}
