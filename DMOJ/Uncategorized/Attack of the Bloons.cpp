#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve_tc() {
  int L, N;
  cin >> L >> N;

  vector<int> damage_values(L + 1);
  while(N--) {
    int C_i, R_i, D_i;
    cin >> C_i >> R_i >> D_i;
    damage_values[C_i] += D_i;
    for(int i = 1; i <= R_i; i++) {
      if(C_i - i > 0) {
        damage_values[C_i - i] += D_i;
      }
      if(C_i + i <= L) {
        damage_values[C_i + i] += D_i;
      }
    }
  }

  int M;
  cin >> M;
  while(M--) {
    int H_i;
    cin >> H_i;
    int i = 1;
    for(; H_i > 0 && i <= L; i++) {
      H_i -= damage_values[i];
    }
    if(i > L && H_i > 0) {
      cout << "Bloon leakage\n";
    } else {
      cout << i - 1 << '\n';
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    solve_tc();
  }

  return 0;
}