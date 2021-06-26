#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> ans;
  for(int run = 0; run < M; run++) {
    int lo = run * N / M + 1, hi = (run + 1) * N / M + 1;
    if((run + 1) * N % M == 0) {
      hi--;
    }
    for(int rise = lo; rise <= hi; rise++) {
      ans.push_back({rise, run + 1});
    }
  }

  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for(auto i: ans) {
    cout << i.first << ' ' << i.second << '\n';
  }

  return 0;
}