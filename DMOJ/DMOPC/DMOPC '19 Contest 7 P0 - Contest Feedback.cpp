#include <bits/stdc++.h>
using namespace std;

long double ratings[4];

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  for(int i = 0; i < 4; i++) cin >> ratings[i];

  cout << setprecision(9) << fixed;

  for(int i = 0; i < 3; i++) {
    for(int j = i + 1; j < 4; j++) {
      cout << (ratings[i] + ratings[j]) / 2.0 << '\n';
    }
  }
  for(int i = 0; i < 2; i++) {
    for(int j = i + 1; j < 3; j++) {
      for(int k = j + 1; k < 4; k++) {
        cout << (ratings[i] + ratings[j] + ratings[k]) / 3.0 << '\n';
      }
    }
  }

  cout << (ratings[0] + ratings[1] + ratings[2] + ratings[3]) / 4.0 << '\n';

  return 0;
}