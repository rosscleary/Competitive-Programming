#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int T;
  cin >> T;

  while(T--) {
    int N, S;
    cin >> N >> S;
    int take = N * (N + 1) / 2 - S;
    if(take - 1 <= N) {
      cout << (take - 1) / 2 ;
    } else {
      cout << (N - (take - N) + 1) / 2;
    }
    cout << '\n';
  }

  return 0;
}