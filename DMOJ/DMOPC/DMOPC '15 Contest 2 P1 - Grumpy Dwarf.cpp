#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;

  int extra_swords = 0, ans = 0;
  while(N) {
    ans += N;
    N += extra_swords;
    extra_swords = N % K;
    N /= K;
  }

  cout << ans << '\n';

  return 0;
}