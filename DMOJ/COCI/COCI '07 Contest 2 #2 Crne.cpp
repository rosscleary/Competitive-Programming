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

int main () {

  int n;
  cin>>n;

  if (n==1) {
    cout<<"2"<<endl;
    return 0;
  }
  if (n==2) {
    cout<<"4"<<endl;
    return 0;
  }
  if (n==3) {
    cout<<"6"<<endl;
    return 0;
  }

  int num_pieces=4;
  int to_cut=2;
  for (int i=3; i<=n; i++) {
    num_pieces+=to_cut;
    if (i%2==1) {
      to_cut++;
    }
  }

  cout<<num_pieces<<endl;

  return 0;

}