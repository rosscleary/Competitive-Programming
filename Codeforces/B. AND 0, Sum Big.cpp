#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

void solve_tc() {
  int n, k;
  cin >> n >> k;
  int ans = 1;
  for(int i = 0; i < k; i++) {
    ans *= n, ans %= mod;
  }

  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while(t--) {
    solve_tc();
  }
	
  return 0;
}