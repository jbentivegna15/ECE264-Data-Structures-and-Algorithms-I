//Joseph Bentivegna
//Data Structures and Algorithms I
//Programming Assignment 1
//Carl Sable

/*This program implements stacks and queues using singly linked lists. It is
designed in a way such that the user specifies an input text file filled will
specificly formatted commands, and the program will output a resultant text file
describing all of the operations carried out based on the commands.  The program
is largely made up of the SimpleList class that sets up a template for creating
a stack or queue.  The class contains member functions that enable commands such
as push and pop.  These functions are later implemented in the Stack and Queue
classes.  The main of the program largely deals with reading and processing
the input file, and parsing through the current collection of stacks and queues.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include "SimpleList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
using namespace std; //opens the standard namespace

list<SimpleList<int> *> listSLi;  //all integer stacks and queues
list<SimpleList<double> *> listSLd; //all double stacks and queues
list<SimpleList<string> *> listSLs; //all string stacks and queues

//the search function used to parse through the list of lists
template <typename T>
SimpleList<T> * search(list<SimpleList<T> * > & searchList, string name) {

  for (typename list<SimpleList<T> * >::iterator iterat = searchList.begin(); iterat != searchList.end(); ++iterat) {

    //the if statement checks if the current list matches the name of the list we're searching for
    if ((*iterat)->getName() == name) {
      return *iterat;
    }
  }

  return NULL;
}

//the process function processes a single line of input and prints it to the output file
void process (string w1, string w2, string w3, ofstream& file){
  if (w1 == "create") {

    //checking if the first character is i, or integer
    if (w2.substr(0,1) == "i"){

      //checking if we're attempting to creat an list that already exists
      if (search(listSLi, w2) != NULL){

        //prints to the output file
        file << "ERROR: This name already exists!\n";
      }

      else if (w3 == "queue"){

        //creating a new integer queue
        SimpleList<int> * pSLi;
        pSLi = new Queue<int>(w2);
        listSLi.push_front(pSLi);

      }

      else if (w3 == "stack"){

        //creating a new integer stack
        SimpleList<int> * pSLi;
        pSLi = new Stack<int>(w2);
        listSLi.push_front(pSLi);

      }

    }

    else if (w2.substr(0,1) == "d") {

      if (search(listSLd, w2) != NULL){

        file<< "ERROR: This name already exists!\n";

      }

      else if (w3 == "queue"){

        SimpleList<double> * pSLd;
        pSLd = new Queue<double>(w2);
        listSLd.push_front(pSLd);

      }

      else if (w3 == "stack"){

        SimpleList<double> * pSLd;
        pSLd = new Stack<double>(w2);
        listSLd.push_front(pSLd);

      }

    }

    else if (w2.substr(0,1) == "s") {

      if (search(listSLs, w2) != NULL) {

        file << "ERROR: This name already exists!\n";

      }

      else if (w3 == "queue"){

        SimpleList<string> * pSLs;
        pSLs = new Queue<string>(w2);
        listSLs.push_front(pSLs);

      }

      else if (w3 == "stack"){

        SimpleList<string> * pSLs;
        pSLs = new Stack<string>(w2);
        listSLs.push_front(pSLs);

      }

    }
  }

  else if (w1 == "push"){

    if(w2.substr(0,1) == "i"){

      if (search(listSLi, w2) == NULL) {

        file << "ERROR: This name does not exist!\n";

      }

      else {

        //pushing the integer value onto the proper stack or queue
        search(listSLi, w2)->push(stoi(w3));

      }
    }

    else if (w2.substr(0,1) == "d"){

      if (search(listSLd, w2) == NULL) {

        file << "ERROR: This name does not exist!\n";
      }

      else {

        search(listSLd, w2)->push(stod(w3));

      }
    }

    else if (w2.substr(0,1) == "s"){

      if (search(listSLs, w2) == NULL) {

        file << "ERROR: This name does not exist!\n";

      }

      else {

        search(listSLs, w2)->push(w3);

      }
    }

  }

  else if (w1 == "pop"){

    if (w2.substr(0,1) == "i"){

      //checking to see if the stack or queue exists
      if (search(listSLi, w2) == NULL) {

        file << "ERROR: This name does not exist!\n";

      }
      //checking to see if the stack or queue has any elements
      else if (search(listSLi, w2)->getSize() == 0){

        file << "ERROR: This list is empty!\n";

      }

      else {

        //popping an integer value off the stack or queue and printing it in the output file
        file << "Value popped: " << search(listSLi, w2)->pop() << "\n";

      }

    }

    else if (w2.substr(0,1) == "d"){

      if (search(listSLd, w2) == NULL) {

        file << "ERROR: This name does not exist!\n";

      }

      else if (search(listSLd, w2)->getSize() == 0){

        file << "ERROR: This list is empty!\n";

      }

      else {

        file << "Value popped: " << search(listSLd, w2)->pop() << "\n";

      }

    }

    else if (w2.substr(0,1) == "s"){

      if (search(listSLs, w2) == NULL) {

        file << "ERROR: This name does not exist!\n";

      }

      else if (search(listSLs, w2)->getSize() == 0){

        file << "ERROR: This list is empty!\n";

      }

      else {

        file << "Value popped: " << search(listSLs, w2)->pop() << "\n";

      }
    }
  }
}


int main(){
  string line;
  string fin;
  string fon;
  string word1, word2, word3; //for dividing up the input line

  cout << "Enter the name of the input file: ";
  cin >> fin; //file-input-name

  cout << "Enter the name of the output file: ";
  cin >> fon; //file-output-name

//input-file stream: allows you to read from a file
  ifstream inn (fin.c_str());

//output-file stream: allows you to write from a file
  ofstream onn (fon.c_str());

  if (inn.is_open()){

    //this while loop will read through the file line by line
    while (getline(inn,line)) {

      //istringstream divides up the input line into separate elements
      istringstream in(line);
      in >> word1 >> word2 >> word3;
      onn << "PROCESSING COMMAND: " << line << "\n";
      //sending the line into the process function
      process(word1, word2, word3, onn);
    }
  }
}
