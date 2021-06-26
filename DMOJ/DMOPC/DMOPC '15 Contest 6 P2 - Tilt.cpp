#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  ld sum = 0.0;
  for(int i = 0; i < N; i++) {
    ld T_i;
    cin >> T_i;
    sum += T_i;
  }
  
  cout << setprecision(6) << fixed << sum - (360.0 * floor(sum / 360.0)) << '\n';
 
  return 0;
}