#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, W;
  cin >> N >> W;
  vector<int> w(N), v(N);
  for(int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }

  vector<int> dp(W + 1);
  for(int i = N - 1; i >= 0; i--) {
    vector<int> new_dp(W + 1);
    for(int j = 0; j <= W; j++) {
      int leave = dp[j];
      int take = -1;
      if(j - w[i] >= 0) {
        take = v[i] + dp[j - w[i]];
      }
      new_dp[j] = max(leave, take);
    }
    dp = new_dp;
  }

  cout << dp[W] << '\n';

  return 0;
}