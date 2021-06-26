#include <bits/stdc++.h>
using namespace std;

#define maxN 1000

int N;
char results_a[maxN + 1], results_b[maxN + 1];
int A[maxN + 1], B[maxN + 1];
int dp[maxN + 1][maxN + 1] = {0};

bool valid_game(int index_a, int index_b) {
  if (results_a[index_a] == results_b[index_b] || A[index_a] == B[index_b]) return false;
  if ((results_a[index_a] == 'W') == (A[index_a] > B[index_b])) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> results_a[i];
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= N; i++) cin >> results_b[i];
  for (int i = 1; i <= N; i++) cin >> B[i];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (valid_game(i, j)) dp[i][j] = max(dp[i][j], A[i] + B[j] + dp[i - 1][j - 1]);
    }
  }

  cout << dp[N][N] << "\n";

  return 0;
}