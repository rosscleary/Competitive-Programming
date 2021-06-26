#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, X, Y, Z;
  cin >> N >> X >> Y >> Z;

  vector<int> dp(N + 1);
  for(int i = 1; i <= N; i++) {
    dp[i] = -1e5 - 1;
    if(i >= X) dp[i] = max(dp[i], 1 + dp[i - X]);
    if(i >= Y) dp[i] = max(dp[i], 1 + dp[i - Y]);
    if(i >= Z) dp[i] = max(dp[i], 1 + dp[i - Z]);
  }

  cout << dp[N] << '\n';

  return 0;
}