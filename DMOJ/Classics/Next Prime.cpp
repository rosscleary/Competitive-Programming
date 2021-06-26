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

int main () {

long long int n;

cin>>n;

if (n==1 || n==2)
  cout<<"2"<<endl;

else {

if (n%2==0) {

for (long long int i=n+1; i<=1000000000000; i++) {

if (prime_check(i)==true) {
  cout<<i<<endl;
  break;
}

}

}

else {

for (long long int i=n; i<=1000000000000; i++) {

if (prime_check(i)==true) {
  cout<<i<<endl;
  break;
}

}

}

}

return 0;

}