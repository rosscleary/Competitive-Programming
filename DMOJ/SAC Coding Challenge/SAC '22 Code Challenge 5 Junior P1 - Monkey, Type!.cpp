#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int X, T, W;
  cin >> X >> T >> W;

  cout << max(0, W - X) << endl;

  return 0;
}