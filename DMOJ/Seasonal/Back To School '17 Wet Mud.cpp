#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, J;
  cin >> N >> M >> J;
  vector<int> p(M), t(M);
  for(int i = 0; i < M; i++) {
    cin >> p[i] >> t[i];
  }

  int lo = 0, hi = 1e6;
  int ans = -1;
  while(lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    vector<int> options;
    options.push_back(0), options.push_back(N + 1);
    for(int i = 0; i < M; i++) {
      if(t[i] <= mid) {
        options.push_back(p[i]);
      }
    }
    sort(options.begin(), options.end());
    bool possible = true;
    for(int i = 0; i < options.size() - 1; i++) {
      if(options[i + 1] - options[i] > J) {
        possible = false;
        break;
      }
    }
    if(possible) {
      ans = mid, hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}