#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
 
  vector<int> pref_min(m), suff_max(m);
  int last = -1;
  for(int i = 0; i < m; i++) {
    last++;
    while(s[last] != t[i]) {
      last++;
    }
    pref_min[i] = last;
  }
  last = n;
  for(int i = m - 1; i >= 0; i--) {
    last--;
    while(s[last] != t[i]) {
      last--;
    }
    suff_max[i] = last;
  }
 
  int ans = 0;
  for(int i = 0; i < m - 1; i++) {
    ans = max(ans, suff_max[i + 1] - pref_min[i]);
  }
 
  cout << ans << '\n';
 
  return 0;
}