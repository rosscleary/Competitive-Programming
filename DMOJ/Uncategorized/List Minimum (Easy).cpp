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
  int useless_number;
  for (int i=1; i<=n; i++) {
    scanf("%d",&useless_number);
  }
  for (int i=1; i<=n; i++) {
    printf("%d",i);
    if (i!=n) {
      printf(" ");
    }
  }
  printf("\n");
}