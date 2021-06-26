#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  int ans = 0;
  for(int div = 1; div <= N; div++) {
    if(N % div == 0) {
      ans += div;
    }
  }

  cout << ans << '\n';

  return 0;
}