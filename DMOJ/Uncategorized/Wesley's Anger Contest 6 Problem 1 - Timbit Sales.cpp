#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  while(N--) {
    double P, C;
    cin >> P >> C;
    double ans = P / (C / 100.0 + 1.0);
    cout << setprecision(12) << fixed << ans << '\n';
  }

  return 0;
}