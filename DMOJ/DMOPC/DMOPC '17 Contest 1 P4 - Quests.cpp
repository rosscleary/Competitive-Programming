#include <bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  int N, H;
  cin >> N >> H;

  vector<LL> last_dp(H + 1);
  for(int place = 0; place < N; place++) {
    int g, h, q, t;
    cin >> g >> h >> q >> t;
    vector<LL> dp_already(H + 1);
    vector<LL> curr_dp(H + 1);
    for(int time = 0; time <= H; time++) {
      dp_already[time] = last_dp[time];
      if(time >= t) dp_already[time] = max(dp_already[time], q + dp_already[time - t]);
      curr_dp[time] = last_dp[time];
      if(time >= h) curr_dp[time] = max(curr_dp[time], g + dp_already[time - h]);
    }
    last_dp = curr_dp;
  }

  LL answer = 0;
  for(int time = 0; time <= H; time++) answer = max(answer, last_dp[time]);
  cout << answer << "\n";

  return 0;
}