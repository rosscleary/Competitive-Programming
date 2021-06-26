#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  for(int div = 2; div * div <= N; div++) {
    if(N % div == 0) {
      cout << N - (N / div) << '\n';
      return 0;
    }
  }
  cout << N - 1 << '\n';
 
  return 0;
}