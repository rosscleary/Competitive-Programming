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
using namespace std;

int main () {

  string str;
  cin>>str;
  if (str.length()==1) {
    cout<<"YES"<<endl;
    return 0;
  }
  for (int i=0; i<str.length()-2; i++) {
    if (str[i]=='C' && str[i+1]=='C' && str[i+2]=='C') {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;

  return 0;

}