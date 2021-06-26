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

  int size;
  while (1) {

    scanf("%d",&size);
    if (!size) {
      break;
    }

    for (int i=sqrt(size); i>0; i--) {
      if (size%i==0) {
        printf("Minimum perimeter is %d with dimensions %d x %d\n",2*i+2*(size/i),i,size/i);
        break;
      }
    }

  }

  return 0;

}