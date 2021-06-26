#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
 
  bool greater = true;
  int length_ans = 1;
  for(int i = n - 2; i >= 0; i--) {
    if(!greater && a[i] > a[i + 1]) {
      break;
    }
    if(greater && a[i] < a[i + 1]) {
      greater = false;
    }
    length_ans++;
  }
 
  cout << n - length_ans << '\n';
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