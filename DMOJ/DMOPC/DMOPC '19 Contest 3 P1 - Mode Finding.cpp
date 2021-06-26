#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e5;

int main() {
  int N;
  cin >> N;
  vector<int> pos(M1 + 1), neg(M1 + 1);
  int mode = 0;
  while(N--) {
    int a_i;
    cin >> a_i;
    if(a_i <= 0) {
      neg[abs(a_i)]++;
      mode = max(mode, neg[abs(a_i)]);
    } else {
      pos[a_i]++;
      mode = max(mode, pos[a_i]);
    }
  }

  for(int i = M1; i >= 0; i--){
    if(neg[i] == mode) {
      cout<< -i << ' ';
    }
  }
  for(int i = 1; i <= M1; i++){
    if(pos[i] == mode) {
      cout << i << ' ';
    }
  }
  cout << '\n';

  return 0;
}