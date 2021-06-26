#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  int one_cnt = 0, zero_cnt = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    one_cnt += a[i], zero_cnt += !a[i];
  }
 
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int x;
      cin >> x;
      a[x] ^= 1;
      if(a[x]) {
        one_cnt++, zero_cnt--;
      } else {
        one_cnt--, zero_cnt++;
      }
    } else {
      int k;
      cin >> k;
      cout << (k <= one_cnt ? 1 : 0) << '\n';
    }
  }
 
  return 0;
}