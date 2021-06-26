#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  string A, B;
  cin >> A >> B;
  A = ' ' + A, B = ' ' + B;
  vector<int> dp(N + 1);
  for(int i = 0; i <= N; i++) {
    dp[i] = i;
  }
  int ans = 0;
  for(int i = 1; i <= M; i++) {
    vector<int> new_dp(N + 1);
    new_dp[0] = i;
    for(int j = 1; j <= N; j++) {
      if(A[j] == B[i]) {
        new_dp[j] = dp[j - 1];
      } else {
        new_dp[j] = 1 + min(dp[j], min(dp[j - 1], new_dp[j - 1]));
      }
    }
    if(i != M) {
      ans += new_dp[N];
    }
    dp = new_dp;
  }

  cout << ans << '\n';

  return 0;
}