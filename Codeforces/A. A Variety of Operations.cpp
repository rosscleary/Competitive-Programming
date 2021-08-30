#include <bits/stdc++.h>
using namespace std;

void solve_tc() {
  int c, d;
  cin >> c >> d;

  if(c + d == 0) {
    cout << 0;
  } else if(abs(c - d) % 2 == 1) {
    cout << -1;
  } else {
    cout << (c == d ? 1 : 2);
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