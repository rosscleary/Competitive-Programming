#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve_tc() {
  int a, b;
  cin >> a >> b;
 
  if(b > a) swap(a, b);
  if(b * 2 <= a) {
    cout << b << '\n';
    return;
  }
  int ans = a - b + (((b - (a - b)) / 3) * 2);
  if(((b - (a - b)) % 3) == 2) ans++;
  cout << ans << '\n';
}
 
int32_t main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve_tc();
 
  return 0;
}