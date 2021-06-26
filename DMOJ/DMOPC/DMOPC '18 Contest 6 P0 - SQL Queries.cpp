#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int a_1, a_2, a_3;
  cin >> a_1 >> a_2 >> a_3;

  if(a_1 == 0 && !(a_2 == 3 && a_3 == 2)) {
    cout << "YES";
  } else if(a_2 == 0 && !(a_1 == 3 && a_3 == 1)) {
    cout << "YES";
  } else if(a_3 == 0 && !(a_1 == 2 && a_2 == 1)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << '\n';

  return 0;
}