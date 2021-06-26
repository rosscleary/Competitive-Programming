#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll num_1, ll num_2) {
  return (num_2 != 0) ? gcd(num_2, num_1 % num_2) : num_1;
}

ll lcm(ll num_1, ll num_2) {
  return (num_1 * num_2) / gcd(num_1, num_2);
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  ll A, B, X;
  cin >> A >> B >> X;
  
  cout << 1 + ((X - 1) / lcm(A, B)) << '\n';
 
  return 0;
}