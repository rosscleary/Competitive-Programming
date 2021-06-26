#include <bits/stdc++.h>
using namespace std;
 
const int M1 = 1e3 + 5;
 
void solve() {
  int n;
  cin >> n;
  vector<int> s(n);
  for(int i = 0; i < n; i++) cin >> s[i];
 
  int answer = M1;
  sort(s.begin(), s.end());
  for(int i = 1; i < n; i++) answer = min(answer, s[i] - s[i - 1]);
  cout << answer << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}