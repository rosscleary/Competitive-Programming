#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int max_k = (5 * 1e2) + 5, max_n = 1e4 + 105;

int t;
int n, k, w;
LL prefix_sum[max_n];
LL dp[max_k][max_n];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while(t--) {
    cin >> n >> k >> w;
    for(int i = 1; i <= n; i++) {
      int value; cin >> value;
      prefix_sum[i] = prefix_sum[i - 1] + value;
    }
    for(int i = n + 1; i <= n + w; i++) prefix_sum[i] = prefix_sum[i - 1];
    n += w;

    for(int ball = 1; ball <= k; ball++) {
      for(int place = 1; place <= n; place++) {
        dp[ball][place] = max(dp[ball - 1][place], dp[ball][place - 1]);
        int end = max(0, place - w);
        int initial_value = prefix_sum[place] - prefix_sum[end];
        dp[ball][place] = max(dp[ball][place], initial_value + dp[ball - 1][end]);
        if(ball >= 2) {
          for(int second = end - 1; second >= max(0, end - w + 1); second--) {
            int new_value = prefix_sum[end] - prefix_sum[second];
            dp[ball][place] = max(dp[ball][place], initial_value + new_value + dp[ball - 2][second]);
          }
        }
      }
    }

    cout << dp[k][n] << "\n";

    memset(prefix_sum, 0, sizeof(prefix_sum));
    memset(dp, 0, sizeof(dp));
  }

  return 0;
}