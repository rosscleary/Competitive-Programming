#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string arang;
  cin >> arang;
  
  int L_cnt = 0, S_cnt = 0;
  for(auto i: arang) {
    L_cnt += i == 'L', S_cnt += i == 'S';
  }

  int ans = 0, S_in_L_cnt = 0;
  for(int i = 0; i < L_cnt; i++) {
    ans += arang[i] != 'L', S_in_L_cnt += arang[i] == 'S';
  }
  int L_used_cnt = 0;
  for(int i = arang.size() - 1, cnt = 0; cnt < S_cnt; i--, cnt++) {
    ans += arang[i] == 'M', ans += arang[i] == 'L' && L_used_cnt >= S_in_L_cnt;
    L_used_cnt += arang[i] == 'L';
  }

  cout << ans << '\n';

  return 0;
}