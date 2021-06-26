#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve() {
  ull X;
  cin >> X;

  int ans = 0;
  while(X > 0) {
    if(!(X % 2)) X /= 2;
    else if(X == 3 || X % 4 == 1) X--;
    else X++;
    ans++;
  }
  cout << ans << '\n';
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while(T--) solve();

  return 0;
}