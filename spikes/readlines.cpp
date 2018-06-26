#include <string>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

void printFile(char* file);

int main(int argc, char** argv){

  if(argc != 2){
    cout << "usage: ./a.out <file>" << endl;
    return 0;
  }

  printFile(argv[1]);

  return 0;
}

void printFile(char* file){
  string line;
  ifstream inFile(file);

  while(getline(inFile, line)){
    cout << line << endl;
  }
}
