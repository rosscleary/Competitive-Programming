#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  double T;
  cin >> T;

  int ans = 0;
  while(N--) {
    double c_i, d_i;
    cin >> c_i >> d_i;
    if(c_i - d_i / 100.0 * c_i <= T) {
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}