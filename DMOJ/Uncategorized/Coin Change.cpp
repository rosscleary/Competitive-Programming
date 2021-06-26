#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int x;
  cin >> x;
  int n;
  cin >> n;
  vector<int> coins(n);
  for(int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  vector<int> dp(x + 1);
  for(int i = 1; i <= x; i++) {
    dp[i] = 1e4;
    for(int j = 0; j < n; j++) {
      if(i >= coins[j]) {
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
  }

  cout << dp[x] << '\n';

  return 0;
}