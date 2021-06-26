#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K, M;
  cin >> N >> K >> M;

  int add_cnt = M / K, cycle_cnt = add_cnt / (2 * N - 2);
  vector<int> ans(N, K * cycle_cnt * 2);
  ans[0] -= cycle_cnt * K, ans[N - 1] -= cycle_cnt * K;
  int i = 0;
  bool turn = false;
  for(int cnt = 0; cnt < add_cnt % (2 * N - 2); cnt++) {
    ans[i] += K;
    if(!turn) {
      if(i < N - 1) {
        i++;
      } else {
        i--, turn = true;
      }
    } else {
      i--;
    }
  }
  ans[i] += M % K;

  for(auto i: ans) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}