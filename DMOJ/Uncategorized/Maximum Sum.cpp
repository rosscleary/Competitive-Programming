#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> arr(N + 2);
  for(int i = 2; i <= N + 1; i++) {
    cin >> arr[i];
  }

  vector<int> dp(N + 2);
  for(int i = 2; i <= N + 1; i++) {
    dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
  }

  cout << dp[N + 1] << '\n';

  return 0;
}