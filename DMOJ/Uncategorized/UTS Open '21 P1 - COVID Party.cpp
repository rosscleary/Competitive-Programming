#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e9;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  int S;
  for(S = 1; ; S++) {
    int top = (S + 2) / 2, next = (S + 1) / 2;
    if(top * top + next * next >= N) {
      cout << S << '\n';
      return 0;
    }
  }

  return 0;
}