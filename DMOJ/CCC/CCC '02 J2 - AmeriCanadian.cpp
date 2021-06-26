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
#define ll long long
using namespace std;

bool not_vowel (char);

int main () {

  while (1) {

    string str;
    cin>>str;
    if (str=="quit!") {
      break;
    }

    int str_length=str.length();
    if (str_length<4) {
      cout<<str<<endl;
      continue;
    }

    if (str[str_length-2]=='o' && str[str_length-1]=='r' && not_vowel(str[str_length-3])) {
      string new_str;
      new_str=str.substr(0,str_length-2);
      new_str+='o';
      new_str+='u';
      new_str+='r';
      cout<<new_str<<endl;
    }
    else {
      cout<<str<<endl;
    }

  }

  return 0;

}

bool not_vowel (char c) {

  if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y') {
    return false;
  }

  return true;

}