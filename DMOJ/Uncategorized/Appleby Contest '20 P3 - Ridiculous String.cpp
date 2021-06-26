#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int s_len, T_len;
  cin >> s_len >> T_len;
  string s, T;
  cin >> s >> T;

  vector<vector<int>> next_i(26, vector<int>(s_len + 1));
  for(int i = 0; i < 26; i++) {
    next_i[i][s_len] = -1;
  }
  for(int i = s_len - 1; i >= 0; i--) {
    for(int j = 0; j < 26; j++) {
      if(s[i] - 'a' == j) {
        next_i[j][i] = i;
      } else {
        next_i[j][i] = next_i[j][i + 1];
      }
    }
  }

  int full_cnt = 0, curr = -1;
  for(auto i: T) {
    if(next_i[i - 'a'][0] == -1) {
      cout << "-1\n";
      return 0;
    }
    if(curr != s_len - 1 && next_i[i - 'a'][curr + 1] != -1) {
      curr = next_i[i - 'a'][curr + 1];
    } else {
      curr = next_i[i - 'a'][0];
      full_cnt++;
    }
  }

  cout << s_len * full_cnt + curr + 1 << '\n';

  return 0;
}