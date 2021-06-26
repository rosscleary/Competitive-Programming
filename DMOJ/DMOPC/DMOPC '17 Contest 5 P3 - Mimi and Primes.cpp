#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll num_1, ll num_2) {
  return num_2 ? gcd(num_2, num_1 % num_2) : num_1;
}

ll ans;
void prime_fac(ll num) {
  for(ll div = 2; div * div <= num; div++) {
    if(!(num % div)) {
      prime_fac(div), prime_fac(num / div);
      return;
    }
  }
  ans = max(ans, num);
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  ll gcd_value = A[0];
  for(int i = 1; i < N; i++) gcd_value = gcd(gcd_value, A[i]);

  prime_fac(gcd_value);
  if(ans != 1) cout << ans << '\n';
  else cout << "DNE\n";

  return 0;
}