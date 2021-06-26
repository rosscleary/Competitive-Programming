#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int n;
  cin >> n;
 
  set<int> remain;
  for(int i = 1; i <= n; i++) {
    remain.insert(i);
  }
  vector<int> ans(n);
  for(int i = 0; i < n; i++) {
    int a_i;
    cin >> a_i;
    if(remain.count(a_i)) {
      ans[i] = a_i, remain.erase(remain.find(a_i));
    }
  }
  for(int i = 0; i < n; i++) {
    if(!ans[i]) {
      ans[i] = *remain.begin(), remain.erase(remain.begin());
    }
  }
 
  for(auto i: ans) {
    cout << i << ' ';
  }
  cout << '\n';
 
  return 0;
}