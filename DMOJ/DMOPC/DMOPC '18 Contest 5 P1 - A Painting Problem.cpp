#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, K;
  cin >> N >> M >> K;

  int bitwise_strict_or = N ^ M;

  int ans_blue = 0;
  for(int i = 0; i < K; i++) {
    if(bitwise_strict_or & (1 << i)) {
      ans_blue++;
    }
  }

  cout << ans_blue << ' ' << K - ans_blue << '\n';

  return 0;
}