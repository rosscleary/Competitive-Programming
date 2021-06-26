#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  while(N--) {
    ll A, B, P;
    cin >> A >> B >> P;
    cout << (A * B == P ? "POSSIBLE DOUBLE SIGMA" : "16 BIT S/W ONLY") << '\n';
  }

  return 0;
}