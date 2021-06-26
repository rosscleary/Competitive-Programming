#include <bits/stdc++.h>
using namespace std;

const int M1 = 50;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> freq(M1 + 1);
  while(n--) {
    int A_i;
    cin >> A_i;
    freq[A_i]++;
  }

  int max_value = -1, ans;
  for(int i = 0; i <= M1; i++) {
    if(i * freq[i] > max_value) {
      max_value = i * freq[i], ans = i;
    }
  }

  cout << ans << '\n';

  return 0;
}