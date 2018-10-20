#ifndef KMP_H
#define KMP_H

#include <iostream>

using std::cout;
using std::endl;

/*
* pattern and prefix table have length m
* index i is the border length of the length i subpattern (0 to m-1)
*/
void build_prefix_table(int* A, char* p, int m);

/*
* find all occurences of p in T
*/
void search(const char* T, int n, int* A, char* p, int m);

/*
* returns the width of the match
*/
int match(int s, const char* T, int n, char* p, int m);

/*
* print an array of printable objects
*/
template <typename T>
void print_array(T* A, int m)
{
    for (int i = 0; i < m; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

#endif
