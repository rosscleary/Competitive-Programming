#include <bits/stdc++.h>
using namespace std;

#define undefined 1000000

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << setprecision(9) << fixed;

  double x_1, y_1, x_2, y_2;
  cin >> x_1 >> y_1 >> x_2 >> y_2;
  double x_3, y_3, x_4, y_4;
  cin >> x_3 >>y_3 >> x_4 >> y_4;

  double slope_1, slope_2, b_1, b_2;

  if (x_1 != x_2 && y_1 != y_2) {
    slope_1 = (y_2 - y_1) / (x_2 - x_1);
    b_1 = y_1 - (slope_1 * x_1);
  } else if (x_1 == x_2) {
    slope_1 = undefined;
    b_1 = undefined;
  } else {
    slope_1 = 0;
    b_1 = y_1;
  }
  

  if (x_3 != x_4 && y_3 != y_4) {
    slope_2 = (y_4 - y_3) / (x_4 - x_3);
    b_2 = y_3 - (slope_2 * x_3);
  } else if (x_3 == x_4) {
    slope_2 = undefined;
    b_2 = undefined;
  } else {
    slope_2 = 0;
    b_2 = y_3;
  }

  //cout << slope_1 << " " << slope_2 << " " << b_1 << " " << b_2 << endl;

  // Special Cases
  if (slope_1 == undefined && slope_2 == undefined) {
    if (x_1 == x_3) {
      cout << "coincident\n";
    }
    else {
      cout << "parallel\n";
    }
    return 0;
  }

  if (slope_1 == 0 && slope_2 == 0) {
    if (y_1 == y_3) {
      cout << "coincident\n";
    }
    else {
      cout << "parallel\n";
    }
    return 0;
  }

  if (slope_1 == undefined && slope_2 != undefined) {
    double y_value = (slope_2 * x_1) + b_2;
    cout << x_1 << " " << y_value << "\n";
    return 0;
  }

  if (slope_1 != undefined && slope_2 == undefined) {
    double y_value = (slope_1 * x_3) + b_1;
    cout << x_3 << " " << y_value << "\n";
    return 0;
  }

  // Regular Cases
  if (abs(slope_1 - slope_2) < 0.0001 && abs(b_1 - b_2) < 0.0001) {
    cout << "coincident\n";
    return 0;
  }

  if (abs(slope_1 - slope_2) < 0.0001) {
    cout << "parallel\n";
    return 0;
  }

  double x_value, y_value;
  x_value = (b_2 - b_1) / (slope_1 - slope_2);
  y_value = (slope_1 * x_value) + b_1;
  cout << x_value << " " << y_value << "\n";

  return 0;
}