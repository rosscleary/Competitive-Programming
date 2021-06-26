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
  int num_cases;
  scanf("%d",&num_cases);
  for (int test_case=1; test_case<=num_cases; test_case++) {
    int number;
    scanf("%d",&number);
    bool factor_sums[32002]={false};
    bool factor_differences[32002]={false};
    for (int i=1; i<=sqrt(number); i++) {
      if (number%i==0) {
        factor_sums[i+(number/i)]=true;
        factor_differences[(number/i)-i]=true;
      }
    }
    bool nasty=false;
    for (int i=0; i<=number+1; i++) {
      if (factor_sums[i] && factor_differences[i]) {
        nasty=true;
        break;
      }
    }
    if (nasty) {
      printf("%d is nasty\n",number);
    }
    else {
      printf("%d is not nasty\n",number);
    }
  }
}