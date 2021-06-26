#include <bits/stdc++.h>
using namespace std;
 
int T;
int n;
bool valid = true;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> T;
 
  while(T--) {
    cin >> n;
    
    int last_p, last_c, p, c;
    cin >> last_p >> last_c;
 
    if(last_c > last_p) {
      valid = false;
    }
 
    for(int i = 1; i < n; i++) {
      cin >> p >> c;
      if(p < last_p || c < last_c) valid = false;
      if(c - last_c > p - last_p) valid = false;
      last_p = p;
      last_c = c;
    }
 
    if(valid) cout << "YES\n";
    else cout << "NO\n";
 
    valid = true;
  }
 
  return 0;
}