#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;

int N;
double percents[MAX_N][MAX_N];
double dp[1 << MAX_N];
bool dp_solved[1 << MAX_N];

double dp_result(int row, int mask) {
  if(mask == 0) return 1.0;
  if(dp_solved[mask]) return dp[mask];

  for(int take = 0; take < N; take++) {
    if((1 << take) & mask) {
      int new_mask = mask;
      new_mask &= ~(1 << take);
      dp[mask] = max(dp[mask], (percents[row][take] / 100.0) * dp_result(row - 1, new_mask));
    }
  }

  dp_solved[mask] = true;
  return dp[mask];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) cin >> percents[i][j];
  }

  cout << setprecision(9) << fixed << (dp_result(N - 1, (1 << N) - 1)) * 100.0 << "\n";

  return 0;
}