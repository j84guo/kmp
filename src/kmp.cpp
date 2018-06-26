#include "kmp.h"

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

void search(const char* T, int n, int* A, char* p, int m){
  int s=0;

  while(s < n - m + 1){
    int width = match(s, T, n, p, m);

    if(width == m){
      cout << T << endl;
      ++s;
    }else if(A[width] <= 0){ // zero width or no border
      ++s;
    }else{
      s += m - A[width];
    }
  }
}

int match(int s, const char* T, int n, char* p, int m){
  for(int i=0; i<m; ++i){
    if(s + i >= n || p[i] != T[s + i]){
      return i;
    }
  }
  return m;
}
