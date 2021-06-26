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

int h;
cin>>h;

for (int i=1; i<=h/2; i++) {
  for (int ii=1; ii<=(2*i)-1; ii++) {
    cout<<"*";
  }
  for (int ii=1; ii<=(2*h)-((4*i)-2); ii++) {
    cout<<" ";
  }
  for (int ii=1; ii<=(2*i)-1; ii++) {
    cout<<"*";
  }
  cout<<endl;
}

for (int i=1; i<=2*h; i++) {
  cout<<"*";
}

cout<<endl;

for (int i=h/2; i>=1; i--) {
  for (int ii=1; ii<=(2*i)-1; ii++) {
    cout<<"*";
  }
  for (int ii=1; ii<=(2*h)-((4*i)-2); ii++) {
    cout<<" ";
  }
  for (int ii=1; ii<=(2*i)-1; ii++) {
    cout<<"*";
  }
  cout<<endl;
}

return 0;

}