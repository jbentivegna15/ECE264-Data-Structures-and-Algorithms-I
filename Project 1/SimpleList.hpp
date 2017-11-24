#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//abstract base SimpleList class
template <typename T>
class SimpleList {
public:

  //public pure virtual function push
  virtual void push(T data) = 0;

  //public pure virtual function pop
  virtual T pop() = 0;

  //public member function getName to retrieve the list name
  string getName(){
    return listname;
  }

  //public member function getSize to keep track of the size of the list
  int getSize(){
    return size;
  }

  //SimpleList constructor
  SimpleList(string n){
    listname = n;
    //start node
    first = NULL;
    //end node
    last = NULL;
    size = 0;
  }

private:

  //private nested node class
  class node {
  public:
    T data;
    node* next; //ptr to next node
    node(T dat, node* nxt){
      data = dat;
      next = nxt;
      }
  };

  //private nameList to store the name of the list
  string listname;

  //private size to store the size of the list
  int size;

  //private pointer first to store first element of the list
  node* first;

  //private pointer last to store last element of the list
  node* last;

protected:

  //protected member function insertStart to insert a node at the start of a list
  void insertStart(T data);

  //protected member function insertEnd to insert a node at the end of a list
  void insertEnd(T data);

  //protected member function removeStart to remove a node from the start of a list
  T removeStart();

};

//implementation of insertStart member function
template <typename T>
void SimpleList<T> :: insertStart(T data){
  node * temp = new node(data, first);
  //check if the list is empty
  if (getSize() == 0) {
    last = temp;
    first = temp;
    size++;
  } else {
    first = temp;
    size++;
  }
}

//implementation of insertEnd member function
template <typename T>
void SimpleList<T> :: insertEnd(T data){
  node * temp = new node(data, NULL);
  //check if the list is empty
  if (getSize() == 0) {
    first = temp;
    last = temp;
    size++;
  } else {
    last->next = temp;
    last = temp;
    size++;
  }
}

//implementation of removeStart member function
template <typename T>
T SimpleList<T> :: removeStart(){
  node * temp = first->next;
  T data = first->data;
  delete first;
  size--;
  first = temp;
  return data;
}
