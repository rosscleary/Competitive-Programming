#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int G;
  cin >> G;
  double ans = 1.0;
  while(G--) {
    double e_g, p_g;
    cin >> e_g >> p_g;
    ans *= (p_g - e_g) / p_g;
  }
  cout << setprecision(6) << fixed << ans << '\n';

  return 0;
}