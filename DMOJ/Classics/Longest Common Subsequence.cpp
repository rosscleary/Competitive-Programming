#include <bits/stdc++.h>
using namespace std;

#define maxN 2000
#define maxM 2000

int N, M, seq_1[maxN + 1], seq_2[maxM + 1];
int dp[maxN + 1][maxM + 1] = {0}, dp_solved[maxN + 1][maxM + 1] = {false};

int dp_result(int seq_1_index, int seq_2_index) {
  if (seq_1_index > N || seq_2_index > M) {
    return 0;
  }

  if (dp_solved[seq_1_index][seq_2_index]) {
    return dp[seq_1_index][seq_2_index];
  }

  if (seq_1[seq_1_index] == seq_2[seq_2_index]) {
    dp[seq_1_index][seq_2_index] = 1 + dp_result(seq_1_index + 1, seq_2_index + 1);
  }
  else {
    dp[seq_1_index][seq_2_index] = max(dp_result(seq_1_index + 1, seq_2_index), dp_result(seq_1_index, seq_2_index + 1));
  }

  dp_solved[seq_1_index][seq_2_index] = true;
  return dp[seq_1_index][seq_2_index];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> seq_1[i];
  }
  for (int i = 1; i <= M; i++) {
    cin >> seq_2[i];
  }

  cout << dp_result(1, 1) << "\n";

  return 0;
}