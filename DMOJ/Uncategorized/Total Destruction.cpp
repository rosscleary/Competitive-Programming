#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> v(Q);
  for(int i = 0; i < Q; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  vector<int> empty_ranges;
  for(int i = 1; i < Q; i++) {
    empty_ranges.push_back(v[i] - v[i - 1] - 1);
  }
  sort(empty_ranges.begin(), empty_ranges.end(), greater<int>());
  int ans = v[Q - 1] - v[0] + 1;
  for(int i = 0, take = 2; i < empty_ranges.size() && take <= M; i++, take++) {
    ans -= empty_ranges[i];
  }

  cout << ans << '\n';

  return 0;
}