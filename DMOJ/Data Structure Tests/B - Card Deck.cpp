#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve_tc() {
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
 
  vector<pair<int, int>> pref_max(n);
  for(int i = 0; i < n; i++) {
    pref_max[i] = {p[i], i};
    if(i != 0 && pref_max[i - 1].first > p[i]) {
      pref_max[i] = pref_max[i - 1];
    } 
  }
 
  int curr = n - 1;
  while(curr >= 0) {
    for(int i = pref_max[curr].second; i <= curr; i++) {
      cout << p[i] << ' ';
    }
    curr = pref_max[curr].second - 1;
  }
  cout << '\n';
}
 
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) {
    solve_tc();
  }
 
  return 0;
}