#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> a >> b >> c >> d;

  int num_carbons = a + b + c + 1;

  if(num_carbons == 1) {
    if(d == 4) cout << "C" << num_carbons << "H" << d << '\n';
    else cout << "invalid\n";
    return 0;
  }
  
  if(((num_carbons - 2) * 2) + 6 == d) cout << "C" << num_carbons << "H" << d << '\n';
  else cout << "invalid\n";

  return 0;
}