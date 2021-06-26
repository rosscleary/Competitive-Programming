#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++) cin >> p[i];
 
  vector<int> ans;
  ans.push_back(0);
  bool last_inc = p[1] > p[0];
  for(int i = 2; i <= n; i++) {
    if(i == n || p[i] > p[i - 1] != last_inc) {
      ans.push_back(i - 1);
      last_inc = !last_inc;
    }
  }
 
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size() - 1; i++) cout << p[ans[i]] << ' ';
  cout << p[ans[ans.size() - 1]] << '\n';
} 
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve_tc();
 
  return 0;
}