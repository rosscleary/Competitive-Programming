#include <bits/stdc++.h>
using namespace std;
 
int t;
int x, n, m;
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    cin >> x >> n >> m;
 
    int n_left = n, m_left = m;
    for(int i = 0; i < n + m; i++) {
      if(x > 20 && n_left > 0) {
        x /= 2;
        x += 10;
        n_left--;
      } else if(m_left > 0) {
        x -= 10;
        m_left--;
      }
    }
 
    if(x <= 0) cout <<"YES\n";
    else cout << "NO\n";
  }
 
  return 0;
}