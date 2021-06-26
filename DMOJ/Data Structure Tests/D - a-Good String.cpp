#include <bits/stdc++.h>
using namespace std;
 
string alph("abcdefghijklmnopqrstuvwxyz");
 
string s;
vector<vector<int>> lett_freq;
 
int dp_value(int length, int start_i, int c_i) {
  if(length == 1) {
    return !(s[start_i] == alph[c_i]);
  }
 
  length /= 2;
  int opt_1 = length - (lett_freq[c_i][start_i + length - 1] - lett_freq[c_i][start_i - 1]);
  opt_1 += dp_value(length, start_i + length, c_i + 1);
  int opt_2 = length - (lett_freq[c_i][start_i + 2 * length - 1] - lett_freq[c_i][start_i + length - 1]);
  opt_2 += dp_value(length, start_i, c_i + 1);
 
  return min(opt_1, opt_2);
}
 
void solve_tc() {
  int n;
  cin >> n;
  cin >> s;
  s = '*' + s;
 
  lett_freq.resize(26);
  for(int i = 0; i < 26; i++) {
    lett_freq[i].resize(n + 1);
    for(int j = 1; j <= n; j++) {
      lett_freq[i][j] = lett_freq[i][j - 1];
      if(s[j] == alph[i]) {
        lett_freq[i][j]++;
      }
    }
  }
 
  cout << dp_value(n, 1, 0) << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
 
  while(t--) {
    solve_tc();
  }
 
  return 0;
}