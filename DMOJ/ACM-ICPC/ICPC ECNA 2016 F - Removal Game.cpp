#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e5 + 5;

bool last_tc = false;

int gcd(int num_1, int num_2) {
  return num_2 ? gcd(num_2, num_1 % num_2) : num_1;
}

void solve_tc() {
  int n;
  cin >> n;
  if(!n) {
    last_tc = true;
    return;
  }
  vector<int> seq(n);
  for(int i = 0; i < n; i++) cin >> seq[i];

  vector<vector<int>> dp(n - 1, vector<int>(n));
  for(int len = 1; len < n - 1; len++) {
    for(int start = 0; start < n; start++) {
      dp[len][start] = M1;
      int end_1 = start ? seq[start - 1] : seq[n - 1], end_2 = seq[(start + len) % n];
      int gcd_value = gcd(end_1, end_2);
      int pick_i = start, left_len = 0, right_len = len - 1, right_start = (start + 1) % n;
      for(int pick_rep = 0; pick_rep < len; pick_rep++) {
        dp[len][start] = min(dp[len][start], gcd_value + dp[left_len][start] + dp[right_len][right_start]);
        pick_i = (pick_i + 1) % n, left_len++, right_len--, right_start = (right_start + 1) % n;
      }
      //cout << len << ' ' << start << ' ' << dp[len][start] << endl;
    }
  }

  int answer = M1;
  for(int last_1 = 0; last_1 < n - 1; last_1++) {
    for(int last_2 = last_1 + 1; last_2 < n; last_2++) {
      int option_value = gcd(seq[last_1], seq[last_2]) + dp[last_2 - last_1 - 1][last_1 + 1] + dp[last_1 + n - last_2 - 1][(last_2 + 1) % n];
      answer = min(answer, option_value);
    }
  }
  cout << answer << '\n';
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  while(!last_tc) solve_tc();

  return 0;
}