#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 21;
const int MOD = 1e9 + 7;

int N;
bool match[21][21];
int dp[1 << MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) cin >> match[i][j];
  }

  dp[0] = 1;
  for(int mask = 1; mask < (1 << N); mask++) {
    int row = N - __builtin_popcount(mask);
    for(int next = 0; next < N; next++) {
      if(match[row][next] && (mask & (1 << next))) {
        int next_mask = mask;
        next_mask &= ~(1 << next);
        dp[mask] += dp[next_mask];
        dp[mask] %= MOD;
      }
    }
  }
  cout << dp[(1 << N) - 1] << "\n";

  return 0;
}