#include <iostream>
using namespace std;

template <class T>
class TreeNode{
  public:
    TreeNode();
    TreeNode(T k);
    ~TreeNode();
    void print();

    T key;
    TreeNode *left;
    TreeNode *right;
};
template <class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
  left = NULL;
  right = NULL;
  key = k;
}
template <class T>
TreeNode<T>::~TreeNode(){
  if(left != NULL){
    prev = NULL;
  }
  if(right != NULL){
    next = NULL;
  }
}
template <class T>
void TreeNode<T>::print(){
  cout << key.print() << endl;
}


//BST
template <class T>
class BST{
  private:
    TreeNode<T> *root;
    int size;
    string entry;

  public:
    BST();
    ~BST();

    void insertNode(T value);
    bool searchNode(int value);
    T retrieveNode(int value);
    bool removeNode(T k);

    TreeNode<T>* getSuccessor(TreeNode<T> *d);
    //for deletion method.

    bool isEmpty();
    T getMax();
    T getMin();

    string recPrint(TreeNode<T> *node);
    string printTree();
};

template <class T>
BST<T>::BST(){
  root = NULL;
  size  = 0;
}

template <class T>
BST<T>::~BST(){
  //iterate and delete, this is O(n)
}

template <class T>
string BST<T>::recPrint(TreeNode<T> *node){
  string output;
  if(node != NULL){
    output += recPrint(node->left);
    output += node->key.print() + "\n";
    output += recPrint(node->right);
  }
  return output;

}

template <class T>
string BST<T>::printTree(){
  return recPrint(root);
}

template <class T>
bool BST<T>::isEmpty(){
  return(root == NULL);
}

template <class T>
T BST<T>::getMax(){
  if(isEmpty()){
    return NULL;
  }

  TreeNode<T> *current = root;
  while(current->right != NULL){
    current = current->right;
  }

  return current->key;
}
template <class T>
void BST<T>::insertNode(T value){
  TreeNode<T> *node = new TreeNode<T>(value);


  if(isEmpty()){
    //cout << "Is root" << endl;
    root = node;
  }else{
    //cout << "Is not root" << endl;
    TreeNode<T> *parent = NULL;
    TreeNode<T> *current = root;
    //current->print();
    //cout << current << endl;
    //cout << "Starting Loop" << endl;
    while(true){
      parent = current;

      if(value < current->key){
        //cout << "less tahn" << endl;
        //Left
        current = current->left;
        //cout <<"left" << endl;
        if(current == NULL){
          //node->print();
          //we found our location/insertion point
          //cout << "Found Spot" << endl;
          parent->left = node;
          break;
        }
        //cout << "Not NULL" << endl;
      }
      else {
        //Right
        //cout << "Right" << endl;
        current = current->right;
        if(current == NULL){
          //we found our location/insertion point
          //cout << "Found Spot" << endl;
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::searchNode(int value){
    TreeNode<T> *current = root;
    //cout << "Intake: " << value << endl;
    while(current->key.getID() != value){
      if(value < current->key.getID()){
        current = current->left;
      }else{
        current = current->right;
      }

      if(current == NULL){
        return false;
      }
    }
    return true;
  }

template <class T>
T BST<T>::retrieveNode(int value){
  //cout << "retreieving node" << endl;
  TreeNode<T> *current = root;
  while(current->key.getID() != value){
    //cout << current->key.getID() << endl;
    if(value < current->key.getID()){
      current = current->left;
    }else{
      current = current->right;
    }
  }
  return current->key;
}
template <class T>
bool BST<T>::removeNode(T k){
  if(isEmpty()){
    return false;
  }
  size--;
  TreeNode<T> *parent = root;
  TreeNode<T> *current = root;
  bool isLeftNode = true;

  while(current->key != k){
    parent = current;
    if(k < current->key){
      //go left
      isLeftNode = true;
      current = current->left;
    }else{
      //go right
      isLeftNode = false;
      current = current->right;
    }

    if(current == NULL){
      return false;
    }

    //case: leaf node
    if(current->left == NULL && current->right == NULL){
      if(current = root){
        //removing root
        root = NULL;
      }else if(isLeftNode){
        //lfet child
        parent->left = NULL;
      }else{
        //right child
        parent->right = NULL;
      }
    }

    //node has one child
    else if(current->right == NULL){
      //has a left child
      if(current == root){
        //if its the root - the one child becomes root
        root = current->left;
      }else if(isLeftNode){
        //has a parent on left
        parent->left = current->left;
      }else{
        //has parent on right
        parent->right = current->left;
      }
    }

    else if(current->left == NULL){
      //has a right child
      if(current == root){
        root = current->right;
      }else if(isLeftNode){
        parent->left = current->right;
      }else{
        parent->right = current->right;
      }
    }
    else{
      //node ot be deleted has 2 children
      TreeNode<T> *successor = getSuccessor(current);

      if(current == root){
        root = successor;
      }else if(isLeftNode){
        parent->left = successor;
      }else{
        parent->right = successor;
      }

      successor->left = current->left;
    }
    //delete (garbage collect) in this function or something special in destructor?
    //delete current;
    return true;
  }
}
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;
  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }
  //Once exit while loop - pointers should be in  correct poositions
  //Check whether or not succ is descendent of right child
  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}
