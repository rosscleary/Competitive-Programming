#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define maxN 100000

void min_self(int &curr_dp, int new_dp) {
  if (new_dp < curr_dp) curr_dp = new_dp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K, h[maxN];

  cin >> N >> K;

  for (int i = 0; i < N; i++) cin >> h[i];

  int dp[maxN];

  dp[N - 1] = 0;

  for (int stone = N - 2; stone >= 0; stone--) {
    dp[stone] = INT_MAX;
    for (int next = stone + 1; next <= min(stone + K, N - 1); next++) min_self(dp[stone], abs(h[next] - h[stone]) + dp[next]);
  }

  cout << dp[0] << endl;

  return 0;
}