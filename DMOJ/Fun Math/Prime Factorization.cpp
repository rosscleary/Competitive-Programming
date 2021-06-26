#include <iostream>
#include <cmath>
using namespace std;

bool prime_check(int x) {

for (int i=2; i<=sqrt(x); i++) {
if (x%i==0)
  return false;
}

return true;

}

void prime_factors(int n) {

if (prime_check(n)==true)
cout<<n<<" ";

for (int i=2; i<=sqrt(n); i++) {

if (n%i==0) {
  prime_factors(i);
  prime_factors(n/i);
  break;
}

}

}

int main () {

int t;

cin>>t;

for (int i=1; i<=t; i++) {

int n;

cin>>n;

prime_factors(n);

cout<<endl;

}

return 0;

}