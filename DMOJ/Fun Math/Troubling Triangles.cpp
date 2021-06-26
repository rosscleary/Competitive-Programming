#include <bits/stdc++.h>
using namespace std;

#define double long double

double dist(pair<double, double> point_1, pair<double, double> point_2) {
  return sqrt(powl(point_1.first - point_2.first, 2.0) + powl(point_1.second - point_2.second, 2.0));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  while(N--) {
    pair<double, double> X, Y, Z;
    cin >> X.first >> X.second >> Y.first >> Y.second >> Z.first >> Z.second;

    double X_len = dist(X, Y), Y_len = dist(X, Z), Z_len = dist(Y, Z);
    double p = (X_len + Y_len + Z_len) / 2.0;
    double a = sqrt((p) * (p - X_len) * (p - Y_len) * (p - Z_len));

    p *= 2.0;
    cout << setprecision(2) << fixed << a << ' ' << p << '\n';
  }

  return 0;
}