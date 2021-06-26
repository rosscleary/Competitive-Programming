#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  LL ans = 0;
  while(N--) {
    LL c_i, v_i;
    cin >> c_i >> v_i;
    if(v_i > 0) ans += c_i;
  }

  cout << ans << '\n';

  return 0;
}