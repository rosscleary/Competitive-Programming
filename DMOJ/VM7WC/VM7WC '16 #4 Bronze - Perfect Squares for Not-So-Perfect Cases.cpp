#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int A, B;
  cin >> A >> B;

  int answer = A <= 0 && B >= 0 ? 1 : 0;
  A = max(A - 1, 0);
  B = max(B, 0);
  answer += floor(sqrt(double(B))) - floor(sqrt(double(A)));
  cout << answer << '\n';

  return 0;
}