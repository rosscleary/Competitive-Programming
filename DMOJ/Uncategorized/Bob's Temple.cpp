#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e6;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  assert(n >= 1 && n <= M1);
  vector<int> freq(M1 + 1);
  while(n--) {
    int A_i;
    cin >> A_i;
    assert(A_i >= 1 && A_i <= M1);
    freq[A_i]++;
  }
  for(int i = 1; i < M1; i++) {
    if(freq[i] > 0) {
      assert(n == 1 || freq[i + 1] == 0 || freq[i] > 1);
    }
    assert(!(freq[i] == 0 && freq[i + 1] > 0));
  }

  int i;
  for(i = 1; i <= M1 && freq[i] != 0; i++) {
    cout << i << ' ';
    freq[i]--;
  }
  for(i--; i >= 1; i--) {
    for(int j = 0; j < freq[i]; j++) {
      cout << i << ' ';
    }
  }
  cout << '\n';

  return 0;
}