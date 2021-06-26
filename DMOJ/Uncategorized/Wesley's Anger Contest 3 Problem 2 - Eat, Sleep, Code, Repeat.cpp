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
#define ll long long
using namespace std;

int main () {

  int D;
  scanf("%d",&D);
  while (D--) {

    ll H;
    scanf("%lld",&H);
    ll answer;
    if (H%3==0) {
      answer=(H/3)*(H/3)*(H/3);
    }
    else {
      if (H%3==1) {
        answer=(H/3)*(H/3)*(H/3+1);
      }
      else {
        answer=(H/3)*(H/3+1)*(H/3+1);
      }
    }

    printf("%lld\n",answer);

  }

  return 0;

}