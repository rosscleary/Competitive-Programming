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

  int N,M;
  scanf("%d%d",&N,&M);
  char grid[1000][1000];
  int top=INT_MAX,bottom=INT_MIN,left=INT_MAX,right=INT_MIN;
  char c;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cin>>c;
      grid[i][j]=c;
      if (c=='*') {
        top=min(top,i);
        bottom=max(bottom,i);
        left=min(left,j);
        right=max(right,j);
      }
    }
  }

  for (int i=top; i<=bottom; i++) {
    for (int j=left; j<=right; j++) {
      printf("%c ",grid[i][j]);
    }
    printf("\n");
  }

  return 0;

}