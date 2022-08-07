#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  multiset<int> a;
  for(int i = 0; i < N; i++) {
    int a_i;
    cin >> a_i;
    a.insert(a_i);
  }

  vector<int> ans;
  ans.push_back(*a.begin());
  a.erase(a.begin());
  while(!a.empty()) {
    auto next = a.lower_bound(M - ans[ans.size() - 1]);
    if(next == a.end()) {
      cout << "-1\n";
      return 0;
    }
    ans.push_back(*next);
    a.erase(next);
  }

  for(auto i: ans) {
    cout << i << ' ';
  }
  cout << '\n';
  
  return 0;
}