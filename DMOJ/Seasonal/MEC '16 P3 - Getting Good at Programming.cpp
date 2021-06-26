#include <bits/stdc++.h>
using namespace std;

#define maxN 100
#define maxT 100
#define maxL 100

int N, T, L, level_times[maxN + 1][maxL + 1] = {0}, level_values[maxN + 1][maxL + 1] = {0};
int dp[maxN + 1][maxT + 1] = {0};
bool dp_solved[maxN + 1][maxT + 1] = {false};

int dp_result(int skill, int time_left) {
  if (skill > N) {
    return 0;
  }

  if (dp_solved[skill][time_left]) {
    return dp[skill][time_left];
  }

  dp[skill][time_left] = dp_result(skill + 1, time_left);

  int total_time = 0, total_value = 0;
  for (int i = 1; true; i++) {
    total_time += level_times[skill][i];
    total_value += level_values[skill][i];
    if (level_times[skill][i] == 0 || total_time > time_left) {
      break;
    }
    dp[skill][time_left] = max(dp[skill][time_left], total_value + dp_result(skill + 1, time_left - total_time));
  }

  dp_solved[skill][time_left] = true;
  return dp[skill][time_left];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> T;
  for (int i = 1; i <= N; i++) {
    cin >> L;
    for (int j = 1; j <= L; j++) {
      cin >> level_times[i][j];
      cin >> level_values[i][j];
    }
  }

  cout << dp_result(1, T) << "\n";

  return 0;
}