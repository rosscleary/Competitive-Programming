#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n;
  cin >> n;
  vector<int> ans;
  set<int> a_i_occ;
  for(int i = 0; i < 2 * n; i++) {
    int a_i;
    cin >> a_i;
    if(a_i_occ.count(a_i)) {
      ans.push_back(a_i);
    }
    a_i_occ.insert(a_i);
  }
 
  for(int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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