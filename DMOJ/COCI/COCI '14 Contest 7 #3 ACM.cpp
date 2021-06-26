#include <bits/stdc++.h>
using namespace std;

const int M1 = 3, M2 = 1.5e5 + 5;
const int INF = 1e7;

int N;
int estimates[M1][M2];
int suffix_sum[M1][M2];

int dp[M2][M1][M1];
int answer = INF;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < N; j++) cin >> estimates[i][j];
  }
  for(int i = 0; i < 3; i++) {
    for(int j = N - 1; j >= 0; j--) suffix_sum[i][j] = estimates[i][j] + suffix_sum[i][j + 1];
  }

  for(int p_one = 0; p_one < M1; p_one++) {
    for(int p_two = 0; p_two < M1; p_two++) {
      if(p_one == p_two) continue;
      dp[N - 2][p_one][p_two] = estimates[p_one][N - 2] + estimates[p_two][N - 1];
    }
  }
  for(int task = N - 3; task > 0; task--) {
    for(int p_one = 0; p_one < M1; p_one++) {
      for(int p_two = 0; p_two < M1; p_two++) {
        if(p_one == p_two) continue;
        dp[task][p_one][p_two] = estimates[p_one][task];
        dp[task][p_one][p_two] += min(dp[task + 1][p_one][p_two], suffix_sum[p_two][task + 1]);
      }
    }
  }

  for(int first = 0; first < N - 2; first++) {
    answer = min(answer, (suffix_sum[0][0] - suffix_sum[0][first + 1]) + min(dp[first + 1][1][2], dp[first + 1][2][1]));
    answer = min(answer, (suffix_sum[1][0] - suffix_sum[1][first + 1]) + min(dp[first + 1][0][2], dp[first + 1][2][0]));
    answer = min(answer, (suffix_sum[2][0] - suffix_sum[2][first + 1]) + min(dp[first + 1][0][1], dp[first + 1][1][0]));
  }

  cout << answer << "\n";

  return 0;
}