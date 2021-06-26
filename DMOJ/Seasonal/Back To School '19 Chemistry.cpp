#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  ll N, M;
  cin >> N >> M;

  ll two_pow = 1, num_bits = 0;
  while(two_pow < N) two_pow *= 2, num_bits++;

  cout << ceil(1.0 * num_bits / M) << '\n';

  return 0;
}