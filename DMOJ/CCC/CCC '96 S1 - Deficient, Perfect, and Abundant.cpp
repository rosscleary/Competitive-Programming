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

int number;

for (int i=1; i<=n; i++) {
  cin>>number;
  int divisor_sum=0;
  for (int ii=1; ii<=number-1; ii++) {
    if (number%ii==0) {
      divisor_sum+=ii;
    }
  }
  if (divisor_sum==number) {
    cout<<number<<" is a perfect number."<<endl;
  }
  else {
    if (divisor_sum<number) {
      cout<<number<<" is a deficient number."<<endl;
    }
    else {
      cout<<number<<" is an abundant number."<<endl;
    }
  }
}

return 0;

}