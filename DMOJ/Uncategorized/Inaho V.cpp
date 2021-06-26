#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long

int M;
ULL sum = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M;

  while(M--) {
    LL value;
    cin >> value;
    value *= -1;
    sum += value;
  }

  if(sum == 0) cout << "0\n";
  else cout << "-" << sum << "\n";

  return 0;
}