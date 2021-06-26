#include <iostream>
using namespace std;

int absolute_value(int x, int y) {
  if (x-y>0) {
    return x-y;
  }
  else {
    return y-x;
  }
}

int main () {

int n;
cin>>n;

int heights[100001];

for (int i=1; i<=n; i++) {
  cin>>heights[i];
}

long long dp[100001];

dp[n]=0;
dp[n-1]=absolute_value(heights[n],heights[n-1]);

for (int stone=n-2; stone>=1; stone--) {
  dp[stone]=min(dp[stone+1]+absolute_value(heights[stone+1],heights[stone]),dp[stone+2]+absolute_value(heights[stone+2],heights[stone]));
}

cout<<dp[1]<<endl;

return 0;

}