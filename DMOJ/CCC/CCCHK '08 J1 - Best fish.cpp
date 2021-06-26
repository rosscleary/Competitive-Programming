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

int c;
cin>>c;
int c_best=0;

int weight,length;

for (int i=1; i<=c; i++) {
  cin>>weight>>length;
  if ((weight*length)>c_best) {
    c_best=weight*length;
  }
}

int n;
cin>>n;
int n_best=0;

for (int i=1; i<=n; i++) {
  cin>>weight>>length;
  if ((weight*length)>n_best) {
    n_best=weight*length;
  }
}

if (c_best>n_best) {
  cout<<"Casper"<<endl;
}
else {
  if (n_best>c_best) {
    cout<<"Natalie"<<endl;
  }
  else {
    cout<<"Tie"<<endl;
  }
}

return 0;

}