#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<pair<LL, LL>> Z(N);
  LL T_sum = 0;
  for(int i = 0; i < N; i++) {
    LL T_i;
    cin >> T_i >> Z[i].first;
    Z[i].second = i;
    T_sum += T_i;
  }

  sort(Z.begin(), Z.end());
  int ans_1 = 0;
  vector<LL> ans_2(N);
  for(int i = N - 1; i >= 0; i--) {
    if(!T_sum) ans_1++;
    ans_2[Z[i].second] = min(T_sum, Z[i].first);
    T_sum = max(0LL, T_sum - Z[i].first);
  }
  
  cout << ans_1 << '\n';
  for(int i = 0; i < N - 1; i++) cout << ans_2[i] << ' ';
  cout << ans_2[N - 1] << '\n';

  return 0;
}