#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int main () {

int m,n;
cin>>m>>n;

int ten_counter=0;

for (int i=1; i<=m; i++) {
  for (int ii=1; ii<=n; ii++) {
    if (i+ii==10) {
      ten_counter++;
    }
  }
}

if (ten_counter==1) {
  cout<<"There is "<<ten_counter<<" way to get the sum 10."<<endl;
}
else {
  cout<<"There are "<<ten_counter<<" ways to get the sum 10."<<endl; 
}

return 0;

}