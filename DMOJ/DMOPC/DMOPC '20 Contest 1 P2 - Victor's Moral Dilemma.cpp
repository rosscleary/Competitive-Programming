#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, D;
  cin >> N >> D;
  vector<int> prefix_a(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> prefix_a[i];
    prefix_a[i] += prefix_a[i - 1];
  }

  int l = 1, r = N;
  while(D--) {
    int n_i;
    cin >> n_i;
    int F = prefix_a[l + n_i - 1] - prefix_a[l - 1];
    int S = prefix_a[r] - prefix_a[l + n_i - 1];
    if(F >= S) {
      cout << F << '\n';
      l += n_i;
    } else {
      cout << S << '\n';
      r = l + n_i - 1;
    }
  }

  return 0;
}