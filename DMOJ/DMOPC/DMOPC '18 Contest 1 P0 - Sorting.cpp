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

  int top, middle, bottom;
  scanf("%d%d%d",&top,&middle,&bottom);

  if (top<=middle && middle<=bottom) {
    printf("Good job!\n");
  }
  else {
    printf("Try again!\n");
  }

  return 0;

}