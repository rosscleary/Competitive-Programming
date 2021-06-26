#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  int xor_value;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if(!i) xor_value = x;
    else xor_value ^= x;
  }
  cout << xor_value << '\n';

  return 0;
}