#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string S, T;
  cin >> S >> T;

  int ans = S.size() + T.size();
  for(int i = 0; i < min(S.size(), T.size()); i++) {
    if(S[i] != T[i]) {
      break;
    }
    ans -= 2;
  }

  cout << ans << '\n';

  return 0;
}