#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> h(N + 1), pref_max(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> h[i];
    pref_max[i] = max(pref_max[i - 1], h[i]);
  } 

  vector<int> dp(N + 2), suff_sum(N + 2);
  suff_sum[N + 1] = 1;
  for(int i = N; i > 0; i--) {
    if(h[i] >= pref_max[i - 1]) {
      dp[i] = suff_sum[i + 1];
    } else {
      dp[i] = dp[i + 1];
    }
    suff_sum[i] = (suff_sum[i + 1] + dp[i]) % M1;
  }

  cout << dp[1] << '\n';

  return 0;
}