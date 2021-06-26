#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> values(n);
  for(int i = 0; i < n; i++) {
    cin >> values[i];
  }

  sort(values.begin(), values.end());

  for(int i = 0; i < n; i++) {
    cout << values[i] << '\n';
  }

  return 0;
}