#include <bits/stdc++.h>
using namespace std;

void solve_tc() {
  int n;
  cin >> n;
  bool ans = false;
  while(n--) {
    int a_i;
    cin >> a_i;
    if(int(sqrt(a_i)) * int(sqrt(a_i)) != a_i) {
      ans = true;
    }
  }

  cout << (ans ? "YES" : "NO") << '\n';
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