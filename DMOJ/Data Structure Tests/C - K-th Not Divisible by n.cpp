#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve() {
  ll n, k; cin >> n >> k;
 
  if(k % (n - 1) == 0) cout << ((k / (n - 1)) * n) - 1 << '\n';
  else cout << ((k / (n - 1)) * n) + (k % (n - 1)) << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}