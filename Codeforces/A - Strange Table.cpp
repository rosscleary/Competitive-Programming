#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve_tc() {
  int n, m, x;
  cin >> n >> m >> x;
 
  int ans;
  if(x % n == 0) {
    ans = m * (n - 1) + x / n;
  } else {
    ans = m * (x % n - 1) + x / n + 1;
  }
 
  cout << ans << '\n';
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