#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
 
  bool alice = true;
  int left = 0, right = n - 1, last_size = 0, curr_size = 0;
  int total_turns = 1, a_amount = 0, b_amount = 0;
  for(int rep = 0; rep < n; rep++) {
    if(alice) {
      curr_size += a[left];
      a_amount += a[left];
      left++;
      if(curr_size > last_size) {
        total_turns += (rep != n - 1);
        last_size = curr_size;
        curr_size = 0;
        alice = false;
      }
    } else {
      curr_size += a[right];
      b_amount += a[right];
      right--;
      if(curr_size > last_size) {
        total_turns += (rep != n - 1);
        last_size = curr_size;
        curr_size = 0;
        alice = true;
      }
    }
  }
 
  cout << total_turns << ' ' << a_amount << ' ' << b_amount << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}