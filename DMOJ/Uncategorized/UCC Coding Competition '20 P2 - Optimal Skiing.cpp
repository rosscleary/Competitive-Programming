#include <bits/stdc++.h>
using namespace std;

const int M1 = 2.02e5 + 5;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  int answer = M1;
  for(int i = 0; i < N; i++) {
    int M_i;
    cin >> M_i;
    int option_time = 0;
    for(int j = 0; j < M_i; j++) {
      int lift_time;
      cin >> lift_time;
      option_time += lift_time;
      //if(option_time >= answer) break;
    }
    answer = min(answer, option_time);
  }
  cout << answer << '\n';

  return 0;
}