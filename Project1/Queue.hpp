#include <iostream>
#include <fstream>
#include <string>

//Queue class inhereting public function from SimpleList
template <typename T>
class Queue : public SimpleList<T>{
public:
  //Queue constructor inherets from SimpleList constructor
  Queue(string n) : SimpleList<T>(n){};
  void push(T data);
  T pop();
};

//Implementation of the push function for the Queue class
template <typename T>
void Queue<T> :: push(T data){

  this->insertEnd(data);

}

//Implementation of the pop function for the Queue class
template <typename T>
T Queue<T> :: pop(){

  return this->removeStart();

}
