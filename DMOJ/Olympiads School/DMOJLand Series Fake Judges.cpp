#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<int> add_freq(N);
  while(Q--) {
    int l_i, r_i;
    cin >> l_i >> r_i;
    add_freq[l_i - 1]++;
    if(r_i != N) {
      add_freq[r_i]--;
    }
  }
  for(int i = 1; i < N; i++) {
    add_freq[i] += add_freq[i - 1];
  }

  sort(a.begin(), a.end(), greater<int>());
  sort(add_freq.begin(), add_freq.end());
  int ans = 0;
  for(int i = 0; i < N; i++) {
    ans += a[i] * add_freq[i];
  }

  cout << ans << '\n';

  return 0;
}