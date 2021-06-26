#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

const int M1 = 4294967296;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  while(N--) {
    int n;
    cin >> n;
    if(n >= 34) {
      cout << "0\n";
      continue;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++) {
      ans *= i;
      ans %= M1;
    }
    
    cout << ans << '\n';
  }

  return 0;
}