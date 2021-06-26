#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e6;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;
  map<int, int> days, day_mins;
  while(Q--) {
    int d_i, p_i;
    cin >> d_i >> p_i;
    d_i = N - d_i + 1;
    days[d_i] = p_i;
    if(day_mins.count(d_i)) {
      day_mins[d_i] = min(day_mins[d_i], p_i);
    } else {
      day_mins[d_i] = p_i;
    }
  }

  days[N + 1] = 0;
  int last = 0, last_value = M1;
  vector<pair<int, int>> ranges;
  for(auto i: days) {
    if(i.first == N + 1) {
      ranges.push_back({last_value, i.first - last - 1});
      continue;
    }
    if(last_value < day_mins[i.first]) {
      ranges.push_back({last_value, i.first - last});
    } else {
      ranges.push_back({last_value, i.first - last - 1}), ranges.push_back({day_mins[i.first], 1});
    }
    last = i.first, last_value = i.second;
  }

  sort(ranges.begin(), ranges.end());
  int ans = 0;
  for(int i = 0; i < ranges.size() && M > 0; i++) {
    ans += ranges[i].first * min(M, ranges[i].second);
    M -= min(M, ranges[i].second);
  }

  cout << ans << '\n';

  return 0;
}