#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 25, MAX_S = 1e2 + 5;

int test_case = 5;
int S, N;
int space, utility;
int dp[MAX_N][MAX_S];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(test_case--) {
    cin >> S >> N;

    for(int item = 1; item <= N; item++) {
      cin >> space >> utility;
      for(int available = 0; available <= S; available++) {
        dp[item][available] = dp[item - 1][available];
        if(available >= space) dp[item][available] = max(dp[item][available], utility + dp[item - 1][available - space]);
      }
    }
    cout << dp[N][S] << "\n";

    memset(dp, 0, sizeof(dp));
  }

  return 0;
}