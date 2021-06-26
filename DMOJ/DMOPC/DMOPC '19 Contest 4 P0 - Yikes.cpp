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
  string a,b;
  cin>>a>>b;
  int dif_counter=0;
  for (int i=0; i<=a.length()-1; i++) {
    if (a[i]!=b[i]) {
      dif_counter++;
    }
  }
  if (dif_counter==1) {
    cout<<"LARRY IS SAVED!"<<endl;
  }
  else {
    cout<<"LARRY IS DEAD!"<<endl;
  }
}