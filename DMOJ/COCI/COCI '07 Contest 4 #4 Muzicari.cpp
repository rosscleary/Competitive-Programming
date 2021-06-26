#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int T, N;
  cin >> T >> N;
  vector<int> break_times(N + 1);
  vector<bool> is_break_time(T + 1);
  for(int i = 1; i <= N; i++) {
    cin >> break_times[i];
    is_break_time[break_times[i]] = true;
  }

  vector<vector<pair<int, int>>> dp(N + 1, vector<pair<int, int>>(T + 1));
  for(int time = 0; time <= T; time++) dp[0][time].first = time;
  for(int i = 1; i <= N; i++) {
    for(int time = 0; time <= T; time++) {
      dp[i][time].first = dp[i - 1][time].first, dp[i][time].second = time;
      if(time >= break_times[i]) {
        int take_value = dp[i - 1][time - break_times[i]].first;
        if(take_value < dp[i][time].first) dp[i][time].first = take_value, dp[i][time].second = time - break_times[i];
      }
    }
  }

  vector<int> answers(N + 1);
  for(int i = 1; i <= N; i++) answers[i] = -1;
  int time = T;
  for(int i = N; i > 0; i--) {
    if(dp[i][time].second == time) continue;
    time = dp[i][time].second;
    answers[i] = time;
  }
  int second_time = 0;
  for(int i = 1; i <= N; i++) {
    if(answers[i] == -1) {
      answers[i] = second_time;
      second_time += break_times[i];
    }
  }
  
  for(int i = 1; i < N; i++) cout << answers[i] << ' ';
  cout << answers[N] << '\n';

  return 0;
}