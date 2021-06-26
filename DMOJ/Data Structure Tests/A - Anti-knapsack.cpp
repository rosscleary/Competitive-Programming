#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n, k;
  cin >> n >> k;
 
  vector<int> ans;
  for(int i = k + 1; i <= n; i++) {
    ans.push_back(i);
  }
  for(int i = k - 1; 2 * i >= k; i--) {
    ans.push_back(i);
  }
  
  cout << ans.size() << '\n';
  for(auto i: ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int T;
  cin >> T;
  while(T--) {
    solve_tc();
  }
 
  return 0;
}