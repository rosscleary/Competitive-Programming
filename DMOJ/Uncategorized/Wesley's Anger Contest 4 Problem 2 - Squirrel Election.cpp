#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double

#define fast_inputandoutput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

// ---------- END OF TEMPLATE ---------- //

const int M1 = 5e3 + 5;
const int Inf = 1e18;

int N, v[M1], p[M1];
int suffix_sum[M1];
int dp[M1][M1];

int solve(int index, int points_needed) {
  if(points_needed <= 0) return 0;
  if(points_needed > suffix_sum[index]) return Inf;
  if(index == N) return 0;
  if(dp[index][points_needed] != -1) return dp[index][points_needed];

  dp[index][points_needed] = min((v[index] / 2) + 1 + solve(index + 1, points_needed - p[index]), solve(index + 1, points_needed));
  return dp[index][points_needed];
}

int32_t main() { fast_inputandoutput

  cin >> N;
  for(int i = 0; i < N; i++) cin >> v[i] >> p[i];

  for(int i = N - 1; i >= 0; i--) suffix_sum[i] = suffix_sum[i + 1] + p[i];

  memset(dp, -1, sizeof(dp));
  cout << solve(0, (suffix_sum[0] / 2) + 1) << endl;

  return 0;
}