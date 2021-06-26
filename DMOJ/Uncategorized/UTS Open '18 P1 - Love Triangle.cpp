#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  LL N, M;
  cin >> N >> M;

  LL ans = max(N + M, max(abs(N - M), N * M));
  cout << ans << '\n';

  return 0;
}