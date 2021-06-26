#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int x, y, n;
  cin >> x >> y >> n;
 
  int ans = ((n - y) / x) * x + y;
  cout << ans << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) {
    solve_tc();
  }
 
  return 0;
}