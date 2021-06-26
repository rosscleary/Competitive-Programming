#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int main () {
  long long n;
  scanf("%lld",&n);
  int a,b;
  scanf("%d",&b);
  scanf("%d",&a);
  long long k_value;
  long long h_value;
  if (b!=0) {
    h_value=(n+(-1*(a/b)))/2;
    k_value=(n-h_value)*(a+(b*h_value));
  }
  else {
    k_value=n*a;
  }
  printf("%lld",k_value);
}