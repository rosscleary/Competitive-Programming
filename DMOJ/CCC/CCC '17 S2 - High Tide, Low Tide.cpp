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
  int n;
  scanf("%d",&n);
  int measurements[100];
  for (int i=0; i<n; i++) {
    scanf("%d",&measurements[i]);
  }
  sort(measurements,measurements+n);
  int lows;
  int highs;
  if (n%2==0) {
    lows=n/2-1;
    highs=n/2;
  }
  else {
    lows=n/2;
    highs=n/2+1;
  }
  while (lows>=0 && highs<=n-1) {
    printf("%d ",measurements[lows]);
    printf("%d ",measurements[highs]);
    lows--;
    highs++;
  }
  if (n%2==1) {
    printf("%d ",measurements[0]);
  }
}