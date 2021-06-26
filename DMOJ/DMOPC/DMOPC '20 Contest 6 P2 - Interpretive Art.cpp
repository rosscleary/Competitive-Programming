#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> A_ones, B_ones;
  for(int i = 1; i <= N; i++) {
    int A_i;
    cin >> A_i;
    if(A_i) {
      A_ones.push_back(i);
    }
  }
  for(int i = 1; i <= N; i++) {
    int B_i;
    cin >> B_i;
    if(B_i) {
      B_ones.push_back(i);
    }
  }

  if(A_ones.size() != B_ones.size()) {
    cout << "-1\n";
    return 0;
  }
  for(int i = 0; i < A_ones.size(); i++) {
    if(A_ones[i] > B_ones[i]) {
      cout << "-1\n";
      return 0;
    }
  }
  if(!A_ones.size()) {
    cout << "0\n";
    return 0;
  }

  vector<pair<int, int>> ans;
  int last = A_ones.size() - 1;
  for(int i = A_ones.size() - 2; i >= 0; i--) {
    if(B_ones[i + 1] - B_ones[i] != 1) {
      if(B_ones[i + 1] != A_ones[i + 1]) {
        ans.push_back({A_ones[i + 1], B_ones[last]});
      }
      last = i;
    }
  }
  if(B_ones[0] != A_ones[0]) {
    ans.push_back({A_ones[0], B_ones[last]});
  }

  cout << ans.size() << '\n';
  for(auto i: ans) {
    cout << i.first << ' ' << i.second << '\n';
  }

  return 0;
}