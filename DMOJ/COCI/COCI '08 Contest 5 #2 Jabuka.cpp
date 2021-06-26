#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { 
  return (b != 0) ? gcd(b, a % b) : a;
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int R, G;
  cin >> R >> G;

  int gcd_value = gcd(R, G);
  for(int div = 1; div * div <= gcd_value; div++) {
    if(gcd_value % div == 0) {
      cout << div << ' ' << R / div << ' ' << G / div << '\n';
      int pair_div = gcd_value / div;
      if(pair_div != div) cout << pair_div << ' ' << R / pair_div << ' ' << G / pair_div << '\n';
    }
  }
 
  return 0;
}