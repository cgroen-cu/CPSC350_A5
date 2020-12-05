#include <iostream>
using namespace std;

template <class T>
class ListNode{
  public:
    T data;
    ListNode *next;
    ListNode *prev;

    ListNode();
    ListNode(T d);
    ~ListNode();
};
//ListNodeImplementation
template <class T>
ListNode<T>::ListNode(){}
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}
template <class T>
ListNode<T>::~ListNode(){
  if(prev != NULL){
    prev = NULL;
  }
  if(next != NULL){
    next = NULL;
  }
}

//LIST

template <class T>
class DoublyLinkedList{
  private:
    ListNode<T>* front;
    ListNode<T>* back;
    unsigned int size;

  public:
    DoublyLinkedList(){
      front = NULL;
      back = NULL;
      size = 0;
    }

    ~DoublyLinkedList(){}

    bool isEmpty(){
      return(size == 0);
    }

    unsigned int getSize(){
      return size;
    }

    void insertFront(T data){
      ListNode<T>* node = new ListNode<T>(data);
      if(size == 0){
        back = node;
      }
      else {
        front->prev = node;
      }
      node->next = front;
      front = node;
      ++size;
    }

    //insert node at the back of the list
    void insertBack(T data){
      ListNode<T> *node = new ListNode<T>(data);
      //cout << "insert back" << endl;
      if(front != NULL){
        back->next = node;
        node->prev = back;
      }else{
      //  cout << "empty" << endl;
        front = node;
      }
      back = node;
      ++size;
    }

    //remove node at the front of the list
    T removeFront(){
      ListNode<T>* nodeToDelete = front;
      if(front->next == NULL){
        back = NULL;
      }
      else {
        front->next->prev = NULL;
      }
      front = front->next;
      nodeToDelete->next = NULL;
      T temp = nodeToDelete->data;
      size--;
      delete nodeToDelete;
      return temp;
    }

    //remove node a the back of list
    T removeBack(){
      ListNode<T> *nodeToDelete = back;
      T temp;
      if(!isEmpty()){
        temp = back->data;
        back = back->prev;
        back->next = NULL;
        nodeToDelete->prev = NULL;
      }
      else{
        cout << "list is empty" << endl;
        return -1;
      }
      delete nodeToDelete;
      return temp;
    }

    //print the list
    void printList(){
      ListNode<T> *curr = front;
      while(curr!= NULL){
        cout << curr->data;
        curr = curr->next;
      }
      cout << endl;
    }

    //return the position of a value in the list - -1 means does not exist
    int find(T val){
      int pos = -1;
      ListNode<T> *curr = front;
      while(curr != NULL){
        ++pos;
        if(curr->data == val){
          break;
        }
        curr = curr->next;
      }
      if(curr == NULL){
        pos = -1;
      }
      return pos;
    }

    //delete node at a certain position in the list
    T deletePos(int pos){
      int p = 0;
      ListNode<T>* curr = front;
      ListNode<T>* prev = front;

      while(p != pos){
        prev = curr;
        curr = curr->next;
        p++;
      }
      // cout << "p = " << p << endl;
      if(p == 0){
        removeFront();
      }else{
        prev->next = curr->next;
        curr->next = NULL;
        T temp = curr->data;

        size--;
        delete curr;
        return temp;
      }
    }
    T returnPos(int pos){
      int p = 0;
      ListNode<T>* curr = front;
      ListNode<T>* prev = front;

      while(p != pos){
        prev = curr;
        curr = curr->next;
        p++;
      }
      T temp = curr->data;
      return temp;
    }

    T removeNode(T key){
      ListNode<T>* curr = front;
      while(curr->data != key){
        curr = curr->next;
        if(curr == NULL){
          return -1;
        }
      }
      if(curr == front){
        front = curr->next;
        front->prev = NULL;
      }
      else if(curr == back){
        back = curr->prev;
        back->next = NULL;
      }
      else {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
      }
      curr->next = NULL;
      curr->prev = NULL;
      T temp = curr->data;
      size--;
      delete curr;
      return temp;
    }
};
