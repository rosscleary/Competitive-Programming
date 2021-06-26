#include <bits/stdc++.h>
using namespace std;

#define maxN 100
#define maxspace 30000

int space, N;
string song_name;
int value, S;
int dp[maxN + 1][maxspace + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case = 5;
  while (test_case--) {
    cin >> space >> N;

    memset(dp, 0, sizeof(dp));
    for (int song = 1; song <= N; song++) {
      cin >> song_name >> value >> S;
      for (int space_left = 0; space_left <= space; space_left++) {
        dp[song][space_left] = dp[song - 1][space_left];
        if (S <= space_left) {
          dp[song][space_left] = max(dp[song][space_left], value + dp[song - 1][space_left - S]);
        }
      }
    }

    int answer = 0;
    for (int space_used = 0; space_used <= space; space_used++) {
      answer = max(answer, dp[N][space_used]);
    }
    cout << answer << endl;
  }

  return 0;
}