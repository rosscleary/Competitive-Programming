#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  int ans = 0;
  
  while(N--) {
    int M, O;
    cin >> M >> O;
    ans += M > O;
  }

  cout << ans << '\n';

  return 0;
}