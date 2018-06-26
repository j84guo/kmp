#include <iostream>

using namespace std;

int main(){
  // returns the size
  int* X = new int[10];

  // sizeof a pointer is 8 bytes on a 64 bit machine
  cout << sizeof X << endl;

  // compilers store the number of elements of each dynamically allocated array
  delete[] X;
}
