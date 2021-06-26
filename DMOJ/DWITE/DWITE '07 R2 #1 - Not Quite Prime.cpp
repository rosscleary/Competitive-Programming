#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

bool prime_check(int x) {

for (int i=2; i<=sqrt(x); i++) {
  if (x%i==0) {
    return false;
  }
}

return true;

}

int main () {

int n;

bool semiprime=false;

for (int i=1; i<=5; i++) {
  cin>>n;
  for (int ii=2; ii<=sqrt(n); ii++) {
    if (n%ii==0) {
      if (prime_check(ii)==true && prime_check(n/ii)==true) {
        semiprime=true;
        break;
      }
    }
  }
  if (semiprime) {
    cout<<"semiprime"<<endl;
  }
  else {
    cout<<"not"<<endl;
  }
}

return 0;

}