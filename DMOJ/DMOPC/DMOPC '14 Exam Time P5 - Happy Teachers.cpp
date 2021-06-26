#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> H(n + 1), E(n + 1), P(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> H[i] >> E[i] >> P[i];
  }
  int s;
  cin >> s;

  vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(s + 1));
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= s; j++) {
      dp[i][j] = dp[i - 1][j];
      for(int gain = H[i], time_left = j - P[i], take_len = 1; time_left >= 0; time_left -= P[i], gain += max(0, H[i] - E[i] * take_len), take_len++) {
        int value = gain + dp[i - 1][time_left].first, len = take_len + dp[i - 1][time_left].second;
        if(value > dp[i][j].first) {
          dp[i][j].first = value, dp[i][j].second = len;
        } else if(value == dp[i][j].first) {
          dp[i][j].second = min(dp[i][j].second, len);
        }
      } 
    }
  }

  cout << dp[n][s].first << '\n' << dp[n][s].second << '\n';

  return 0;
}