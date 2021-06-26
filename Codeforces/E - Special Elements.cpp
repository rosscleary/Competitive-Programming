#include <bits/stdc++.h>
using namespace std;
 
const int M1 = 8e3 + 5;
 
void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
 
  int answer = 0; vector<bool> is_special(M1);
  for(int i = 0; i < n; i++) {
    if(is_special[a[i]]) {
      answer++;
      continue;
    }
    int left = 0, right = -1, sum = 0;
    while(right < n - 1) {
      if(sum + a[right + 1] <= a[i]) right++, sum += a[right];
      else sum -= a[left], left++;
      if(sum == a[i] && right - left > 0) {
        is_special[a[i]] = true;
        answer++;
        break;
      }
    }
  }
 
  cout << answer << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}