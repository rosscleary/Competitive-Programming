#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve() {
  ll n, k;
  cin >> n >> k;
 
  ll smallest_div = -1;
  for(ll i = 2; i <= sqrt(n); i++) {
    if(n % i == 0) {
      smallest_div = i; 
      break;
    }
  }
  if(smallest_div == -1) smallest_div = n;
 
  cout << n + smallest_div + (2 * (k - 1)) << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}