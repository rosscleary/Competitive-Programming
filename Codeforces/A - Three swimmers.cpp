#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve_tc() {
  int p, a, b, c;
  cin >> p >> a >> b >> c;
 
  cout << min((a - p % a) % a, min((b - p % b) % b, (c - p % c) % c)) << '\n';
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