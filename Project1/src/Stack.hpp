#include <iostream>
#include <fstream>
#include <string>

//Stack class inhereting public function from SimpleList
template <typename T>
class Stack : public SimpleList<T>{
public:
  //Stack constructor inherets from SimpleList constructor
  Stack(string n) : SimpleList<T>(n){};
  void push(T data);
  T pop();
};

//Implementation of the push function for the Stack class
template <typename T>
void Stack<T> :: push(T data){

  this->insertStart(data);

}

//Implementation of the pop function for the Stack class
template <typename T>
T Stack<T> :: pop(){

  return this->removeStart();

}
