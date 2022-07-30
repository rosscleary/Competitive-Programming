#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  
  int ans = 0;
  for(int x = 0; x < 4; x++) {
    if((N - 5 * x) % 4 == 0 && (N - 5 * x) >= 0) {
      ans += (N - 5 * x) / 20 + 1;
    }
  }

  cout << ans << '\n';
  
  return 0;
}