#include <bits/stdc++.h>
using namespace std;

#define maxN 1000
#define maxM 1000

int N, M;
char DNA_1[maxN + 1], DNA_2[maxM + 1];
int dp[maxN + 1][maxM + 1];
bool dp_solved[maxN + 1][maxM + 1] = {false};

int ceil_divide_3(int numerator) {
  if (numerator % 3 == 0) {
    return numerator / 3;
  }
  return (numerator / 3) + 1;
}

int dp_result(int index_1, int index_2) {
  if (index_1 == N + 1 && index_2 == M + 1) {
    return 0;
  }
  if (index_1 == N + 1) {
    return ceil_divide_3(M - index_2 + 1);
  }
  if (index_2 == M + 1) {
    return ceil_divide_3(N - index_1 + 1);
  }
  if (dp_solved[index_1][index_2]) {
    return dp[index_1][index_2];
  }

  if (DNA_1[index_1] == DNA_2[index_2]) {
    dp_solved[index_1][index_2] = true;
    return dp[index_1][index_2] = dp_result(index_1 + 1, index_2 + 1);
  }

  dp[index_1][index_2] = 1 + dp_result(index_1 + 1, index_2 + 1);
  dp[index_1][index_2] = min(dp[index_1][index_2], 1 + dp_result(index_1 + 1, index_2));
  dp[index_1][index_2] = min(dp[index_1][index_2], 1 + dp_result(index_1, index_2 + 1));

  if (index_1 < N) {
    dp[index_1][index_2] = min(dp[index_1][index_2], 1 + dp_result(index_1 + 2, index_2));
  }
  if (index_1 < N - 1) {
    dp[index_1][index_2] = min(dp[index_1][index_2], 1 + dp_result(index_1 + 3, index_2));
  }
  if (index_2 < M) {
    dp[index_1][index_2] = min(dp[index_1][index_2], 1 + dp_result(index_1, index_2 + 2));
  }
  if (index_2 < M - 1) {
    dp[index_1][index_2] = min(dp[index_1][index_2], 1 + dp_result(index_1, index_2 + 3));
  }

  dp_solved[index_1][index_2] = true;
  return dp[index_1][index_2];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> DNA_1[i];
  }
  for (int i = 1; i <= M; i++) {
    cin >> DNA_2[i];
  }

  memset(dp, INT_MAX, sizeof(dp));

  cout << dp_result(1, 1) << "\n";

  return 0;
}