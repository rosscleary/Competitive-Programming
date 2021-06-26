#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool prime_check(int x) {

if (x==1)
  return false;

for (int i=2; i<=sqrt(x); i++) {

if (x%i==0) {
  return false;
  break;
}

}

return true;

}

int digits_sum(int x) {

if (x<10)
  return x;

return x%10+digits_sum(x/10);

}



int main () {

int n;

cin>>n;

int good_counter=0;

for (int case_=1; case_<=n; case_++) {

int number;

cin>>number;

if (prime_check(digits_sum(number))==true && prime_check(number)==true)
  good_counter=good_counter+1;

}

cout<<good_counter<<endl;

return 0;

}