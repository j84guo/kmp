#include "filesystem.h"

void traverse_dir(char* path, char* pattern){
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

      traverse_dir(next, pattern);
    }else{

      char file[1024];
      join_path(file, path, ent->d_name);

      search_file(file, pattern);
    }
  }

  closedir(dir);
}

void search_file(char* file, char* p){
  int m = strlen(p);
  int* A = new int[m];

  build_prefix_table(A, p, m);

  string line;
  ifstream in(file);

  while(getline(in, line)){
    search(line.c_str(), line.size(), A, p, m);
  }

  delete[] A;
}

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

bool starts_with(char* s, char c){
  size_t n = strlen(s);

  if(n == 0){
    return false;
  }

  return s[0] == c;
}

bool ends_with(char* s, char c){
  size_t n = strlen(s);

  if(n == 0){
    return false;
  }

  return s[n-1] == c;
}

bool is_dir(char* path){
  struct stat path_info;

  if (stat(path, &path_info) != 0){
    return false;
  }

  return S_ISDIR(path_info.st_mode);
}
