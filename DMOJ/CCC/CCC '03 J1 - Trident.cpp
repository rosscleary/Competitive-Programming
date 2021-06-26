#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;
int main () {

int t,s,h;
cin>>t>>s>>h;

for (int i=1; i<=t; i++) {
  cout<<"*";
  for (int ii=1; ii<=s; ii++) {
    cout<<" ";
  }
  cout<<"*";
  for (int ii=1; ii<=s; ii++) {
    cout<<" ";
  }
  cout<<"*"<<endl;
}

for (int i=1; i<=(2*s)+3; i++) {
  cout<<"*";
}

cout<<endl;

for (int i=1; i<=h; i++) {
  for (int ii=1; ii<=(((2*s)+3)-1)/2; ii++) {
    cout<<" ";
  }
  cout<<"*"<<endl;
}

return 0;

}