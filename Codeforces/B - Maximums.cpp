#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int n;
int b;
ll a, prefix_max = 0;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> n;
 
  while (n--) {
    cin >> b;
    a = prefix_max + b;
    prefix_max = max(prefix_max, a);
    cout << a;
    if (n != 0) cout << " ";
  }
  cout << "\n";
 
  return 0;
}