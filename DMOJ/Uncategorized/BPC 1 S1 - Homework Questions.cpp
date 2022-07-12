#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  map<int, int> freq;
  for(int i = 0; i < N * N; i++) {
    int b_i;
    cin >> b_i;
    freq[b_i]++;
  }

  vector<int> ans;
  for(auto i: freq) {
    if(i.second % 2 == 1) {
      ans.push_back(i.first / 2);
    }
  }

  for(int i = 0; i < ans.size() - 1; i++) {
    cout << ans[i] << ' ';
  }
  cout << ans[ans.size() - 1] << '\n';

  return 0;
}