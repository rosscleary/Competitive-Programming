#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> values(N + 1);
  int sum = 0;
  for(int i = 1; i <= N; i++) {
    cin >> values[i];
    sum += values[i];
  }

  int M;
  cin >> M;
  while(M--) {
    int a_i, d_i;
    cin >> a_i >> d_i;
    sum -= d_i;
    int opt_1 = 0, opt_2 = d_i - values[a_i], opt_3 = d_i - values[a_i + 1];
    sum += max(opt_1, max(opt_2, opt_3));
  }

  cout << sum << '\n';

  return 0;
}