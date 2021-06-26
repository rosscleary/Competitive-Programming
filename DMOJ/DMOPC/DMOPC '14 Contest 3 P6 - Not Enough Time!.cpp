#include <bits/stdc++.h>
using namespace std;

const int MT = 1e4 + 5;

int N, T;
vector<int> dp(MT);
int answer = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> T;

  for(int customer = 0; customer < N; customer++) {
    vector<int> new_dp(MT);
    int times[3], values[3];
    for(int i = 0; i < 3; i++) {
      cin >> times[i] >> values[i];
    }
    for(int time = 0; time <= T; time++) {
      new_dp[time] = dp[time];
      for(int i = 0; i < 3; i++) {
        if(time >= times[i]) new_dp[time] = max(new_dp[time], values[i] + dp[time - times[i]]);
      }
    }
    dp = new_dp;
  }

  for(int time = 0; time <= T; time++) answer = max(answer, dp[time]);
  cout << answer << "\n";

  return 0;
}