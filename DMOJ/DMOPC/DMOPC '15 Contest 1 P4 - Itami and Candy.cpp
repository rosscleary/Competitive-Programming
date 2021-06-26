#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, X;
  cin >> N >> X;

  vector<bool> is_prime(N + 1, true);
  for(int value = 2; value * value <= N; value++) {
    if(is_prime[value]) {
      for(int update = value * value; update <= N; update += value) {
        is_prime[update] = false;
      }
    }
  }
  vector<int> primes;
  for(int value = 2; value <= N; value++) {
    if(is_prime[value]) {
      primes.push_back(value);
    }
  }

  int ans = 0;
  for(auto i: primes) {
    ans += (N - i) / X + 1;
    if(N - i - 1 >= 0) {
      ans += (N - i - 1) / X + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}