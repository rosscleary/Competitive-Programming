#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> values;
  map<pair<int, int>, string> names;
  while(N--) {
    string name;
    int amount;
    cin >> name >> amount;
    values.push_back({amount, N}), names[{amount, N}] = name;
  }

  sort(values.begin(), values.end());
  cout << names[values[values.size() - 1]] << '\n';

  return 0;
}