#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, C;
  cin >> N >> C;

  vector<vector<int>> dp(N + 1, vector<int>(C + 1));
  dp[0][0] = 1;
  for(int i = 1; i <= N; i++) {
    vector<int> prefix_sum(C + 1);
    prefix_sum[0] = dp[i - 1][0];
    for(int j = 1; j <= C; j++) prefix_sum[j] = (prefix_sum[j - 1] + dp[i - 1][j]) % mod;
    for(int j = 0; j <= C; j++) dp[i][j] = (prefix_sum[j] - (j - i >= 0 ? prefix_sum[j - i] : 0) + mod) % mod;
  }

  cout << dp[N][C] << '\n';

  return 0;
}