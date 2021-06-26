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
  string s;
  cin>>n;
  cin>>s;
  int dp[3001][3001];
  dp[1][1]=1;
  for (int prefix=2; prefix<=n; prefix++) {
    int prefix_sum[3001]={0};
    for (int second_last=1; second_last<prefix; second_last++) {
      prefix_sum[second_last]=(prefix_sum[second_last-1]+dp[prefix-1][second_last])%1000000007;
    }
    for (int last=1; last<=prefix; last++) {
      if (s[prefix-2]=='<') {
        dp[prefix][last]=prefix_sum[last-1]%1000000007;
      }
      else {
        dp[prefix][last]=(prefix_sum[prefix-1]-prefix_sum[last-1]+1000000007)%1000000007;
      }
    }
  }
  int answer=0;
  for (int overall_last=1; overall_last<=n; overall_last++) {
    answer+=dp[n][overall_last];
    answer=answer%1000000007;
  }
  cout<<answer<<endl;
}