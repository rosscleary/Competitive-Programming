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
  int choices_1[100001];
  int choices_2[100001];
  int choices_3[100001];
  for (int i=1; i<=n; i++) {
    scanf("%d",&choices_1[i]);
    scanf("%d",&choices_2[i]);
    scanf("%d",&choices_3[i]);   
  }
  long long dp[100001][4];
  dp[n][1]=max(choices_2[n],choices_3[n]);
  dp[n][2]=max(choices_1[n],choices_3[n]);
  dp[n][3]=max(choices_1[n],choices_2[n]);
  for (int day=n-1; day>=1; day--) {
    dp[day][1]=max(choices_2[day]+dp[day+1][2],choices_3[day]+dp[day+1][3]);
    dp[day][2]=max(choices_1[day]+dp[day+1][1],choices_3[day]+dp[day+1][3]);
    dp[day][3]=max(choices_1[day]+dp[day+1][1],choices_2[day]+dp[day+1][2]);
  }
  long long answer=max(max(dp[1][1],dp[1][2]),dp[1][3]);
  printf("%lld",answer);
}