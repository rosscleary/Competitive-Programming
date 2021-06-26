#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n;
  cin >> n;
  string s;
  cin >> s;
 
  vector<int> suff_amount(n + 1);
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == '(') {
      suff_amount[i] = 1;
    }
    suff_amount[i] += suff_amount[i + 1];
  }
 
  int seq_value = 0, removed_amount = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '(' && suff_amount[i] <= removed_amount) continue;
    if(s[i] == '(') {
      seq_value++;
    } else {
      seq_value--;
    }
    if(seq_value == -1) {
      removed_amount++;
      seq_value = 0;
    }
  }
 
  cout << removed_amount << '\n';
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