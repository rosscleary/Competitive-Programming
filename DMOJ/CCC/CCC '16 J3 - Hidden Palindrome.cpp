#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <climits>
using namespace std;

bool is_palindrome(string);

int main () {

  string str;
  cin>>str;

  int str_length=str.length();
  for (int length=str_length; length>=2; length--) {
    for (int i=0; i<=str_length-length; i++) {
      if (is_palindrome(str.substr(i,length))) {
        cout<<length<<endl;
        return 0;
      }
    }
  }

  cout<<"1"<<endl;

  return 0;

}

bool is_palindrome(string str) {

  string reverse("");
  for (int i=str.length()-1; i>=0; i--) {
    reverse+=str[i];
  }

  if (str==reverse) {
    return true;
  }
  return false;

}