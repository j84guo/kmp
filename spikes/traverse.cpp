/*
* todo :
* strcat(), strcpy()
*/

#include <cstring>
#include <cstddef>
#include <iostream>

#include <errno.h>
#include <dirent.h>
#include <unistd.h>

using std::cout;
using std::endl;
using std::size_t;
using std::strcat;
using std::strcmp;
using std::strcpy;

void traverse_dir(char* path);
void join_path(char* dst, char* p1, char* p2);
bool starts_with(char* s, char c);
bool ends_with(char* s, char c);

int main(int argc, char** argv){
  if(argc != 2){
    cout << "usage: ./a.out <path>" << endl;
    return 0;
  }

  char* path = argv[1];
  traverse_dir(path);
}

/*
* directory depth first search
*/
void traverse_dir(char* path){
  DIR* dir;
  struct dirent* ent;

  if((dir = opendir(path)) == nullptr){
    return;
  }

  while((ent = readdir(dir)) != nullptr){
    // todo : some filesystems don't support d_type, so handle DT_UNKOWN
    if(ent->d_type == DT_DIR){
      if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0){
        continue;
      }

      char next[1024];
      join_path(next, path, ent->d_name);

      traverse_dir(next);
    }else{
      cout << ent->d_name << endl;
    }
  }

  closedir(dir);
}

/*
* dst must be large enough to hold p1 and p2
*/
void join_path(char* dst, char* p1, char* p2){
  size_t l1 = strlen(p1);
  size_t l2 = strlen(p2);

  strcpy(dst, p1);

  if(!ends_with(p1, '/')){
    strncat(dst, "/", 1);
  }

  if(starts_with(p2, '/')){
    strncat(dst, p2 + 1, l2 - 1);
  }else{
    strncat(dst, p2, l2);
  }
}

/*
* checks the string's first character
*/
bool starts_with(char* s, char c){
  size_t n = strlen(s);

  if(n == 0){
    return false;
  }

  return s[0] == c;
}

/*
* checks the string's last character
*/
bool ends_with(char* s, char c){
  size_t n = strlen(s);

  if(n == 0){
    return false;
  }

  return s[n-1] == c;
}
