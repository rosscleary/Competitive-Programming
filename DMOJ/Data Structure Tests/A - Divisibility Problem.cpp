#include <bits/stdc++.h>
using namespace std;
 
int t;
int a, b;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << (b - (a % b)) % b << "\n";
  }
 
  return 0;
}