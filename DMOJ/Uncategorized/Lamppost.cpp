#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, C;
  cin >> N >> C;
  vector<int> lamp_cnt(N + 1);
  while(C--) {
    int C_1, C_2;
    cin >> C_1 >> C_2;
    lamp_cnt[C_1]++;
    lamp_cnt[C_2]++;
  }

  int ans_max = -1, ans_i = 0;
  for(int i = 1; i <= N; i++) {
    if(lamp_cnt[i] >= ans_max) {
      ans_max = lamp_cnt[i];
      ans_i = i;
    }
  }

  cout << ans_i << '\n';

  return 0;
}