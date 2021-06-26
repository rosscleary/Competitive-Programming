#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int main () {
  int n;
  cin>>n;
  for (int test_case=1; test_case<=n; test_case++) {
    string s;
    cin>>s;
    int to_close_counter=0;
    bool valid=true;
    for (int i=0; i<=s.length()-1; i++) {
      if (s[i]=='(') {
        to_close_counter++;
      }
      else {
        if (s[i]==')') {
          to_close_counter--;
        }
      }
      if (to_close_counter<0) {
        valid=false;
        break;
      }
    }
    if (to_close_counter==0 && valid) {
      cout<<"YES"<<endl;
    }
    else {
      cout<<"NO"<<endl;
    }
  }
}