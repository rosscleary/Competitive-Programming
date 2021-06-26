#include <iostream>
#include <cstdio>
using namespace std;

int main () {

  int F,R;
  scanf("%d%d",&F,&R);
  int prefix_sum[6][10001];
  for (int i=1; i<=F; i++) {
    for (int j=1,C; j<=R; j++) {
      scanf("%d",&C);
      prefix_sum[i][j]=prefix_sum[i][j-1]+C;
    }
  }

  int Q;
  scanf("%d",&Q);
  for (int i=0,a,b,c; i<Q; i++) {
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",prefix_sum[c][b]-prefix_sum[c][a-1]);
  }

  return 0;

}