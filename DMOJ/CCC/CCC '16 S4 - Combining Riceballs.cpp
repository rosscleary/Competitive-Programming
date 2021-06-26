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

  int n;
  cin>>n;
  int prefix_sum[401]={0};
  for (int i=1,value; i<=n; i++) {
    cin>>value;
    prefix_sum[i]=prefix_sum[i-1]+value;
  }

  int max_ball=0;
  bool dp[401][401]={false};
  for (int i=1; i<=n; i++) {
    dp[i][i]=true;
    max_ball=max(max_ball,prefix_sum[i]-prefix_sum[i-1]);
  }

  for (int l=n-1; l>=1; l--) {
    for (int r=l+1; r<=n; r++) {
      for (int i=l; i<r; i++) {
        bool found=false;
        if (prefix_sum[i]-prefix_sum[l-1]==prefix_sum[r]-prefix_sum[i] && dp[l][i] && dp[i+1][r]) {
          dp[l][r]=true;
          break;
        }
        for (int j=i+2; j<=r; j++) {
          if (prefix_sum[i]-prefix_sum[l-1]==prefix_sum[r]-prefix_sum[j-1] && dp[l][i] && dp[i+1][j-1] && dp[j][r]) {
            dp[l][r]=true;
            found=true;
            break;
          }
        }
        if (found) {
          break;
        }
      }
      max_ball=max(max_ball,(prefix_sum[r]-prefix_sum[l-1])*dp[l][r]);
    }
  }

  cout<<max_ball<<endl;

  return 0;

}