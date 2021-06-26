#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n;
  cin >> n;
  int even_count = 0, even_count_index = 0, good_count = 0;
  for(int i = 0; i < n; i++) {
    int a_i;
    cin >> a_i;
    even_count += a_i % 2 == 0;
    even_count_index += i % 2 == 0;
    good_count += (a_i % 2 == 0) && (i % 2 == 0);
  }
 
  if(even_count != even_count_index) {
    cout << "-1\n";
    return;
  }
 
  cout << even_count - good_count << '\n';
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