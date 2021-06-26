#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, M;
  cin >> n >> M;
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());
  int j = 0;
  long long ans = 0;
  for(int i = n - 1; i >= 0; i--) {
    j = min(j, i - 1);
    for(; j < i && A[i] + A[j] <= M; j++) {

    }
    ans += j;
  }

  cout << ans % int(1e9 + 7) << '\n';

  return 0;
}