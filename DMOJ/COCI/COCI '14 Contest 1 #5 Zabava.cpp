#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL perm_sum(LL num) {
  return num * (num + 1) / 2;
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, K;
  cin >> N >> M >> K;
  vector<int> building_freq(M + 1);
  while(N--) {
    int building;
    cin >> building;
    building_freq[building]++;
  }

  vector<vector<LL>> dp(M + 1, vector<LL>(K + 1));
  for(int i = 1; i <= M; i++) {
    for(int j = 0; j <= K; j++) {
      dp[i][j] = 1e12;
      for(int take = 0; take <= j; take++) {
        int range_count = take + 1, low_range = building_freq[i] / range_count, mod_value = building_freq[i] % range_count;
        LL curr_value = perm_sum(low_range) * (range_count - mod_value) + perm_sum(low_range + 1) * mod_value;
        dp[i][j] = min(dp[i][j], curr_value + dp[i - 1][j - take]);
      }
    }
  }
  
  cout << dp[M][K] << '\n';

  return 0;
}