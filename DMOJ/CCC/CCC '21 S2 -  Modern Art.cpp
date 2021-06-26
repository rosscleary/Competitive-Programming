#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int M, N, K;
  cin >> M >> N >> K;
  vector<int> row_freq(M + 1), col_freq(N + 1);
  while(K--) {
    char type;
    cin >> type;
    int value;
    cin >> value;
    if(type == 'R') {
      row_freq[value]++;
    } else {
      col_freq[value]++;
    }
  }

  int ans = 0;
  for(int i = 1; i <= M; i++) {
    for(int j = 1; j <= N; j++) {
      ans += ((row_freq[i] + col_freq[j]) & 1);
    }
  }

  cout << ans << '\n';

  return 0;
}