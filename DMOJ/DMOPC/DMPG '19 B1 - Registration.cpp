#include <bits/stdc++.h>
using namespace std;

int N;
int sum = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    int C_i; cin >> C_i;
    sum += C_i;
  }

  if(sum > 200) cout << "Over maximum capacity!\n";
  else cout << 200 - sum << "\n";

  return 0;
}