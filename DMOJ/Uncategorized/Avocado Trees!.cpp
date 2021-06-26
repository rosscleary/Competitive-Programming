#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, Q, H;
  cin >> N >> Q >> H;

  vector<int> pref_sum(N + 1);
  for(int i = 1; i <= N; i++) {
    int a_i, b_i;
    cin >> a_i >> b_i;
    if(a_i <= H) {
      pref_sum[i] = b_i;
    }
    pref_sum[i] += pref_sum[i - 1];
  }

  int ans = -1;
  while(Q--) {
    int l, r;
    cin >> l >> r;
    ans = max(ans, pref_sum[r] - pref_sum[l - 1]);
  }

  cout << ans << '\n';

  return 0;
}