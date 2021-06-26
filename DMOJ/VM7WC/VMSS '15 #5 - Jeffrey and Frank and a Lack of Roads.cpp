#include <bits/stdc++.h>
using namespace std;

struct apple {
  string E;
  int V, A, B;
};

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, R, S;
  cin >> N >> R >> S;
  vector<apple> apples(N);
  for(int i = 0; i < N; i++) {
    cin >> apples[i].E >> apples[i].V >> apples[i].A >> apples[i].B;
  }

  vector<vector<int>> dp(R + 1, vector<int>(S + 1));
  vector<vector<int>> dp_choice(R + 1, vector<int>(S + 1));
  for(int i = 0; i <= R; i++) {
    for(int j = 0; j <= S; j++) {
      for(int k = 0; k < N; k++) {
        if(apples[k].A <= i && apples[k].B <= j) {
          if(apples[k].V + dp[i - apples[k].A][j - apples[k].B] > dp[i][j]) {
            dp[i][j] = apples[k].V + dp[i - apples[k].A][j - apples[k].B];
            dp_choice[i][j] = k;
          }
        } 
      }
    }
  }

  cout << dp[R][S] << '\n';

  vector<int> apple_freq(N);
  int money_left = R, volume_left = S;
  while(dp[money_left][volume_left]) {
    apple_freq[dp_choice[money_left][volume_left]]++;
    int last_money_left = money_left;
    money_left -= apples[dp_choice[money_left][volume_left]].A;
    volume_left -= apples[dp_choice[last_money_left][volume_left]].B;
  }
  for(int i = 0; i < N; i++) {
    cout << apples[i].E << ' ' << apple_freq[i] << '\n';
  }

  return 0;
}