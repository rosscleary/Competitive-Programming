#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> changes;
  int sum = 0;
  for(int i = 0, cnt = N; i < N; i++, cnt--) {
    int a_i;
    cin >> a_i;
    sum += a_i * cnt, changes.push_back(a_i * 2 * cnt);
  }

  int run_sum = 0, best = -1e18;
  for(int i = 0; i < N; i++) {
    run_sum = max(run_sum, 0LL), run_sum += changes[i];
    best = max(best, run_sum);
  }

  cout << sum - best << '\n';

  return 0;
}