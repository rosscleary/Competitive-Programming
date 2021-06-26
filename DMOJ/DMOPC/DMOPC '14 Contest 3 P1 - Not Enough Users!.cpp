#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
  int N, K, D;
  cin >> N >> K >> D;

  int num_users = N;
  for(int day = 1; day <= D; day++) {
    num_users *= K;
  }

  cout << num_users << '\n';
 
  return 0;
}