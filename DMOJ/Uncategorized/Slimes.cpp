#include <iostream>
#include <algorithm>
using namespace std;
int main () {

int n;
cin>>n;

long long slimes[401];

for (int i=1; i<=n; i++) {
  cin>>slimes[i];
}

long long prefix_sums[401];

prefix_sums[0]=0;
prefix_sums[1]=slimes[1];

for (int i=2; i<=n; i++) {
  prefix_sums[i]=prefix_sums[i-1]+slimes[i];
}

long long dp[401][401];

for (int left=n; left>=1; left--) {
  for (int right=left; right<=n; right++) {
    if (left==right) {
      dp[left][right]=0;
    }
    else {
      dp[left][right]=1000000000000000000;
      for (int divide=left; divide<right; divide++) {
        dp[left][right]=min(dp[left][right],dp[left][divide]+dp[divide+1][right]+prefix_sums[right]-prefix_sums[left-1]);
      }
    }
  }
}

cout<<dp[1][n]<<endl;

return 0;

}