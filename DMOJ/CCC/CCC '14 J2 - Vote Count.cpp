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
  int v;
  string votes;
  cin>>v;
  cin>>votes;
  
  int a_counter=0;
  int b_counter=0;
  for (int i=0; i<=v-1; i++) {
    if (votes[i]=='A') {
      a_counter++;
    }
    else {
      b_counter++;
    }
  }

  if (a_counter>b_counter) {
    cout<<"A"<<endl;
  }
  else {
    if (b_counter>a_counter) {
      cout<<"B"<<endl;
    }
    else {
      cout<<"Tie"<<endl;
    }
  }
}