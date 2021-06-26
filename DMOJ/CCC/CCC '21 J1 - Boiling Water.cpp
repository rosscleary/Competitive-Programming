#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int B;
  cin >> B;

  cout << 5 * B - 400 << '\n';
  if(B < 100) {
    cout << 1;
  } else if(B == 100) {
    cout << 0;
  } else {
    cout << -1;
  }
  cout << '\n';

  return 0;
}