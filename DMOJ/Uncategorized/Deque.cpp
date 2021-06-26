#include <iostream>
using namespace std;
int main () {

int n;

cin>>n;

long long int picks[301];

for (int i=1; i<=n; i++) {
  cin>>picks[i];
}

long long int dp[3001][3001];

for (int left=n; left>=1; left--) {
  for (int right=left; right<=n; right++) {
    if (left==right) {
      dp[left][right]=picks[left];
    }
    else {
        dp[left][right]=max(picks[left]-dp[left+1][right],picks[right]-dp[left][right-1]);
    }
  }
}

cout<<dp[1][n]<<endl;

return 0;

}