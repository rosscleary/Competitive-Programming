#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  double A, B, C, I, J, K;
  cin >> A >> B >> C >> I >> J >> K;

  double min_multiplier = min(A / I, min(B / J, C / K));
  double A_ans = A - min_multiplier * I, B_ans = B - min_multiplier * J, C_ans = C - min_multiplier * K;
  cout << setprecision(6) << fixed << A_ans << ' ' << B_ans << ' ' << C_ans << '\n';

  return 0;
}