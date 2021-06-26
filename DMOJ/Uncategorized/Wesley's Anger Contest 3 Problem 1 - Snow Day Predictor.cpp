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

  int T,D,P;
  scanf("%d%d%d",&T,&D,&P);

  int cond_counter=0;

  if (T<-40) {
    cond_counter++;
  }
  if (D>=15) {
    cond_counter++;
  }
  if (P>50) {
    cond_counter++;
  }

  if (cond_counter>1) {
    printf("YES\n");
  }
  else {
    printf("NO\n");
  }

  return 0;

}