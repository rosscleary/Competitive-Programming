#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int T, S, q;
  cin >> T >> S >> q;
  int ans;
  for(ans = 0; S < T; ans++) {
    S *= q;
  }
 
  cout << ans << '\n';
 
  return 0;
}