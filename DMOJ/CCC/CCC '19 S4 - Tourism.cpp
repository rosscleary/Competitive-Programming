#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;
  vector<int> day_values(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> day_values[i];
  }

  vector<long long> dp(N + 1);
  for(int i = 1; i <= K; i++) {
    dp[i] = max(dp[i - 1], (long long)day_values[i]);
  }
  vector<long long> pref_max(N + 1), pref_max_dp(N + 1);
  for(int i = K; i < N; i += K) {
    int pref_max_value = 0;
    for(int j = i; j > i - K; j--) {
      pref_max_value = max(pref_max_value, day_values[j]);
      pref_max[j] = max(pref_max[j + 1], pref_max_value + dp[j - 1]), pref_max_dp[j] = max(pref_max_dp[j + 1], dp[j]);
    }
    pref_max_value = 0;
    for(int j = i + 1; j <= N && j <= i + K; j++) {
      pref_max_value = max(pref_max_value, day_values[j]), dp[j] = max(pref_max_value + pref_max_dp[j - K], pref_max[j - K + 1]);
    }
  }

  cout << dp[N] << '\n';

  return 0;
}