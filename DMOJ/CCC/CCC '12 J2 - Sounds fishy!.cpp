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

  int d_1,d_2,d_3,d_4;
  scanf("%d%d%d%d",&d_1,&d_2,&d_3,&d_4);

  if (d_1<d_2 && d_2<d_3 && d_3<d_4) {
    printf("Fish Rising\n");
  }
  else {
    if (d_1>d_2 && d_2>d_3 && d_3>d_4) {
      printf("Fish Diving\n");
    }
    else {
      if (d_1==d_2 && d_2==d_3 && d_3==d_4) {
        printf("Fish At Constant Depth\n");
      }
      else {
        printf("No Fish\n");
      }
    }
  }

  return 0;

}