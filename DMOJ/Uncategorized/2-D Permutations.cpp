#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<int> ans(N * M + 2);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      int low = i * j, high = N * M - ((N - i + 1) * (M - j + 1) - 1);
      ans[low]++, ans[high + 1]--;
    }
  }

  for(int i = 1; i <= N * M; i++) {
    ans[i] += ans[i - 1];
  }

  int Q;
  cin >> Q;
  while(Q--) {
    int q_i;
    cin >> q_i;
    cout << ans[q_i] << '\n';
  }

  return 0;
}