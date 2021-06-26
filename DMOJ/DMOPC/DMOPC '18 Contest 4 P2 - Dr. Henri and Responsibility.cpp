#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }

  vector<bool> dp(sum + 1);
  dp[0] = true;
  for(int i = 0; i < N; i++) {
    vector<bool> new_dp(sum + 1);
    for(int j = 0; j <= sum; j++) {
      if(dp[j] || (j - A[i] >= 0 && dp[j - A[i]])) {
        new_dp[j] = true;
      }
    }
    dp = new_dp;
  }

  int ans = sum;
  for(int i = 0; i <= sum; i++) {
    if(dp[i]) {
      ans = min(ans, abs(sum - 2 * i));
    }
  }

  cout << ans << '\n';

  return 0;
}