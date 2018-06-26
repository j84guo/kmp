#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#include <iostream>

using std::cout;
using std::endl;

int is_file(const char* path){
  struct stat path_info;
  stat(path, &path_info);
  return S_ISREG(path_info.st_mode);
}

int main(){

  // current directory
  char cwd[1024];
  getcwd(cwd, sizeof cwd);
  cout << cwd << endl;

  // check if path is a directory
  DIR *dir = opendir("/Users/jguo/Projects"); // DIR is a directory stream typedef

  if(dir != nullptr){
    cout << "directory exists" << endl;
  }else if(errno == ENOENT){
    cout << "directory does not exist" << endl;
    return 0;
  }else{
    cout << "other directory error" << endl;
    return 0;
  }

  // check if path is a file
  cout << is_file("a.out") << endl;

  // read directory
  struct dirent* ent;
  while((ent = readdir(dir))){ // while a null pointer is not returned
    cout << ent->d_name << " ";
  }

  // close directory
  closedir(dir);
}
