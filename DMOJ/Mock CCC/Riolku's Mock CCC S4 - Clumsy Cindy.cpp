#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> a(N), b(N), c(N);
  int max_c = -1;
  for(int i = 0; i < N; i++) {
    cin >> c[i];
    max_c = max(max_c, c[i]);
  }
  for(int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }

  vector<vector<int>> dp(N, vector<int>(max_c + 1));
  for(int i = 0; i <= c[N - 1]; i++) {
    dp[N - 1][i] = (c[N - 1] - i) / a[N - 1];
    if((c[N - 1] - i) % a[N - 1] != 0) {
      dp[N - 1][i]++;
    }
  }
  for(int i = N - 2; i >= 0; i--) {
    vector<int> options(c[i + 1] + 1);
    for(int j = 0; j < min(c[i + 1], b[i]); j++) {
      for(int k = j, cnt = 0; k <= c[i + 1]; k += b[i], cnt++) {
        options[k] = cnt + dp[i + 1][k];
      }
    }
    vector<int> suffix_best(c[i + 1] + 1);
    for(int j = c[i + 1]; j >= 0; j--) {
      if(j + b[i] > c[i + 1]) {
        suffix_best[j] = j;
      } else {
        if(options[j] < options[suffix_best[j + b[i]]]) {
          suffix_best[j] = j;
        } else {
          suffix_best[j] = suffix_best[j + b[i]];
        }
      }
    }
    for(int j = 0; j <= c[i]; j++) {
      int add = (c[i] - j) / a[i];
      if((c[i] - j) % a[i] != 0) {
        add++;
      }
      if(add * b[i] > c[i + 1]) {
        dp[i][j] = add + dp[i + 1][c[i + 1]];
      } else {
        int all_add = c[i + 1] / b[i];
        if(c[i + 1] % b[i] != 0) {
          all_add++;
        }
        dp[i][j] = all_add + dp[i + 1][c[i + 1]];
        dp[i][j] = min(dp[i][j], add + (suffix_best[add * b[i]] - add * b[i]) / b[i] + dp[i + 1][suffix_best[add * b[i]]]);
      }
    }
  }

  cout << dp[0][0] << '\n';

  return 0;
}