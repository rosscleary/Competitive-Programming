#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string g_string;
  cin >> g_string;
  int len = g_string.length();

  vector<int> prefix_freq(len);
  prefix_freq[0] = (g_string[0] == 'G');
  for(int i = 1; i < len; i++) {
    prefix_freq[i] = prefix_freq[i - 1] + (g_string[i] == 'G');
  }

  int Q;
  cin >> Q;
  while(Q--) {
    int i, j;
    cin >> i >> j;
    cout << prefix_freq[j] - (i ? prefix_freq[i - 1] : 0) << '\n';
  }

  return 0;
}