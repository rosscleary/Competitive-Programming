#include <bits/stdc++.h>
using namespace std;

#define int long long

const string f_0 = "Good writing is good writing is good writing.";
const string seg_1 = "Good writing is good ", seg_2 = " writing is good ", seg_3 = " is good writing.";
vector<int> lengths;

char solve(int i, int j) {
  if(i == 0) {
    if(j > f_0.length()) {
      return '.';
    }
    return f_0[j - 1];
  }

  vector<int> pref_lengths(5);
  pref_lengths[0] = seg_1.length();
  pref_lengths[1] = pref_lengths[0] + lengths[i - 1];
  pref_lengths[2] = pref_lengths[1] + seg_2.length();
  pref_lengths[3] = pref_lengths[2] + lengths[i - 1];
  pref_lengths[4] = pref_lengths[3] + seg_3.length();

  for(int k = 0; k < 5; k++) {
    if(j <= pref_lengths[k]) {
      if(k == 0) {
        return seg_1[j - 1];
      } else if(k == 1) {
        return solve(i - 1, j - pref_lengths[0]);
      } else if(k == 2) {
        return seg_2[j - pref_lengths[1] - 1];
      } else if(k == 3) {
        return solve(i - 1, j - pref_lengths[2]);
      } else {
        return seg_3[j - pref_lengths[3] - 1];
      }
    }
  }

  return '.';
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int q;
  cin >> q;
  while(q--) {
    int n, k;
    cin >> n >> k;
    lengths.resize(n + 1);
    lengths[0] = f_0.length();
    for(int i = 1; i <= n; i++) {
      lengths[i] = 2 * lengths[i - 1] + seg_1.length() + seg_2.length() + seg_3.length();
    }
    cout << solve(n, k) << '\n';
  }

  return 0;
}