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

int n;
cin>>n;

char occupied;

int occ_freq[101]={0};

for (int i=1; i<=n; i++) {
  cin>>occupied;
  if (occupied=='C') {
    occ_freq[i]+=1;
  }
}

for (int i=1; i<=n; i++) {
  cin>>occupied;
  if (occupied=='C') {
    occ_freq[i]+=1;
  }
}

int both_counter=0;

for (int i=1; i<=n; i++) {
  if (occ_freq[i]==2) {
    both_counter++;
  }
}

cout<<both_counter<<endl;

return 0;

}