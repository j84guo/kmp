#include <iostream>

using std::cout;
using std::endl;

/*
* assumes strings are null terminated
*/
bool match_here(char* T, int start, char* P){

  for(int i=0; P[i] != '\0'; ++i){
    if(T[start + i] == '\0' || T[start + i] != P[i]){
      return false;
    }
  }

  return true;
}

/*
* assumes T is longer than P
*/
int naive_search(char* T, char* P){

  for(int i=0; T[i] != '\0'; ++i){
    if(match_here(T, i, P)){
      return i;
    }
  }

  return -1;
}

int main(){

  char a[] = "jackson";
  char b[] = "on";

  int x = naive_search(a, b);
  cout << x << endl;

}
