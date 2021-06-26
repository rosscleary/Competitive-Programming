#include <bits/stdc++.h>
using namespace std;

int N; string str;
vector<int> dp(N);

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N >> str;

  for(int left = N - 1; left >= 0; left--) {
    vector<int> new_dp(N);
    new_dp[left] = 0;
    if(left < N - 1) new_dp[left + 1] = (str[left] == str[left + 1]) ? 0 : 1;
    for(int right = left + 2; right < N; right++) {
      if(str[left] == str[right]) new_dp[right] = dp[right - 1];
      else new_dp[right] = 1 + min(new_dp[right - 1], dp[right]);
    }
    dp = new_dp;
  }

  cout << dp[N - 1] << '\n';

  return 0;
}