#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  double max_value = -1;
  string max_string;
  for(int i = 0; i < N; i++) {
    string S_i;
    double R_i;
    cin >> S_i >> R_i;
    if(R_i > max_value) max_value = R_i, max_string = S_i;
  }
  
  cout << max_string << '\n';
 
  return 0;
}