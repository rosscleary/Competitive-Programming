#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define maxN 500
#define maxM 500

int N, M, grid[maxN + 1][maxM + 1];
ll dp[maxN + 1][maxM + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> grid[i][j];
    }
  }

  for (int row = N; row > 0; row--) {
    for (int col = M; col > 0; col--) {
      if (row == N && col == M) {
        dp[row][col] = grid[row][col];
      } else {
        dp[row][col] = LONG_LONG_MAX;
        if (row != N) {
          dp[row][col] = min(dp[row][col], grid[row][col] + dp[row + 1][col]);
        }
        if (col != M) {
          dp[row][col] = min(dp[row][col], grid[row][col] + dp[row][col + 1]);
        }
      }
    }
  }

  cout << dp[1][1] << endl;

  return 0;
}