#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <climits>
using namespace std;

int n;

bool valid(int);
bool is_prime(int);

int main () {

  int t=5;
  while (t--) {
    cin>>n;
    if (valid(n)) {
      cout<<"valid"<<endl;
    }
    else {
      cout<<"not"<<endl;
    }
  }

  return 0;

}

bool is_prime(int number) {

  if (number==2) {
    return true;
  }
  
  if (number%2==0) {
    return false;
  }

  for (int i=3; i<=sqrt(number); i+=2) {
    if (number%i==0) {
      return false;
    }
  }

  return true;

}

bool valid(int number) {

  int prime_factor_counter=0;
  for (int i=2; i<=number/2; i++) {
    if (number%i==0 && is_prime(i)) {
      prime_factor_counter++;
    }
  }

  if (prime_factor_counter==3) {
    return true;
  }
  return false;

}