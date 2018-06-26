#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <cstring>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>

#include "kmp.h"

#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

using std::size_t;
using std::strcat;
using std::strcmp;
using std::strcpy;

/*
* directory depth first search
*/
void traverse_dir(char* path, char* pattern);

/*
* search a file
*/
void search_file(char* file, char* pattern);

/*
* dst must be large enough to hold p1 and p2
*/
void join_path(char* dst, char* p1, char* p2);

/*
* checks the string's first character
*/
bool starts_with(char* s, char c);

/*
* checks the string's last character
*/
bool ends_with(char* s, char c);

/*
* path to file or directory
*/
bool is_dir(char* path);

#endif
