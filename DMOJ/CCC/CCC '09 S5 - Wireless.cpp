#include <bits/stdc++.h>
using namespace std;  

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int M, N, K;
  cin >> M >> N >> K;

  vector<vector<int>> diff_arr(N + 1, vector<int>(M + 1));
  while(K--) {
    int x, y, r, b;
    cin >> x >> y >> r >> b;
    for(int i = max(1, x - r); i <= min(N, x + r); i++) {
      int max_dist = sqrt(r * r - (i - x) * (i - x));
      int l = max(1, y - max_dist), r = y + max_dist + 1;
      diff_arr[i][l] += b;
      if(r <= M) {
        diff_arr[i][r] -= b;
      }
    }
  }

  int ans_1 = -1, ans_2;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      diff_arr[i][j] += diff_arr[i][j - 1];
      ans_2 += diff_arr[i][j] == ans_1;
      if(diff_arr[i][j] > ans_1) {
        ans_1 = diff_arr[i][j];
        ans_2 = 1;
      }
    }
  }

  cout << ans_1 << '\n' << ans_2 << '\n';

  return 0;
}