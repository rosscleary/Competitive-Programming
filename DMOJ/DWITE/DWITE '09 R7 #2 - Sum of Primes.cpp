#include <iostream>
#include <cmath>
using namespace std;

bool prime_check(int x) {

if (x%2!=0) {

for (int i=3; i<=sqrt(x); i+=2) {

if (x%i==0) {
  return false;
  break;
}

}

}

else
return false;

return true;

}

int main () {

int sum_of_primes[100001];

sum_of_primes[2]=2;

for (int i=3; i<=100000; i++) {

if (prime_check(i))
  sum_of_primes[i]=sum_of_primes[i-1]+i;
else
  sum_of_primes[i]=sum_of_primes[i-1];

}

int number;

for (int i=1; i<=5; i++) {
cin>>number;
cout<<sum_of_primes[number]<<endl;
}

return 0;

}