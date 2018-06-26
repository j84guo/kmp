#include <iostream>

using std::cout;
using std::endl;

void build_prefix_table(int *A, char* p, int m);

void search(char* T, int n, int* A, char* p, int m);

int match(int s, char* T, int n, char* p, int m);

template <typename T>
void print_array(T* A, int m);

int main(){
  char p[] = "sh";
  int m = sizeof(p) - 1;
  int A[m];

  build_prefix_table(A, p, m);

  cout << p << endl;
  print_array<int>(A, m);

  char T[] = "she sells sea shells by the sea shore";
  search(T, sizeof(T) - 1, A, p, m);
}

/*
* pattern and prefix table have length m
* index i is the border length of the length i subpattern (0 to m-1)
*/
void build_prefix_table(int *A, char* p, int m){
  int i = 0;
  int j = -1;

  A[i] = j; // zero length subpattern

  while(i < m-1){ // m - 1 iterations
    while(j >= 0 && p[i] != p[j]){ // border of a border
      j = A[j];
    }

    ++i;
    ++j;
    A[i] = j;
  }
}

/*
* find all occurences of p in T
*/
void search(char* T, int n, int* A, char* p, int m){
  int s=0;

  while(s < n - m + 1){
    int width = match(s, T, n, p, m);

    if(width == m){
      cout << "match at " << s << endl;
      ++s;
    }else if(A[width] <= 0){ // zero width or no border
      ++s;
    }else{
      s += m - A[width];
    }
  }
}

/*
* returns the width of the match
*/
int match(int s, char* T, int n, char* p, int m){
  for(int i=0; i<m; ++i){
    if(s + i >= n || p[i] != T[s + i]){
      return i;
    }
  }
  return m;
}

/*
* print an array of printable objects
*/
template <typename T>
void print_array(T* A, int m){
  for(int i=0; i<m; ++i){
    cout << A[i] << " ";
  }
  cout << endl;
}
