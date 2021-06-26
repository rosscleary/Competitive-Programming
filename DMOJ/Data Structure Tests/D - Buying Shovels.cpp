#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n, k;
  cin >> n >> k;
 
  int answer = n;
  for(int div = 1; div <= sqrt(n); div++) {
    if(!(n % div)) {
      if(div <= k) answer = min(answer, n / div);
      if(n / div <= k) answer = min(answer, div);
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