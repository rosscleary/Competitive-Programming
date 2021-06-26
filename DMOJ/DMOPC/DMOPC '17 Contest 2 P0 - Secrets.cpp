#include <bits/stdc++.h>
using namespace std;

double x_1, y_1, x_2, y_2, x_s, y_s, D;

double distance(double x_1, double y_1, double x_2, double y_2) {
  return sqrt(pow(y_2 - y_1, 2.0) + pow(x_2 - x_1, 2.0));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_s >> y_s >> D;

  if (distance(x_1, y_1, x_s, y_s) <= D || distance(x_2, y_2, x_s, y_s) <= D) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}