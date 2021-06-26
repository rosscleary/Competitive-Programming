#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<int> odd, even;
  for(int i = 0; i < n; i++) {
    int a_i;
    cin >> a_i;
    if(a_i % 2) odd.push_back(a_i);
    else even.push_back(a_i);
  }
 
  if(!(odd.size() % 2)) {
    cout << "YES\n";
    return;
  }
  for(int i = 0; i < odd.size(); i++) {
    for(int j = 0; j < even.size(); j++) {
      if(abs(odd[i] - even[j]) == 1) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}