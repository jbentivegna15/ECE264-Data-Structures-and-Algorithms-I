// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, SPRING 2017

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds one string
class Data {
public:
  string data;
  Data(const string &s) { data = s; }
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l) {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;

  ifstream input(filename.c_str());
  if (!input) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    string line;
    getline(input, line);
    l.push_back(new Data(line));
  }

  input.close();
}

// Output the data to a specified input file
void writeDataList(const list<Data *> &l) {
  string filename;
  cout << "Enter name of output file: ";
  cin >> filename;

  ofstream output(filename.c_str());
  if (!output){
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << endl;

  // Write the data
  for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++) {
    output << (*ipD)->data << endl;
  }

  output.close();
}

void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  list<Data *> theList;
  loadDataList(theList);

  cout << "Data loaded.  Executing sort..." << endl;

  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds." << endl;

  writeDataList(theList);
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

int currentTest(list<Data *> &l);
void sort12(list<Data *> &l);
void sort3(list<Data *> &l);
void sort4(list<Data *> &l);

int size = 0;
char const* num;
list<Data *> sortedList;
Data * arrayNum[1010000];
char ncount[1010000];

void sortDataList(list<Data *> &l) {

  size = l.size();

  switch(currentTest(l)){
    case 1:
      sort12(l);
      break;
    case 2:
      sort12(l);
      break;
    case 3:
      sort3(l);
      break;
    case 4:
      sort4(l);
      break;
   }
}

int currentTest(list<Data *> &l){

  string first = (*l.begin())->data;
  list<Data *>::iterator iterator = l.begin();
  string second = (*iterator)->data;2
  string third = (*(++iterator))->data;

  if (size < 200000){

    return 1;
  }
  else if (first.length() <= 7 ){
    return 3;
  }
  else if (stof(second.substr(0,10)) == stof(third.substr(0,10))) {
    return 4;
  }
  else {
    return 2;
  }
}

bool compare12(const Data * a, const Data * b){
  int harambe = 0;
  int pepe =0;
    while (((a)->data)[harambe] != '.') {
      harambe++;
    }
    while (((b)->data)[pepe] != '.') {
      pepe++;
    }
  if(pepe!=harambe){
    return harambe<pepe;
  }
  else{
    return ((a)->data) < ((b)->data);
  }
}

void sort12(list<Data *> &l){
  l.sort(compare12);
}

void sort3(list<Data *> &l){
  int theInt = 0;
  list<Data *>::iterator iterat1 = l.begin();
  list<Data *>::iterator iterat2 = l.end();
  for (iterat1 = l.begin(); iterat1 != iterat2; iterat1++) {
    theInt = round((1000*atof(((*iterat1)->data).c_str())));
    arrayNum[theInt] = *iterat1;
    ncount[theInt]++;
  }

  iterat1 = l.begin();
  int i = 0;
  while (iterat1 != iterat2) {
    while (ncount[i]--) {
      *(iterat1++) = arrayNum[i];
    }
    i++;
  }
}

void sort4(list<Data *> &l){
  for (list<Data *>::iterator iterat = l.begin()++; iterat != l.end(); iterat++) {
    list<Data *>::iterator tempit = iterat;
    list<Data *>::iterator tempit2 = tempit;
    tempit2--;
    for(tempit = iterat; tempit != l.begin() && (**tempit).data < (**tempit2).data; tempit--, tempit2--){
      iter_swap(tempit,tempit2);
    }
  }
}
