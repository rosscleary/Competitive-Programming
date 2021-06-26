#include <bits/stdc++.h>
using namespace std;

const int M1 = 32;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }

  vector<int> max_dp(M1);
  int ans = 0;
  for(int i = N - 1; i >= 0; i--) {
    vector<int> on_bits;
    for(int j = 0; j < M1; j++) {
      if((1 << j) & a[i]) {
        on_bits.push_back(j);
      } 
    }
    int dp = 0;
    for(int j: on_bits) {
      dp = max(dp, 1 + max_dp[j]);
    }
    for(int j: on_bits) {
      max_dp[j] = max(max_dp[j], dp);
    }
    ans = max(ans, dp);
  }

  cout << ans << '\n';

  return 0;
}