#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e5 + 1, M2 = 2e5 + 1;

void fill_dp(vector<vector<int>> &dp, int options_size, vector<int> options) {
  for(int i = 1; i < M1; i++) {
    dp[0][i] = M1;
  }
  for(int i = 1; i <= options_size; i++) {
    for(int j = 0; j < M1; j++) {
      dp[i][j] = dp[i - 1][j];
      if(j - options[i] >= 0) {
        dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - options[i]]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int H;
  cin >> H;
  vector<int> h(H + 1);
  for(int i = 1; i <= H; i++) {
    cin >> h[i];
  }
  int B;
  cin >> B;
  vector<int> b(B + 1);
  for(int i = 1; i <= B; i++) {
    cin >> b[i];
  }

  vector<vector<int>> dp_h(H + 1, vector<int>(M1)), dp_b(B + 1, vector<int>(M1));
  fill_dp(dp_h, H, h), fill_dp(dp_b, B, b);

  int ans = M2;
  for(int i = 1; i < M1; i++) {
    if(dp_h[H][i] < M1 && dp_b[B][i] < M1) {
      ans = min(ans, dp_h[H][i] + dp_b[B][i]);
    }
  }

  if(ans < M2) {
    cout << ans;
  } else {
    cout << "impossible";
  }
  cout << '\n';

  return 0;
}