#include <iostream>

using std::cout;
using std::endl;

int main(){

  // 8 bytes due to null terminator
  char a[] = "jackson";
  cout << sizeof a << endl;

  // 3 bytes, compiler doesn't add null terminator for brace initialization
  char b[] = {'j', 'v', 'm'};
  cout << sizeof b << endl;

  // comparing char, which is an 8 bit numeric type
  cout << (a[0] == b[0]) << endl;

}
