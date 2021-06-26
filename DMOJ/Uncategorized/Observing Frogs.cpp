#include <bits/stdc++.h>
using namespace std;

long long N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  scanf("%lld", &N);

  cout << ((((N - 1) / 2) + 1) * (N / 2)) * 2 << "\n";

  return 0;
}