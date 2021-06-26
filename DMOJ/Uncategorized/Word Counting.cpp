#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  vector<int> p;
  unordered_map<int, int> p_index;
  for(int i = 1; i <= N; i++) {
    int p_i;
    cin >> p_i;
    if(!p_index.count(p_i)) {
      p.push_back(p_i), p_index[p_i] = i;
    }
  }

  sort(p.begin(), p.end());
  while(Q--) {
    int w_i;
    cin >> w_i;
    int target = sqrt(w_i);
    auto hi = upper_bound(p.begin(), p.end(), target);
    if(hi == p.end()) {
      cout << p_index[p[p.size() - 1]] << ' ';
      continue;
    }
    if(hi == p.begin()) {
      cout << p_index[p[0]] << ' ';
      continue;
    }
    auto lo = hi - 1;
    if(w_i < *lo * *hi || (w_i == *lo * *hi && p_index[*lo] < p_index[*hi])) {
      cout << p_index[*lo] << ' ';
    } else {
      cout << p_index[*hi] << ' ';
    }
  }
  cout << '\n';

  return 0;
}