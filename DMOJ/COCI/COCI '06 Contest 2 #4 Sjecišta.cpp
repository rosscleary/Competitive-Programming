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

  int n;
  cin>>n;

  if (n==3) {
    cout<<"0"<<endl;
  }
  else {
    cout<<n*(n-1)*(n-2)*(n-3)/24<<endl;
  }

  return 0;

}