#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> breadth_counts(n + m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int a_i_j;
      cin >> a_i_j;
      int start_dist = i + j;
      if(start_dist * 2 == n + m - 2) continue;
      if(start_dist * 2 > n + m - 2) start_dist = m + n - 2 - start_dist;
      breadth_counts[start_dist].first += a_i_j == 0;
      breadth_counts[start_dist].second += a_i_j == 1;
    }
  }
 
  int ans = 0;
  for(int i = 0; i <= n + m - 2; i++) ans += min(breadth_counts[i].first, breadth_counts[i].second);
  
  cout << ans << '\n';
}
 
int32_t main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve_tc();
 
  return 0;
}