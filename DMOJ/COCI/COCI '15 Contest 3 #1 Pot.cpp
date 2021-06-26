#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  int answer = 0;
  for(int i = 0; i < N; i++) {
    int P_i;
    cin >> P_i;
    answer += pow(P_i / 10, P_i % 10);
  }
  cout << answer << '\n';

  return 0;
}