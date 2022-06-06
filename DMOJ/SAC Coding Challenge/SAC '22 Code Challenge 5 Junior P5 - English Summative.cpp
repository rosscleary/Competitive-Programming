#include <bits/stdc++.h>
using namespace std;

int dp[200001][26];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<string> S(N);
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  int ans = 0;
  for(int i = N - 1; i >= 0; i--) {
    int score = 0;
    for(int j = 0; j < S[i].size() - 1; j++) {
      score += S[i][j] == S[i][j + 1];
    }
    for(int j = 0; j < 26; j++) {
      dp[i][j] = max(dp[i + 1][j], int(dp[i + 1][S[i][S[i].size() - 1] - 'a'] + score + (S[i][0] - 'a' == j)));
    }
    ans = max(ans, score + dp[i + 1][S[i][S[i].size() - 1] - 'a']);
  }

  cout << ans << '\n';

  return 0;
}