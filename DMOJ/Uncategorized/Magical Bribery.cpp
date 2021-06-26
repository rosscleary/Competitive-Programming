#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> amount_values(N + 1);
  for(int i = 1; i <= N; i++) cin >> amount_values[i];

  vector<int> dp(N + 1);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= i; j++) dp[i] = max(dp[i], amount_values[j] + dp[i - j]);
  }

  cout << dp[N] << '\n';

  return 0;
}