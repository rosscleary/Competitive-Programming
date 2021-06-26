#include <bits/stdc++.h>
using namespace std;

int a, b, c, C;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> a >> b >> c >> C;

  for(int t_a = 0; t_a <= 100; t_a++) {
    for(int t_b = 0; t_b <= 100; t_b++) {
      for(int t_c = 0; t_c <= 100; t_c++) {
        if(a * t_a + b * t_b + c * t_c == C) {
          cout << "QUEST CLEARED\n";
          return 0;
        }
      }
    }
  }
  cout << "TRY AGAIN\n";

  return 0;
}