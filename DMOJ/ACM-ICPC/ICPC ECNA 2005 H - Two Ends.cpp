#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3 + 5;

int game_counter = 1;
int n, cards[MAX_N];
int dp[MAX_N][MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(true) {
    cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n; i++) cin >> cards[i];

    for(int left = n - 2; left >= 0; left--) {
      for(int right = left + 1; right < n; right++) {
        int result_1, result_2;
        if(cards[left + 1] >= cards[right]) result_1 = cards[left] - cards[left + 1] + dp[left + 2][right];
        else result_1 = cards[left] - cards[right] + dp[left + 1][right - 1];
        if(cards[left] >= cards[right - 1]) result_2 = cards[right] - cards[left] + dp[left + 1][right - 1];
        else result_2 = cards[right] - cards[right - 1] + dp[left][right - 2];
        dp[left][right] = max(result_1, result_2);
      }
    }
    cout << "In game " << game_counter <<", the greedy strategy might lose by as many as " <<  dp[0][n - 1]<< " points.\n";

    memset(dp, 0, sizeof(dp));
    game_counter++;
  }

  return 0;
}