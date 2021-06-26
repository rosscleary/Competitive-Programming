#include <bits/stdc++.h>
using namespace std;

bool f(int n) {
  vector<bool> is_perfect_square(n + 1);
  for(int i = 0; i * i <= n; i++) {
    is_perfect_square[i * i] = true;
  }

  for(int i = 0; i * i <= n; i++) {
    if(is_perfect_square[n - (i * i)]) return true;
  }
  return false;
}

// int main() {
//   ios_base::sync_with_stdio(false); 
//   cin.tie(NULL); 
//   cout.tie(NULL);



//   return 0;
// }