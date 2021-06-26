#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> x_d(N);
  for(int i = 0; i < N; i++) {
    cin >> x_d[i].first >> x_d[i].second;
  }
  sort(x_d.begin(), x_d.end());
  int zero_i;
  for(int i = 0; i < N; i++) {
    if(x_d[i].first == 0) {
      zero_i = i;
      break;
    }
  }

  int dp[N][N][2];
  memset(dp, -1, sizeof(dp));
  for(int i = zero_i; i >= 0; i--) {
    for(int j = zero_i; j < N; j++) {
      if(i == j) {
        dp[i][j][0] = dp[i][j][1] = x_d[i].second;
        continue;
      }
      if(dp[i + 1][j][0] != -1 && dp[i + 1][j][0] - (x_d[i + 1].first - x_d[i].first) >= 0) {
        dp[i][j][0] = dp[i + 1][j][0] - (x_d[i + 1].first - x_d[i].first) + x_d[i].second;
      }
      if(dp[i + 1][j][1] != -1 && dp[i + 1][j][1] - (x_d[j].first - x_d[i].first) >= 0) {
        dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][1] - (x_d[j].first - x_d[i].first) + x_d[i].second);
      }
      dp[i][j][1] = -1;
      if(dp[i][j - 1][1] != -1 && dp[i][j - 1][1] - (x_d[j].first - x_d[j - 1].first) >= 0) {
        dp[i][j][1] = dp[i][j - 1][1] - (x_d[j].first - x_d[j - 1].first) + x_d[j].second;
      }
      if(dp[i][j - 1][0] != -1 && dp[i][j - 1][0] - (x_d[j].first - x_d[i].first) >= 0) {
        dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - (x_d[j].first - x_d[i].first) + x_d[j].second);
      }
    }
  }

  int left_sum = 0;
  int ans = -1;
  for(int i = zero_i; i >= 0; i--) {
    left_sum += x_d[i].second;
    int right_sum = 0;
    for(int j = zero_i; j < N; j++) {
      right_sum += j != zero_i ? x_d[j].second : 0;
      if(dp[i][j][0] != -1 || dp[i][j][1] != -1) {
        ans = max(ans, left_sum + right_sum);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}