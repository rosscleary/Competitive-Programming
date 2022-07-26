#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int Q;
  cin >> Q;
  
  while(Q--) {
    int A, B, C;
    cin >> A >> B >> C;
    cout << A * B + (C % A) << '\n';
  }
  
	return 0;
}