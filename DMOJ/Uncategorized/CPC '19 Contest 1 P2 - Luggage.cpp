#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  set<int> heights;
  unordered_map<int, int> heights_i;
  for(int i = 0; i < N; i++) {
    cin >> h[i];
    heights.insert(h[i]);
  }
  sort(h.begin(), h.end());
  for(int i = 0; i < N; i++) {
    if(!heights_i.count(h[i])) {
      heights_i[h[i]] = i;
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    ans = max(ans, i - heights_i[*heights.lower_bound(h[i] - K)] + 1);
  }

  cout << ans << '\n';

  return 0;
}