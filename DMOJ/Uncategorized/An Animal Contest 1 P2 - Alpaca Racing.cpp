#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, D, K, X;
  cin >> N >> D >> K >> X;
  vector<int> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int P;
  cin >> P;

  for(int i = 0; i < N; i++) {
    while(a[i] >= P && K > 0) {
      a[i] = a[i] * (100 - X) / 100, K--;
    }
    if(a[i] >= P) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";

  return 0;
}