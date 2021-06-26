#include <bits/stdc++.h>
using namespace std;

void impossible() {
  cout << "0\n";
  exit(0);
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int C, D, E;
  cin >> C >> D >> E;
  int ans = 1;
  for(int i = 0; i < 30; i++) {
    int C_curr = (1 << i) & C, D_curr = (1 << i) & D, E_curr = (1 << i) & E;
    if(E_curr) {
      if(!C_curr || D_curr) {
        impossible();
      }
      ans *= 2;
    } else {
      if(C_curr != D_curr) {
        impossible();
      }
    }
  }

  cout << ans << '\n';

  return 0;
}