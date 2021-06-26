#include <bits/stdc++.h>
using namespace std;

#define double long double

const double M1 = 1e-12;

vector<double> diff_coef(6);

double pow_double(double base, double exp) {
  double ans = 1;
  for(int i = 0; i < exp; i++) {
    ans *= base;
  }
  return ans;
}

double fun_value(double x) {
  double ans = 0;
  for(int i = 5; i >= 0; i--) {
    ans += diff_coef[i] * pow_double(x, i);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N;
  vector<double> coef_1(6), coef_2(6);
  for(int i = N; i >= 0; i--) {
    cin >> coef_1[i];
  }
  cin >> M;
  for(int i = M; i >= 0; i--) {
    cin >> coef_2[i];
  }
  for(int i = 5; i >= 0; i--) {
    diff_coef[i] = coef_2[i] - coef_1[i];
  }
  double a, b;
  cin >> a >> b;

  double low = a, high = b;
  cout << setprecision(12) << fixed;
  while(high - low > M1) {
    double mid = (high + low) / 2.0;
    if(fun_value(low) == 0) {
      cout << low << '\n';
      return 0;
    }
    if((fun_value(low) < 0) != (fun_value(mid) < 0)) {
      high = mid;
    } else {
      low = mid;
    }
  }

  cout << setprecision(12) << fixed << (low + high) / 2.0 << '\n';

  return 0;
}