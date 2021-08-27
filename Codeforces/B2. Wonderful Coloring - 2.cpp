#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  unordered_map<int, int> freq;
  unordered_map<int, vector<int>> value_locations;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
    value_locations[a[i]].push_back(i);
  }
 
  int remain = n;
  for(auto i: freq) {
    remain -= max(0, i.second - k);
  }
 
  vector<bool> no_paint(n);
  for(int i = 0; i < n; i++) {
    if(freq[a[i]] > k) {
      no_paint[i] = true;
      freq[a[i]]--;
    }
  }
 
  int still_no_paint = remain % k;
  for(int i = 0; i < n && still_no_paint > 0; i++) {
    if(!no_paint[i]) {
      no_paint[i] = true;
      still_no_paint--;
    }
  }
 
  int painted = 0;
  vector<int> ans(n);
  for(auto i: value_locations) {
    for(auto j: i.second) {
      if(!no_paint[j]) {
        ans[j] = painted % k + 1;
        painted++;
      } else {
        ans[j] = 0;
      }
    }
  }
  
  for(auto i: ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
 
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
  int t;
  cin >> t;
  while(t--) {
    solve_tc();
  }
 
  return 0;
}