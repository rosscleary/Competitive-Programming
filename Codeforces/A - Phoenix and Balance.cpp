#include <bits/stdc++.h>
using namespace std;
 
int t;
int n;
 
int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
  cin >> t;
 
  while(t--) {
    cin >> n;
 
    int large_group = pow(2, n) + pow(2, n / 2) - 2, small_group = (pow(2, n + 1) - 2) - large_group;
    cout << large_group - small_group << '\n';
  }
 
  return 0;
}