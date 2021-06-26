#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  unordered_map<int, int> slope_cnt;
  map<pair<int, int>, int> pair_cnt;
  int ans = N * (N - 1) / 2;
  for(int i = 0; i < N; i++) {
    int m, b;
    cin >> m >> b;
    ans -= slope_cnt[m] - pair_cnt[{m, b}];
    slope_cnt[m]++, pair_cnt[{m, b}]++;
  }

  cout << ans << '\n';

  return 0;
}