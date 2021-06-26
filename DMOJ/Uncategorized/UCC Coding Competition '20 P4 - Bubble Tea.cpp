#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> prices(N + 1);
  for(int i = 1; i <= N; i++) cin >> prices[i];

  vector<int> dp(N + 1);
  dp[0] = 0, dp[1] = prices[1], dp[2] = prices[1] + prices[2] - min(prices[1], prices[2]) / 4;
  for(int price = 3; price <= N; price++) {
    int option_1 = prices[price] + dp[price - 1];
    int option_2 = prices[price] + prices[price - 1] - min(prices[price], prices[price - 1]) / 4 + dp[price - 2];
    int option_3 = prices[price] + prices[price - 1] + prices[price - 2] - min(prices[price], min(prices[price - 1], prices[price - 2])) / 2;
    option_3 += dp[price - 3];
    dp[price] = min(option_1, min(option_2, option_3));
  }
  cout << dp[N] << '\n';

  return 0;
}