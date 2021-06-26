#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> l_v(N);
  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> l_v[i].first >> l_v[i].second;
    sum += l_v[i].second;
  }

  if(N == 1) {
    cout << "0\n";
    return 0;
  }
  
  sort(l_v.begin(), l_v.end());

  vector<vector<int>> dp(N + 1, vector<int>(N));
  int max_dp = 0;
  for(int i = N - 1; i > 0; i--) {
    int suffix = i + 1;
    for(int j = 0; j < i; j++) {
      while(suffix < N && l_v[i].first + l_v[j].first > l_v[suffix].first) {
        suffix++;
      }
      int take_value = l_v[i].second + dp[suffix][i];
      dp[i][j] = max(dp[i + 1][j], take_value);
      max_dp = max(max_dp, l_v[j].second + take_value);
    }
  }

  cout << sum - max_dp << '\n';

  return 0;
}